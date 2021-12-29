#include "TypeSymbol.h"

namespace MIEC {
TypeSymbol::TypeSymbol(std::wstring const &name, Kind type) : Symbol(name, type)
{}
void TypeSymbol::Print(std::wostream & out, size_t indent) const
{
	out << std::wstring(indent, ' ') << L"TypeSym: " << mName << std::endl;
}
}
