#include "Symbol.h"

namespace MIEC {
class ConstIntSymbol : Symbol
{
	public:
		ConstIntSymbol(std::string const &name, Type const &type, int value);
		int GetValue();
	private:
		int mValue;
}
}
