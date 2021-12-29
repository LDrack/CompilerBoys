#include "SymbolFactory.h"
#include "BasicType.h"
#include <algorithm>


namespace MIEC {

SymbolFactory& SymbolFactory::GetInstance()
{
	if (mInstance == nullptr) mInstance = std::unique_ptr<SymbolFactory>(new SymbolFactory);
	return *mInstance;
}

void SymbolFactory::Delete()
{
	mInstance.reset();
}

std::shared_ptr<VarSymbol> SymbolFactory::CreateVar(std::wstring const &name, Kind type)
{
	return std::make_shared<VarSymbol>(name, type, 0);
}

std::shared_ptr<ConstIntSymbol> SymbolFactory::CreateConstInt(int value)
{
	return std::make_shared<ConstIntSymbol>(std::to_wstring(value),
			Kind::eInt, value);
}

std::shared_ptr<TypeSymbol> SymbolFactory::CreateTypeSym(std::wstring const &name, Kind kind)
{
	return std::make_shared<TypeSymbol>(name, kind);
}
}
