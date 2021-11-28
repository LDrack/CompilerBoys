#include "ConstIntSymbol.h"


namespace MIEC {
ConstIntSymbol::ConstIntSymbol(std::string const &name, Type *type, int value) : Symbol(name, type), mValue(value)
{}

int ConstIntSymbol::GetValue()
{
	return mValue;
}
}
