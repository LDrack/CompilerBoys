#include "BaseType.h"

size_t BaseType::getSize()
{
	return 2;
}

TypeKind BaseType::getKind()
{
	return mTypeKind;
}
