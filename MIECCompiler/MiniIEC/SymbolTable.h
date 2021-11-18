#include "Symbol.h"

class SymbolTable
{
	public:
		static SymbolTable& GetInstance();
		static void Delete();

	private:
		static std::unique_ptr<SymbolTable> mInstance;
		SymbolTable() = default;
		SymbolTable(SymbolTable const&) = delete;
		SymbolTable& operator= (SymbolTable const&) = delete;
}

//init static member
unique_ptr<SymbolTable> Singleton::mInstance{nullptr};
