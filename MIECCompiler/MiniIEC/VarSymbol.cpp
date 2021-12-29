#include "VarSymbol.h"


namespace MIEC {
VarSymbol::VarSymbol(std::wstring const &name, Kind type, size_t offset) : Symbol(name, type), mOffset(offset)
{}

size_t VarSymbol::GetOffset()
{
	return mOffset;
}
void VarSymbol::Print(std::wostream& out, size_t indent) const
{
	out << std::wstring(indent, ' ') << L"VarSym: " << mName << L" with offset " << mOffset << std::endl;
}

}
