#include "SymbolFactory.h"
#include <memory>
#include <list>
#include <ostream>

#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H
namespace MIEC {
class SymbolTable
{
	public:
		static SymbolTable& GetInstance();
		static void Delete();

		std::shared_ptr<Symbol> Add(std::wstring const &name, Kind kind);
		std::shared_ptr<Symbol> Add(int const value);
		std::shared_ptr<Symbol> Find(std::wstring const &name);
		void Print(std::wostream &ost);
		std::unique_ptr<Symbol> Insert(std::unique_ptr<Symbol> symbol);

	private:
		static std::unique_ptr<SymbolTable> mInstance;
		static SymbolFactory* mFac;
		SymbolTable() = default;
		SymbolTable(SymbolTable const&) = delete;
		SymbolTable& operator= (SymbolTable const&) = delete;
		std::list<std::shared_ptr<Symbol>> mTable;

		std::shared_ptr<Symbol> Insert(std::shared_ptr<Symbol> symbol);
};
}

//init static member
//std::unique_ptr<MIEC::SymbolTable> MIEC::SymbolTable::mInstance{nullptr};
#endif
