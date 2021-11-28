#include "Symbol.h"
#ifndef CONSTINTSYMBOL_H
#define CONSTINTSYMBOL_H
namespace MIEC {
class ConstIntSymbol : Symbol
{
	public:
		ConstIntSymbol(std::string const &name, Type *type, int value);
		int GetValue();
	private:
		int mValue;
};
}
#endif
