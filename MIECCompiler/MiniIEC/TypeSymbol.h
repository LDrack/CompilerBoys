#include "Symbol.h"

#ifndef TYPESYMBOL_H
#define TYPESYMBOL_H
namespace MIEC {
class TypeSymbol : Symbol {
public:
	TypeSymbol(std::wstring const &name, Kind type);
	virtual void Print(std::wostream& out, size_t indent = 0) const override;
};
}
#endif
