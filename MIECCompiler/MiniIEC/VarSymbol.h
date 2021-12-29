#include "Symbol.h"
#include <string>

#ifndef VARSYMBOL_H
#define VARSYMBOL_H
namespace MIEC {
class VarSymbol : public Symbol
{
public:
	VarSymbol(std::wstring const &name, Kind type, size_t offset);
	size_t GetOffset();
	virtual void Print(std::wostream& out, size_t indent = 0) const override;
private:
	size_t mOffset;
};
}
#endif
