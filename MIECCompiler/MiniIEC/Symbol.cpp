#include "Symbol.h"

namespace MIEC {
Symbol::Symbol(std::wstring const &name, Kind type) : mName(name), mType(type)
{}

std::wstring* Symbol::GetName()
{
	return &mName;
}

Kind Symbol::GetType()
{
	return mType;
}
}
