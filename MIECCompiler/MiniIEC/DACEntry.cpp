#include "DACEntry.h"

namespace MIEC {
    DACEntry::DACEntry(OpClass op, Operand* first, Operand* second, std::wstring label) :
        mOp(op), mFirst(first), mSecond(second), mLabel(label)
    {
    }

    Operand* DACEntry::getFirst()
    {
        return mFirst;
    }

    Operand* DACEntry::getSecond()
    {
        return mSecond;
    }

    OpKind DACEntry::getOp()
    {
        return mOp;
    }

    std::wstring* DACEntry::getLabel()
    {
        return &mLabel;
    }
}
