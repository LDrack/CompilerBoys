#include "RefOperand.h"

namespace MIEC {
    RefOperand::RefOperand(const DACEntry* entry) : mEntry(entry)
    {
        mClass = OpClass::eRefOp;
    }

    void RefOperand::Print(std::wostream& wost, size_t indent) const
    {
        wost << std::wstring(indent, ' ') << "DACOperand:" << std::endl;
        if (mEntry) {
            mEntry->Print(wost, indent + 3);
        }
        else {
            wost << std::wstring(indent + 3, ' ') << "<NULL Entry>" << std::endl;
        }

        //wost << "(" << mEntry->getNr() << ")";
    }
}
