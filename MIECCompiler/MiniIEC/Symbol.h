#include <string>
#include <iostream>
#include "Type.h"
#include "Kind.h"

#ifndef SYMBOL_H
#define SYMBOL_H
namespace MIEC {

class Symbol
{
	public:
		Symbol() = delete;
		std::wstring* GetName();
		Kind GetType();
		virtual void Print(std::wostream& out, size_t indent = 0) const = 0;
	protected:
		Symbol(std::wstring const &name, Kind type);
		std::wstring mName;
		Kind mType;
};

}

#endif
