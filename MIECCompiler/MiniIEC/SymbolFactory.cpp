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

std::shared_ptr<VarSymbol> SymbolFactory::CreateVar(std::wstring const &name, Type * type)
{
//static size_t offset = 0;
	return std::make_shared<VarSymbol>(name, type, 0);
}

std::shared_ptr<ConstIntSymbol> SymbolFactory::CreateConstInt(int value)
{
	return std::make_shared<ConstIntSymbol>(std::to_wstring(value),
			new BasicType(BasicType::Kind::eInt), value);
}

std::shared_ptr<TypeSymbol> SymbolFactory::CreateTypeSym(wchar_t * name)
{
	return std::make_shared<TypeSymbol>(name, new BasicType(BasicType::Kind::eUndef));
}
}
