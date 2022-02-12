#include "SymbolFactory.h"
#include "BasicType.h"
#include <algorithm>


namespace MIEC {

SymbolFactory& SymbolFactory::GetInstance()
{
	if (mInstance == nullptr) mInstance = std::unique_ptr<SymbolFactory>(new SymbolFactory);
	mInstance->offset = 0;
	return *mInstance;
}

void SymbolFactory::Delete()
{
	mInstance.reset();
}

std::unique_ptr<VarSymbol> SymbolFactory::CreateVar(const Type* const type, std::wstring const& name)
{
	auto var = std::make_unique<VarSymbol>(type->getUniquePtr(), name, mInstance->offset);
	mInstance->offset += type->getSize();
	return var;
}

std::unique_ptr<ConstIntSymbol> SymbolFactory::CreateConstInt(const Type* const type, std::wstring const& name, int const value)
{
	return std::make_unique<ConstIntSymbol>(type->getUniquePtr(), name, value);
}

std::unique_ptr<TypeSymbol> SymbolFactory::CreateTypeSym(const BasicTypeKind basicTypeKind, std::wstring const& name)
{
	return std::make_unique<TypeSymbol>(std::make_unique<BasicType>(basicTypeKind), name);
}
}
