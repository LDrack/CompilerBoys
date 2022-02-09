#include "Symbol.h"

#ifndef TYPESYMBOL_H
#define TYPESYMBOL_H
namespace MIEC {
class TypeSymbol : Symbol {
public:
	TypeSymbol(std::unique_ptr<Type>&& type, std::wstring const &name);
	virtual void Print(std::wostream& out, size_t indent = 0) const override;
	SymbolKind GetKind() const;
};
}
#endif
