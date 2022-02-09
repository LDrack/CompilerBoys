#include "DACEntry.h"

namespace MIEC {
    DACEntry::DACEntry(OpKind op, std::unique_ptr<Operand> first,
        std::unique_ptr <Operand> second, std::wstring label) :
        mOp(op), mFirst(std::move(first)), mSecond(std::move(second)),  mLabel(label)
    {
    }

    //Operand* DACEntry::getFirst()
    //{
    //    return mFirst;
    //}

    //Operand* DACEntry::getSecond()
    //{
    //    return mSecond;
    //}

    //OpKind DACEntry::getOp()
    //{
    //    return mOp;
    //}

    //int DACEntry::getNr()
    //{
    //    return mNr;
    //}

    //std::wstring* DACEntry::getLabel()
    //{
    //    return &mLabel;
    //}

    void DACEntry::Print(std::wostream& wost, size_t indent) const
    {
        wost << std::wstring(indent, ' ') << "(" << mNr << ") Entry: \"" << mLabel << "\" of type \""
            << OpKindToString(mOp) << "\"" << std::endl;
        if (mFirst)
            mFirst->Print(wost, indent + 3);
        if (mSecond)
            mSecond->Print(wost, indent + 3);

        //mFirst->Print(wost);
        //wost << " <" << (int)mOp << "> ";
        //mSecond->Print(wost);
    }
}
