#include "VarSymbol.h"


namespace MIEC {
VarSymbol::VarSymbol(std::unique_ptr<Type>&& type, std::wstring const& name, size_t const offset) : Symbol(std::move(type), name), mOffset(offset)
{}

size_t VarSymbol::GetOffset()
{
	return mOffset;
}
void VarSymbol::Print(std::wostream& out, size_t indent) const
{
	out << std::wstring(indent, ' ') << L"VarSym: " << mName << L" with offset " << mOffset << std::endl;
}

SymbolKind VarSymbol::GetKind() const
{
	return SymbolKind::Variable;
}

}
