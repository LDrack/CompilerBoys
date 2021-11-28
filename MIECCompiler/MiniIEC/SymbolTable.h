#include "Symbol.h"
#include <memory>
#include <list>

#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H
namespace MIEC {
class SymbolTable
{
	public:
		static SymbolTable& GetInstance();
		static void Delete();

		bool Add(std::shared_ptr<Symbol> symbol);
		std::shared_ptr<Symbol> Find(std::string const &name);

	private:
		static std::unique_ptr<SymbolTable> mInstance;
		SymbolTable() = default;
		SymbolTable(SymbolTable const&) = delete;
		SymbolTable& operator= (SymbolTable const&) = delete;
		std::list<std::shared_ptr<Symbol>> mTable;
};
}

//init static member
std::unique_ptr<MIEC::SymbolTable> MIEC::SymbolTable::mInstance{nullptr};
#endif
