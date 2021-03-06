

#if !defined(COCO_PARSER_H__)
#define COCO_PARSER_H__

#include "SymbolTable.h"
#include "SymbolFactory.h"
#include "Kind.h"
#include "DACFactory.h"
#include "Type.h"
#include <charconv>


#include "Scanner.h"

namespace MIEC {


class Errors {
public:
	int count;			// number of errors detected

	Errors();
	void SynErr(int line, int col, int n);
	void Error(int line, int col, const wchar_t *s);
	void Warning(int line, int col, const wchar_t *s);
	void Warning(const wchar_t *s);
	void Exception(const wchar_t *s);

}; // Errors

class Parser {
private:
	enum {
		_EOF=0,
		_ident=1,
		_number=2
	};
	int maxT;

	Token *dummyToken;
	int errDist;
	int minErrDist;

	void SynErr(int n);
	void Get();
	void Expect(int n);
	bool StartOf(int s);
	void ExpectWeak(int n, int follow);
	bool WeakSeparator(int n, int syFol, int repFol);

public:
	Scanner *scanner;
	Errors  *errors;

	Token *t;			// last recognized token
	Token *la;			// lookahead token

SymbolTable   *tab = &MIEC::SymbolTable::GetInstance();
    SymbolFactory *fac = &MIEC::SymbolFactory::GetInstance();
    DACGenerator dac;
    // CodeGenerator *gen;
/*--------------------END VARIABLE DECLARATION------------------------------*/

/*--------------------BEGIN FUNCTION DECLARATION----------------------------*/
    void Err(wchar_t* msg) {
        errors->Error(la->line, la->col, msg);
    }

    // int // types
    //   undef, Integer;

    // void InitDeclarations() { // it must exist
    //     undef = 0; Integer = 1; // types
    // }


    const Type* getIntegerType() {
      std::wstring typeName = L"[Type]Integer";
      MIEC::Symbol* sym = tab->Find(typeName);
      if (!sym || sym->GetKind() != SymbolKind::Type) {
        std::unique_ptr<MIEC::TypeSymbol> typeSym = fac->CreateTypeSym(BasicTypeKind::Integer, typeName);
        sym = tab->Add(std::move(typeSym));
        if (!sym) {
          Err(L"Insert Type Integer failed");
          return nullptr;
        }
      }
      return (sym->GetType());
    }

/*--------------------END FUNCTION DECLARATION------------------------------*/

/*--------------------BEGIN ALPHABET DECLARATION----------------------------*/


	Parser(Scanner *scanner);
	~Parser();
	void SemErr(const wchar_t* msg);

	void VarBlock();
	void VarDecl();
	void MIEC();
	void Statements();
	void Ident(wchar_t* &name);
	void Types(const Type *&type);
	void Stat();
	void InstructionLine(std::unique_ptr<MIEC::DACEntry> &entry );
	void Controlblock();
	void WhileLoop();
	void ConditionalBlock();
	void Condition(std::unique_ptr<MIEC::DACEntry> &entry );
	void Expr(std::unique_ptr<MIEC::DACEntry>& entry );
	void Relop(OpKind &op );
	void Assignment(std::unique_ptr<MIEC::DACEntry> &entry );
	void Print(std::unique_ptr<MIEC::DACEntry> &entry );
	void Term(std::unique_ptr<MIEC::DACEntry> &entry );
	void AddOp(OpKind &op);
	void Fact(std::unique_ptr<MIEC::DACEntry> &entry );
	void MulOp(OpKind &op);
	void Number(Symbol* &numSym);

	void Parse();

}; // end Parser

} // namespace


#endif // !defined(COCO_PARSER_H__)

