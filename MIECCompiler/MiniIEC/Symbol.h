#include <string>
#include "Type.h"

#ifndef SYMBOL_H
#define SYMBOL_H
namespace MIEC {

class Symbol
{
	public:
		Symbol() = delete;
		std::wstring const* GetName();
		Type* GetType();
	protected:
		Symbol(std::wstring const &name, Type *type);
	private:
		std::wstring mName;
		Type* mType;
};

}

#endif
