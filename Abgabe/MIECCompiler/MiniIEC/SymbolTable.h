#include "SymbolFactory.h"
#include <memory>
#include <list>
#include <ostream>
#include <map>

#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H
namespace MIEC {
class SymbolTable
{
	public:
		static SymbolTable& GetInstance();
		static void Delete();

		//std::shared_ptr<Symbol> Add(std::wstring const &name, Kind kind);
		//std::shared_ptr<Symbol> Add(int const value);
		Symbol* Add(std::unique_ptr<Symbol> sym);
		//std::shared_ptr<Symbol> Find(std::wstring const& name);
		Symbol* Find(std::wstring const &name) const;
		void Print(std::wostream &ost);

	private:
		static std::unique_ptr<SymbolTable> mInstance;
		static SymbolFactory* mFac;
		SymbolTable() = default;
		SymbolTable(SymbolTable const&) = delete;
		SymbolTable& operator= (SymbolTable const&) = delete;

		//std::list<std::unique_ptr<Symbol>> mTable;
		std::map<std::wstring, std::unique_ptr<Symbol>> mTable;

};
}

//init static member
//std::unique_ptr<MIEC::SymbolTable> MIEC::SymbolTable::mInstance{nullptr};
#endif
