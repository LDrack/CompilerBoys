#include "VarSymbol.h"
#include "ConstIntSymbol.h"
#include "TypeSymbol.h"
#include <memory>

#ifndef SYMBOLFACTORY_H
#define SYMBOLFACTORY_H
namespace MIEC {
class SymbolFactory
{
	public:
		static SymbolFactory& GetInstance();
		static void Delete();

		std::shared_ptr<VarSymbol> CreateVar(std::string const &name, Type * type, size_t offset);
		std::shared_ptr<ConstIntSymbol> CreateConstInt(std::string const &name, Type * type, int value);
		std::shared_ptr<TypeSymbol> CreateTypeSym(std::string const &name, Type * type);

	private:
		SymbolFactory() = default;
		SymbolFactory(SymbolFactory const&) = delete;
		SymbolFactory& operator= (SymbolFactory const&) = delete;
		static std::unique_ptr<SymbolFactory> mInstance;

};

}
//init static member
std::unique_ptr<MIEC::SymbolFactory> MIEC::SymbolFactory::mInstance{nullptr};
#endif
