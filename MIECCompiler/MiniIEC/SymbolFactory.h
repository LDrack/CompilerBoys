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

		std::shared_ptr<VarSymbol> CreateVar(std::wstring const &name, Kind type);
		std::shared_ptr<ConstIntSymbol> CreateConstInt(int value);
		std::shared_ptr<TypeSymbol> CreateTypeSym(std::wstring const &name, Kind kind);

	private:
		SymbolFactory() = default;
		SymbolFactory(SymbolFactory const&) = delete;
		SymbolFactory& operator= (SymbolFactory const&) = delete;
		static std::unique_ptr<SymbolFactory> mInstance;

};

}
//init static member
//std::unique_ptr<MIEC::SymbolFactory> MIEC::SymbolFactory::mInstance{nullptr};
#endif
