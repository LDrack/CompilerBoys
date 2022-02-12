#include "ConstIntSymbol.h"


namespace MIEC {
ConstIntSymbol::ConstIntSymbol(std::unique_ptr<Type>&& type, std::wstring const &name, int value) : Symbol(std::move(type), name), mValue(value)
{}

int ConstIntSymbol::GetValue()
{
	return mValue;
}
void ConstIntSymbol::Print(std::wostream& out, size_t indent) const
{
	out << std::wstring(indent, ' ') << L"ConstIntSym: " << mName << L" with value " << mValue << std::endl;
}
SymbolKind ConstIntSymbol::GetKind() const
{
	return SymbolKind::ConstInt;
}
}
