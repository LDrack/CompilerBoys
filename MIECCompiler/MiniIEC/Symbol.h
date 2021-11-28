#include <string>
#include "Type.h"

#ifndef SYMBOL_H
#define SYMBOL_H
namespace MIEC {

class Symbol
{
	public:
		Symbol() = delete;
		std::string* GetName();
		Type* GetType();
	protected:
		Symbol(std::string const &name, Type *type);
	private:
		std::string mName;
		Type* mType;
};

}

#endif
