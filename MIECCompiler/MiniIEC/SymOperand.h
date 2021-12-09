#ifndef _SYMOPERAND__
#define _SYMOPERAND__

#include "Object.h"
#include "Operand.h"
#include "Symbol.h"

namespace MIEC {
	class SymOperand : Operand {
	public:
		SymOperand(Symbol* sym);
		Symbol* getSymbol();
		void Print(std::wostream& wost);

	private:
		Symbol* mSymbol;
	};
}

#endif