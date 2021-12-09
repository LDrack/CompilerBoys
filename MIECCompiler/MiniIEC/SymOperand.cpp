#include "SymOperand.h"

namespace MIEC {
    
    SymOperand::SymOperand(Symbol* sym) : mSymbol(sym)
    {
        mClass = OpClass::eSymOp;
    }

    Symbol* SymOperand::getSymbol()
    {
        return mSymbol;
    }

    void SymOperand::Print(std::wostream& wost)
    {
        wost << "(" << mSymbol->GetName() << ")";
    }

}
