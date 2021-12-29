#include "DACOperand.h"

namespace MIEC {
    DACOperand::DACOperand(DACEntry* entry) : mEntry(entry)
    {
        mClass = OpClass::eDACOp;
    }

    DACEntry* DACOperand::getDACEntry()
    {
        return nullptr;
    }
    void DACOperand::Print(std::wostream& wost, size_t indent) const
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
