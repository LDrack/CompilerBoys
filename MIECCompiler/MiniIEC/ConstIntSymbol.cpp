#include "ConstIntSymbol.h"


namespace MIEC {
ConstIntSymbol::ConstIntSymbol(std::wstring const &name, Kind type, int value) : Symbol(name, type), mValue(value)
{}

int ConstIntSymbol::GetValue()
{
	return mValue;
}
}
