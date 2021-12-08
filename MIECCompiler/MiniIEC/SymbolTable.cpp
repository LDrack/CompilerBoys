#include "SymbolTable.h"
#include <algorithm>


namespace MIEC {
SymbolTable& SymbolTable::GetInstance()
{
	if (mInstance == nullptr) mInstance = std::unique_ptr<SymbolTable>(new SymbolTable);
	return *mInstance;
}

void SymbolTable::Delete()
{
	mInstance.reset();
}

bool SymbolTable::Add(std::shared_ptr<Symbol> symbol)
{
	mTable.push_back(symbol);
	return true;
}

std::shared_ptr<Symbol> SymbolTable::Find(std::wstring const &name)
{
	for(auto elem : mTable) {
		if (name.compare(*elem->GetName())==0)
			return elem;
	}
	return nullptr;
}
}
