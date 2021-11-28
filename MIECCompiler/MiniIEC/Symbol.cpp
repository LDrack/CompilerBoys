#include "Symbol.h"

namespace MIEC {
Symbol::Symbol(std::string const &name, Type *type) : mName(name), mType(type)
{}

std::string* Symbol::GetName()
{
	return &mName;
}

Type* Symbol::GetType()
{
	return mType;
}
}
