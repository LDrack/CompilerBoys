#include "Symbol.h"

Symbol::Symbol(std::string const &name, Type const &type) : mName(name), mType(type)
{}

std::string* Symbol::GetName()
{
	return &mName;
}

Type* Symbol::GetType();
{
	return &mType;
}
