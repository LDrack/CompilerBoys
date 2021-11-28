#include "TypeSymbol.h"

namespace MIEC {
TypeSymbol::TypeSymbol(std::string const &name, Type *type) : Symbol(name, type)
{}
}
