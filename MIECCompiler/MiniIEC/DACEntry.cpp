#include "DACEntry.h"

namespace MIEC {
    DACEntry::DACEntry(OpKind op, Operand* first, Operand* second, int nr, std::wstring label) :
        mOp(op), mFirst(first), mSecond(second), mNr(nr), mLabel(label)
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

    int DACEntry::getNr()
    {
        return mNr;
    }

    std::wstring* DACEntry::getLabel()
    {
        return &mLabel;
    }
    void DACEntry::Print(std::wostream& wost)
    {
        mFirst->Print(wost);
        wost << " <" << (int)mOp << "> ";
        mSecond->Print(wost);
    }
}
