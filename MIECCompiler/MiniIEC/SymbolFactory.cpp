#include "SymbolFactory.h"
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

std::shared_ptr<VarSymbol> SymbolFactory::CreateVar(const std::string &name, Type *type, size_t offset)
{
	return std::make_shared<VarSymbol>(name, type, offset);
}

std::shared_ptr<ConstIntSymbol> SymbolFactory::CreateConstInt(const std::string &name, Type *type, int value)
{
	return std::make_shared<ConstIntSymbol>(name, type, value);
}

std::shared_ptr<TypeSymbol> SymbolFactory::CreateTypeSym(const std::string &name, Type *type)
{
	return std::make_shared<TypeSymbol>(name, type);
}
}
