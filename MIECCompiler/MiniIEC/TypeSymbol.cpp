#include "TypeSymbol.h"

namespace MIEC {
TypeSymbol::TypeSymbol(std::wstring const &name, Type *type) : Symbol(name, type)
{}
}
