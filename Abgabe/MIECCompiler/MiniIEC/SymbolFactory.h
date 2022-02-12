#include "VarSymbol.h"
#include "ConstIntSymbol.h"
#include "TypeSymbol.h"
#include "BasicType.h"
#include <memory>

#ifndef SYMBOLFACTORY_H
#define SYMBOLFACTORY_H
namespace MIEC {
class SymbolFactory
{
	public:
		static SymbolFactory& GetInstance();
		static void Delete();

		std::unique_ptr<VarSymbol> CreateVar(const Type *const type, std::wstring const &name);
		std::unique_ptr<ConstIntSymbol> CreateConstInt(const Type* const type, std::wstring const& name, int const value);
		std::unique_ptr<TypeSymbol> CreateTypeSym(const BasicTypeKind basicTypeKind, std::wstring const &name);

	private:
		SymbolFactory() = default;
		SymbolFactory(SymbolFactory const&) = delete;
		SymbolFactory& operator= (SymbolFactory const&) = delete;
		static std::unique_ptr<SymbolFactory> mInstance;

		size_t offset = 0;
};

}
//init static member
//std::unique_ptr<MIEC::SymbolFactory> MIEC::SymbolFactory::mInstance{nullptr};
#endif
