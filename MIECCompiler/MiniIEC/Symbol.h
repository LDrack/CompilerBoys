#include <string>
#include <iostream>
#include "Object.h"
#include "Type.h"
#include "Kind.h"

#ifndef SYMBOL_H
#define SYMBOL_H
namespace MIEC {

	enum class SymbolKind { Undefined, Variable, ConstInt, Type };

	class Symbol : public Object
	{
		public:
			Symbol(std::unique_ptr<Type> &&type, std::wstring const& name);
			virtual ~Symbol() = default;

			std::wstring GetName();
			virtual SymbolKind GetKind() const = 0;
			virtual void Print(std::wostream& out, size_t indent = 0) const = 0;
			const Type* GetType() const;

		protected:
			const std::wstring mName;
			const std::unique_ptr<Type> mType;
	};

}

#endif
