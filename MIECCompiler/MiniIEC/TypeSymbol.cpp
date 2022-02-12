#include "TypeSymbol.h"

namespace MIEC {
TypeSymbol::TypeSymbol(std::unique_ptr<Type>&& type, std::wstring const &name) : Symbol(std::move(type), name)
{}

void TypeSymbol::Print(std::wostream & out, size_t indent) const
{
	out << std::wstring(indent, ' ') << L"TypeSym: " << mName << std::endl;
}
SymbolKind TypeSymbol::GetKind() const
{
	return SymbolKind::Type;
}
}
