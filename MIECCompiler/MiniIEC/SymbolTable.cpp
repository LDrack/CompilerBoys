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
	if(Find(*symbol->GetName()) == nullptr)
	{
		mTable.push_back(symbol);
		return true;
	}
	return false;
}

std::shared_ptr<Symbol> SymbolTable::Find(std::wstring const &name)
{
	for(auto elem : mTable) {
		if (name.compare(*elem->GetName())==0)
			return elem;
	}
	return nullptr;
}

void SymbolTable::Print(std::wostream &ost)
{
	ost << "---Begin SymbolTable---" << std::endl;
	for_each(mTable.begin(), mTable.end(), [&ost](auto it)
			{ost << *it->GetName() << std::endl;});
	ost << "---End SymbolTable---" << std::endl;
}
}
