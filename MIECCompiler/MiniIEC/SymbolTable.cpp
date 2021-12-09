#include "SymbolTable.h"
#include "SymbolFactory.h"
#include <algorithm>


namespace MIEC {
SymbolTable& SymbolTable::GetInstance()
{
	if (mInstance == nullptr) mInstance = std::unique_ptr<SymbolTable>(new SymbolTable);
	mFac = &SymbolFactory::GetInstance();
	return *mInstance;
}

void SymbolTable::Delete()
{
	mInstance.reset();
}

std::shared_ptr<Symbol> SymbolTable::Insert(std::shared_ptr<Symbol> symbol)
{
	if(Find(*symbol->GetName()) == nullptr)
	{
		mTable.push_back(symbol);
		return symbol;
	}
	return nullptr;
}

std::shared_ptr<Symbol> SymbolTable::Add(int const value)
{
	std::shared_ptr<Symbol> sym = mFac->CreateConstInt(value);
	return Insert(sym);
}

std::shared_ptr<Symbol> SymbolTable::Add(std::wstring const &name, Kind type)
{
	std::shared_ptr<Symbol> sym = mFac->CreateVar(name, type);
	return Insert(sym);
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
