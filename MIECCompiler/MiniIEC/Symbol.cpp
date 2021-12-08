#include "Symbol.h"

namespace MIEC {
Symbol::Symbol(std::wstring const &name, Type *type) : mName(name), mType(type)
{}

std::wstring* Symbol::GetName()
{
	return &mName;
}

Type* Symbol::GetType()
{
	return mType;
}
}
