#ifndef _SYMOPERAND__
#define _SYMOPERAND__

#include "Object.h"
#include "Operand.h"
#include "Symbol.h"

namespace MIEC {
	class SymOperand : Operand {
	public:
		SymOperand(Symbol* sym);
		//OpClass getOpClass();
		Symbol* getSymbol();
	private:
		Symbol* mSymbol;
	};
}

#endif