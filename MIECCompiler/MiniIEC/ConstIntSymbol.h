#include "Symbol.h"
#ifndef CONSTINTSYMBOL_H
#define CONSTINTSYMBOL_H
namespace MIEC {
class ConstIntSymbol : public Symbol
{
public:
	ConstIntSymbol(std::unique_ptr<Type>&& type, std::wstring const &name, int value);
	int GetValue();
	virtual void Print(std::wostream& out, size_t indent = 0) const override;
	SymbolKind GetKind() const;
private:
	int mValue;
};
}
#endif
