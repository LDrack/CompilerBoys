

#include <wchar.h>
#include "Parser.h"
#include "Scanner.h"


namespace MIEC {


void Parser::SynErr(int n) {
	if (errDist >= minErrDist) errors->SynErr(la->line, la->col, n);
	errDist = 0;
}

void Parser::SemErr(const wchar_t* msg) {
	if (errDist >= minErrDist) errors->Error(t->line, t->col, msg);
	errDist = 0;
}

void Parser::Get() {
	for (;;) {
		t = la;
		la = scanner->Scan();
		if (la->kind <= maxT) { ++errDist; break; }

		if (dummyToken != t) {
			dummyToken->kind = t->kind;
			dummyToken->pos = t->pos;
			dummyToken->col = t->col;
			dummyToken->line = t->line;
			dummyToken->next = NULL;
			coco_string_delete(dummyToken->val);
			dummyToken->val = coco_string_create(t->val);
			t = dummyToken;
		}
		la = t;
	}
}

void Parser::Expect(int n) {
	if (la->kind==n) Get(); else { SynErr(n); }
}

void Parser::ExpectWeak(int n, int follow) {
	if (la->kind == n) Get();
	else {
		SynErr(n);
		while (!StartOf(follow)) Get();
	}
}

bool Parser::WeakSeparator(int n, int syFol, int repFol) {
	if (la->kind == n) {Get(); return true;}
	else if (StartOf(repFol)) {return false;}
	else {
		SynErr(n);
		while (!(StartOf(syFol) || StartOf(repFol) || StartOf(0))) {
			Get();
		}
		return StartOf(syFol);
	}
}

void Parser::VarBlock() {
		Expect(3);
		while (la->kind == 1) {
			VarDecl();
		}
		Expect(4);
}

void Parser::VarDecl() {
		wchar_t* name = nullptr;
		const Type* type = nullptr; 
		Ident(name);
		Expect(8);
		Types(type);
		Expect(9);
		if(!tab->Add(fac->CreateVar(type, name))){
		 Err(L"Insert new var failed");
		 } 
}

void Parser::MIEC() {
		Expect(5);
		Expect(1);
		if (la->kind == 3) {
			VarBlock();
		}
		Expect(6);
		Statements();
		Expect(7);
}

void Parser::Statements() {
		Stat();
		while (StartOf(1)) {
			Stat();
		}
}

void Parser::Ident(wchar_t* &name) {
		Expect(1);
		name = coco_string_create(t->val); 
}

void Parser::Types(const Type *&type) {
		Expect(29);
		type = getIntegerType(); 
}

void Parser::Stat() {
		if (la->kind == 1 || la->kind == 15) {
			std::unique_ptr<DACEntry> entry; 
			InstructionLine(entry);
			dac.AddStat(std::move(entry)); 
		} else if (la->kind == 10 || la->kind == 12) {
			Controlblock();
		} else SynErr(31);
}

void Parser::InstructionLine(std::unique_ptr<MIEC::DACEntry> &entry ) {
		if (la->kind == 1) {
			Assignment(entry);
		} else if (la->kind == 15) {
			Print(entry);
		} else SynErr(32);
		Expect(9);
}

void Parser::Controlblock() {
		if (la->kind == 10) {
			WhileLoop();
		} else if (la->kind == 12) {
			ConditionalBlock();
		} else SynErr(33);
}

void Parser::WhileLoop() {
		std::unique_ptr<MIEC::DACEntry> cond; 
		Expect(10);
		Condition(cond);
		Expect(11);
		auto endLabel = MIEC::DACFactory::createEntry(OpKind::eNop,
		 nullptr, nullptr, L"While: END");
		
		                                      auto startLoopLabel = MIEC::DACFactory::createEntry(OpKind::eIfFalseJump,
		                                        MIEC::DACFactory::createDACOperand(std::move(cond)),
		                                        MIEC::DACFactory::createRefOperand(endLabel.get()),
		                                        L"While: Jump to END");
		
		                                      auto endLoopLabel = MIEC::DACFactory::createEntry(OpKind::eJump,
		                                        MIEC::DACFactory::createRefOperand(startLoopLabel.get()),
		                                        nullptr,
		                                        L"While: Jump to start");
		                                      dac.AddStat(std::move(startLoopLabel));
		                                  
		if (StartOf(1)) {
			Statements();
		}
		Expect(7);
		dac.AddStat(std::move(endLoopLabel));
		dac.AddStat(std::move(endLabel));
		
}

void Parser::ConditionalBlock() {
		std::unique_ptr<MIEC::DACEntry> cond; 
		Expect(12);
		Condition(cond);
		Expect(13);
		auto endLabel = MIEC::DACFactory::createEntry(OpKind::eNop,
		nullptr, nullptr, L"If: END");
		
		                                    auto elseLabel = MIEC::DACFactory::createEntry(OpKind::eNop,
		                                    nullptr, nullptr, L"If: else");
		
		                                    auto afterIfLabel = MIEC::DACFactory::createEntry(OpKind::eJump,
		                                    MIEC::DACFactory::createRefOperand(endLabel.get()),
		                                    nullptr,
		                                    L"If: Jump over else to END");
		
		                                    auto startIfLabel = MIEC::DACFactory::createEntry(OpKind::eIfFalseJump,
		                                    MIEC::DACFactory::createDACOperand(std::move(cond)),
		                                    MIEC::DACFactory::createRefOperand(elseLabel.get()),
		                                    L"If: Jump to else");
		                                    dac.AddStat(std::move(startIfLabel));
		                                
		if (StartOf(1)) {
			Statements();
		}
		dac.AddStat(std::move(afterIfLabel));
		dac.AddStat(std::move(elseLabel));
		
		if (la->kind == 14) {
			Get();
			if (StartOf(1)) {
				Statements();
			}
		}
		Expect(7);
		dac.AddStat(std::move(endLabel));  
}

void Parser::Condition(std::unique_ptr<MIEC::DACEntry> &entry ) {
		OpKind opkind = OpKind::eNop;
		std::unique_ptr<MIEC::DACEntry> arg1, arg2; 
		Expr(arg1);
		while (StartOf(2)) {
			Relop(opkind);
			Expr(arg2);
			arg1 = MIEC::DACFactory::createEntry(opkind,
			MIEC::DACFactory::createDACOperand(std::move(arg1)),
			MIEC::DACFactory::createDACOperand(std::move(arg2)));
			
		}
		entry = std::move(arg1); 
}

void Parser::Expr(std::unique_ptr<MIEC::DACEntry>& entry ) {
		OpKind opkind = OpKind::eNop;
		std::unique_ptr<MIEC::DACEntry> arg1, arg2; 
		Term(arg1);
		while (la->kind == 27 || la->kind == 28) {
			AddOp(opkind);
			Term(arg2);
			arg1 = MIEC::DACFactory::createEntry(opkind,
			MIEC::DACFactory::createDACOperand(std::move(arg1)),
			MIEC::DACFactory::createDACOperand(std::move(arg2)));
			
		}
		entry = std::move(arg1); 
}

void Parser::Relop(OpKind &op ) {
		switch (la->kind) {
		case 19: {
			Get();
			op = OpKind::eIsEqual; 
			break;
		}
		case 20: {
			Get();
			op = OpKind::eIsLessEqual; 
			break;
		}
		case 21: {
			Get();
			op = OpKind::eIsGreaterEqual; 
			break;
		}
		case 22: {
			Get();
			op = OpKind::eIsNotEqual; 
			break;
		}
		case 23: {
			Get();
			op = OpKind::eIsLess; 
			break;
		}
		case 24: {
			Get();
			op = OpKind::eIsGreater; 
			break;
		}
		default: SynErr(34); break;
		}
}

void Parser::Assignment(std::unique_ptr<MIEC::DACEntry> &entry ) {
		wchar_t* name = nullptr;
		Type* type = nullptr;
		Symbol* sym = nullptr;
		std::unique_ptr<MIEC::DACEntry> expr; 
		Ident(name);
		sym = tab->Find(name);
		if (sym == nullptr) Err(L"Variable not defined");  
		Expect(18);
		Expr(expr);
		entry = MIEC::DACFactory::createEntry(OpKind::eAssign,
		MIEC::DACFactory::createSymOperand(sym),
		MIEC::DACFactory::createDACOperand(std::move(expr)));
		
}

void Parser::Print(std::unique_ptr<MIEC::DACEntry> &entry ) {
		std::unique_ptr<MIEC::DACEntry> expr; 
		Expect(15);
		Expect(16);
		Expr(expr);
		Expect(17);
		entry = MIEC::DACFactory::createEntry(OpKind::ePrint,
		MIEC::DACFactory::createDACOperand(std::move(expr)),
		nullptr); 
}

void Parser::Term(std::unique_ptr<MIEC::DACEntry> &entry ) {
		OpKind opkind = OpKind::eNop;
		std::unique_ptr<MIEC::DACEntry> arg1, arg2; 
		Fact(arg1);
		while (la->kind == 25 || la->kind == 26) {
			MulOp(opkind);
			Fact(arg2);
			arg1 = MIEC::DACFactory::createEntry(opkind,
			MIEC::DACFactory::createDACOperand(std::move(arg1)),
			MIEC::DACFactory::createDACOperand(std::move(arg2)));
			
		}
		entry = std::move(arg1); 
}

void Parser::AddOp(OpKind &op) {
		if (la->kind == 27) {
			Get();
			op = OpKind::eAdd; 
		} else if (la->kind == 28) {
			Get();
			op = OpKind::eSubtract; 
		} else SynErr(35);
}

void Parser::Fact(std::unique_ptr<MIEC::DACEntry> &entry ) {
		if (la->kind == 1) {
			wchar_t* name = nullptr;
			Symbol* sym = nullptr; 
			Ident(name);
			sym = tab->Find(name);
			if(sym == nullptr) Err(L"Variable not defined");
			entry = MIEC::DACFactory::createEntry(MIEC::OpKind::eNop,
			                std::move(MIEC::DACFactory::createSymOperand(sym)),
			                nullptr,
			                L"Ident");
			
		} else if (la->kind == 2) {
			Symbol* sym = nullptr; 
			Number(sym);
			entry = MIEC::DACFactory::createEntry(MIEC::OpKind::eNop,
			                 std::move(MIEC::DACFactory::createSymOperand(sym)),
			                 nullptr,
			                 L"ConstInt");
			
		} else if (la->kind == 16) {
			Get();
			Expr(entry);
			Expect(17);
		} else SynErr(36);
}

void Parser::MulOp(OpKind &op) {
		if (la->kind == 25) {
			Get();
			op = OpKind::eMultiply; 
		} else if (la->kind == 26) {
			Get();
			op = OpKind::eDivide; 
		} else SynErr(37);
}

void Parser::Number(Symbol* &numSym) {
		Expect(2);
		int value = 0;
		int ret = swscanf(t->val, L"%d", &value);
		if (ret < 1) Err(L"parsing number failed");
		
		                                      std::wstring name = L"[ConstInt]";
				                                  name.append(coco_string_create(t->val));
		
		                                      numSym = tab->Find(name);
		                                      if (!numSym) {
		                                        auto constIntSym = fac->CreateConstInt(getIntegerType(), name, value);
		                                        numSym = tab->Add(std::move(constIntSym));
		                                        if (!numSym) {
		                                          Err(L"Insert new ConstInt failed");
		                                        }
		                                      }
		                                   
}



void Parser::Parse() {
	t = NULL;
	la = dummyToken = new Token();
	la->val = coco_string_create(L"Dummy Token");
	Get();
	MIEC();

	Expect(0);
}

Parser::Parser(Scanner *scanner) {
	maxT = 30;

	dummyToken = NULL;
	t = la = NULL;
	minErrDist = 2;
	errDist = minErrDist;
	this->scanner = scanner;
	errors = new Errors();
}

bool Parser::StartOf(int s) {
	const bool T = true;
	const bool x = false;

	static bool set[3][32] = {
		{T,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x},
		{x,T,x,x, x,x,x,x, x,x,T,x, T,x,x,T, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x},
		{x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,T, T,T,T,T, T,x,x,x, x,x,x,x}
	};



	return set[s][la->kind];
}

Parser::~Parser() {
	delete errors;
	delete dummyToken;
}

Errors::Errors() {
	count = 0;
}

void Errors::SynErr(int line, int col, int n) {
	wchar_t* s;
	switch (n) {
			case 0: s = coco_string_create(L"EOF expected"); break;
			case 1: s = coco_string_create(L"ident expected"); break;
			case 2: s = coco_string_create(L"number expected"); break;
			case 3: s = coco_string_create(L"\"BEGIN_VAR\" expected"); break;
			case 4: s = coco_string_create(L"\"END_VAR\" expected"); break;
			case 5: s = coco_string_create(L"\"PROGRAM\" expected"); break;
			case 6: s = coco_string_create(L"\"BEGIN\" expected"); break;
			case 7: s = coco_string_create(L"\"END\" expected"); break;
			case 8: s = coco_string_create(L"\":\" expected"); break;
			case 9: s = coco_string_create(L"\";\" expected"); break;
			case 10: s = coco_string_create(L"\"WHILE\" expected"); break;
			case 11: s = coco_string_create(L"\"DO\" expected"); break;
			case 12: s = coco_string_create(L"\"IF\" expected"); break;
			case 13: s = coco_string_create(L"\"THEN\" expected"); break;
			case 14: s = coco_string_create(L"\"ELSE\" expected"); break;
			case 15: s = coco_string_create(L"\"print\" expected"); break;
			case 16: s = coco_string_create(L"\"(\" expected"); break;
			case 17: s = coco_string_create(L"\")\" expected"); break;
			case 18: s = coco_string_create(L"\":=\" expected"); break;
			case 19: s = coco_string_create(L"\"=\" expected"); break;
			case 20: s = coco_string_create(L"\"<=\" expected"); break;
			case 21: s = coco_string_create(L"\">=\" expected"); break;
			case 22: s = coco_string_create(L"\"!=\" expected"); break;
			case 23: s = coco_string_create(L"\"<\" expected"); break;
			case 24: s = coco_string_create(L"\">\" expected"); break;
			case 25: s = coco_string_create(L"\"*\" expected"); break;
			case 26: s = coco_string_create(L"\"/\" expected"); break;
			case 27: s = coco_string_create(L"\"+\" expected"); break;
			case 28: s = coco_string_create(L"\"-\" expected"); break;
			case 29: s = coco_string_create(L"\"Integer\" expected"); break;
			case 30: s = coco_string_create(L"??? expected"); break;
			case 31: s = coco_string_create(L"invalid Stat"); break;
			case 32: s = coco_string_create(L"invalid InstructionLine"); break;
			case 33: s = coco_string_create(L"invalid Controlblock"); break;
			case 34: s = coco_string_create(L"invalid Relop"); break;
			case 35: s = coco_string_create(L"invalid AddOp"); break;
			case 36: s = coco_string_create(L"invalid Fact"); break;
			case 37: s = coco_string_create(L"invalid MulOp"); break;

		default:
		{
			wchar_t format[20];
			coco_swprintf(format, 20, L"error %d", n);
			s = coco_string_create(format);
		}
		break;
	}
	wprintf(L"-- line %d col %d: %ls\n", line, col, s);
	coco_string_delete(s);
	count++;
}

void Errors::Error(int line, int col, const wchar_t *s) {
	wprintf(L"-- line %d col %d: %ls\n", line, col, s);
	count++;
}

void Errors::Warning(int line, int col, const wchar_t *s) {
	wprintf(L"-- line %d col %d: %ls\n", line, col, s);
}

void Errors::Warning(const wchar_t *s) {
	wprintf(L"%ls\n", s);
}

void Errors::Exception(const wchar_t* s) {
	wprintf(L"%ls", s); 
	exit(1);
}

} // namespace


