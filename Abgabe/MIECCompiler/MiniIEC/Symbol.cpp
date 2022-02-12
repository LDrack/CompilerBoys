#include "Symbol.h"

namespace MIEC {

	Symbol::Symbol(std::unique_ptr<Type>&& type, std::wstring const& name): mName(name), mType(std::move(type))
	{}

	std::wstring Symbol::GetName()
	{
		return mName;
	}

	const Type* Symbol::GetType() const
	{
		return mType.get();
	}

}
