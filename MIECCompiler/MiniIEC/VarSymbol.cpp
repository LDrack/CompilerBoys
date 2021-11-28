#include "VarSymbol.h"


namespace MIEC {
VarSymbol::VarSymbol(std::string const &name, Type *type, size_t offset) : Symbol(name, type), mOffset(offset)
{}

size_t VarSymbol::GetOffset()
{
	return mOffset;
}
}
