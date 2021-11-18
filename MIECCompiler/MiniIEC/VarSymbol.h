#include "Symbol.h"

class VarSymbol : Symbol
{
	public:
		VarSymbol(std::string const &name, Type const &type, size_t offset);
		size_t GetOffset();
	private:
		size_t mOffset;
}
