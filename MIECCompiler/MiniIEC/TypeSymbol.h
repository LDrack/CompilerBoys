#include "Symbol.h"

namespace MIEC {
class TypeSymbol : Symbol
{
	public:
		TypeSymbol(std::string const &name, Type const &type);
}
}
