#include <string>
#include "Type.h"

class Symbol
{
	public:
		Symbol() = delete;
		std::string* GetName();
		Type* GetType();
	protected:
		Symbol(std::string const &name, Type const &type)
	private:
		std::string mName;
		Type mType;
};
