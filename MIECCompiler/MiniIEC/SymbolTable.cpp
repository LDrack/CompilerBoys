#include "SymbolTable.h"
#include <algorithm>


namespace MIEC {
static SymbolTable& SymbolTable::GetInstance()
{
	if (mInstance == nullptr) mInstance = unique_ptr<SymbolTable>(new SymbolTable);
	return *mInstance;
}

static void SymbolTable::Delete()
{
	mInstance.reset();
}

bool SymbolTable::Add(std::shared_ptr<Symbol> symbol)
{
	mTable.push_pack(symbol);
}

std::shared_ptr<Symbol> SymbolTable::Find(std::string const &name)
{
	return std::find(mTable.begin(), mTable.end(), [](std::shared_ptr<Symbol> symbol)
			{
				return symbol.GetName() == name;
			});
}
}
