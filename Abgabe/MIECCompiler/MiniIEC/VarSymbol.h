#include "Symbol.h"
#include <string>

#ifndef VARSYMBOL_H
#define VARSYMBOL_H
namespace MIEC {
class VarSymbol : public Symbol
{
public:
	VarSymbol(std::unique_ptr<Type>&& type, std::wstring const &name, size_t const offset);
	size_t GetOffset();
	virtual void Print(std::wostream& out, size_t indent = 0) const override;
	SymbolKind GetKind() const;
private:
	size_t mOffset;
};
}
#endif
