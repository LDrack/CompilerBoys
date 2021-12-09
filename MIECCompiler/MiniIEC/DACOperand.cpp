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
    void DACOperand::Print(std::wostream& wost)
    {
        wost << "(" << mEntry->getNr() << ")";
    }
}
