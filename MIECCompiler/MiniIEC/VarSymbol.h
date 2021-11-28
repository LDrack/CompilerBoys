#include "Symbol.h"

#ifndef VARSYMBOL_H
#define VARSYMBOL_H
namespace MIEC {
class VarSymbol : Symbol
{
	public:
		VarSymbol(std::string const &name, Type *type, size_t offset);
		size_t GetOffset();
	private:
		size_t mOffset;
};
}
#endif
