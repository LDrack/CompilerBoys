#include "Symbol.h"
#ifndef CONSTINTSYMBOL_H
#define CONSTINTSYMBOL_H
namespace MIEC {
class ConstIntSymbol : public Symbol
{
public:
	ConstIntSymbol(std::wstring const &name, Kind type, int value);
	int GetValue();
	virtual void Print(std::wostream& out, size_t indent = 0) const override;
private:
	int mValue;
};
}
#endif
