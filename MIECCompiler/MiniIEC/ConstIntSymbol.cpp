#include "ConstIntSymbol.h"


namespace MIEC {
ConstIntSymbol::ConstIntSymbol(std::wstring const &name, Kind type, int value) : Symbol(name, type), mValue(value)
{}

int ConstIntSymbol::GetValue()
{
	return mValue;
}
void ConstIntSymbol::Print(std::wostream& out, size_t indent) const
{
	out << std::wstring(indent, ' ') << L"ConstIntSym: " << mName << L" with value " << mValue << std::endl;
}
}
