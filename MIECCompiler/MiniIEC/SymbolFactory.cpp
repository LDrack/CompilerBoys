#include "SymbolFactory.h"
#include <algorithm>


namespace MIEC {
static SymbolFactory& SymbolFactory::GetInstance()
{
	if (mInstance == nullptr) mInstance = unique_ptr<SymbolFactory>(new SymbolFactory);
	return *mInstance;
}

static void SymbolFactory::Delete()
{
	mInstance.reset();
}

std::shared_ptr<Symbol> SymbolFactory::CreateVar(const std::string &name, const Type &type, size_t offset)
{
	return std::make_shared<VarSymbol>(name, type, offset);
}

std::shared_ptr<Symbol> SymbolFactory::CreateConstInt(const std::string &name, const Type &type, int value)
{
	return std::make_shared<ConstIntSymbol>(name, type, value);
}

std::shared_ptr<Symbol> SymbolFactory::CreateTypeSym(const std::string &name, const Type &type)
{
	return std::make_shared<TypeSymbol>(name, type);
}
}
