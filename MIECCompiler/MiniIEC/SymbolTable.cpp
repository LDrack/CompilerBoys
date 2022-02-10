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

//std::shared_ptr<Symbol> SymbolTable::Insert(std::shared_ptr<Symbol> symbol)
//{
//	if(Find(*symbol->GetName()) == nullptr)
//	{
//		mTable.push_back(symbol);
//		return symbol;
//	}
//	return nullptr;
//}
//
//std::shared_ptr<Symbol> SymbolTable::Add(int const value)
//{
//	std::shared_ptr<Symbol> sym = mFac->CreateConstInt(value);
//	return Insert(sym);
//}
//
//std::shared_ptr<Symbol> SymbolTable::Add(std::wstring const &name, Kind type)
//{
//	std::shared_ptr<Symbol> sym = mFac->CreateVar(name, type);
//	return Insert(sym);
//}
//
//std::shared_ptr<Symbol> SymbolTable::Find(std::wstring const &name)
//{
//	for(auto elem : mTable) {
//		if (name.compare(*elem->GetName())==0)
//			return elem;
//	}
//	return nullptr;
//}

Symbol* SymbolTable::Add(std::unique_ptr<Symbol> sym)
{
	const std::wstring name = sym->GetName();

	if (mTable.find(name) != mTable.end()) {
		std::string strName(name.begin(), name.end());
		throw std::invalid_argument("A symbol with this name \"" + strName + "\" is already in the symbol table!");
	}
	mTable[name] = std::move(sym);
	return mTable[name].get();
}

Symbol* SymbolTable::Find(std::wstring const& name) const
{
	if (mTable.find(name) == mTable.end()) {
		return nullptr;
	}
	return mTable.at(name).get();
}

void SymbolTable::Print(std::wostream &ost)
{
	ost << "---Begin SymbolTable---" << std::endl;
	//for_each(mTable.begin(), mTable.end(), [&ost](auto it)
	//		{ost << it.second->GetName() << std::endl;});
	for (auto const& sympair : mTable) {
		ost << sympair.second->GetName() << std::endl;
	}
	ost << "---End SymbolTable---" << std::endl;
}
//std::unique_ptr<Symbol> SymbolTable::Insert(std::unique_ptr<Symbol> symbol)
//{
//	if (Find(*symbol->GetName()) == nullptr)
//	{
//		mTable.push_back(std::move(symbol));
//		return symbol;
//	}
//	return nullptr;
//}
}
