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

    void SymOperand::Print(std::wostream& wost, size_t indent) const
    {
        wost << std::wstring(indent, ' ') << "SymOperand:" << std::endl;
        if (mSymbol) {
            mSymbol->Print(wost, indent + 3);
        }
        else {
            wost << std::wstring(indent + 3, ' ') << "<NULL Symbol>" << std::endl;
        }

        //wost << "(" << mSymbol->GetName() << ")";
    }

}
