#include "DACOperand.h"

namespace MIEC {
    DACOperand::DACOperand(std::unique_ptr<DACEntry> entry) : mEntry(std::move(entry))
    {
        mClass = OpClass::eDACOp;
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
