#include "ConstIntSymbol.h"


ConstIntSymbol::ConstIntSymbol(std::string const &name, Type const &type, int value) : Symbol(name, type), mValue(value)
{}

int ConstIntSymbol::GetValue()
{
	return mValue;
}
