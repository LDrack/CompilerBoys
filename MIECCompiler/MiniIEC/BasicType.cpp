#include "BasicType.h"

namespace MIEC{
	BasicType::BasicType(BasicTypeKind basicType) : mBasicTypeKind(basicType)
	{}

	size_t BasicType::getSize() const {
		switch (mBasicTypeKind) {
			case BasicTypeKind::Integer:
				return sizeof(int);
			default:
				return 0;
		}
	}

	TypeKind BasicType::getTypeKind() const
	{
		return TypeKind::BasicType;
	}
	BasicTypeKind BasicType::getBasicTypeKind() const
	{
		return mBasicTypeKind;
	}

	std::unique_ptr<Type> BasicType::getUniquePtr() const
	{
		return std::make_unique<BasicType>(*this);
	}
}
