#include "VarSymbol.h"
#include "ConstIntSymbol.h"
#include "TypeSymbol.h"

class SymbolFactory
{
	public:
		static SymbolTable& GetInstance();
		static void Delete();

		std::shared_ptr<Symbol> CreateVar(std::string const &name, Type const & type, size_t offset);
		std::shared_ptr<Symbol> CreateConstInt(std::string const &name, Type const & type, int value);
		std::shared_ptr<Symbol> CreateTypeSym(std::string const &name, Type const & type);

	private:
		SymbolTable() = default;
		SymbolTable(SymbolTable const&) = delete;
		SymbolTable& operator= (SymbolTable const&) = delete;
		static std::unique_ptr<SymbolTable> mInstance;

		std::list<std::shared_ptr<Symbol>> mTable;
}

//init static member
unique_ptr<SymbolTable> Singleton::mInstance{nullptr};
