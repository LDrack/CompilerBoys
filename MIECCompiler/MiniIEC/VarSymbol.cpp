#include "VarSymbol.h"


namespace MIEC {
VarSymbol::VarSymbol(std::wstring const &name, Type *type, size_t offset) : Symbol(name, type), mOffset(offset)
{}

size_t VarSymbol::GetOffset()
{
	return mOffset;
}
}