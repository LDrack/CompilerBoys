#include <string>
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
	protected:
		Symbol(std::wstring const &name, Kind type);
	private:
		std::wstring mName;
		Kind mType;
};

}

#endif
