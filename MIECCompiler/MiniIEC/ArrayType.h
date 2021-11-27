#ifndef ARRAYTYPE_H_
#define ARRAYTYPE_H_

#include "Type.h"

namespace MIEC {
	class ArrayType : public Type {
		ArrayType(Type* elemType) : mElemType(elemType) {}

		size_t getSize();

	private:
		Type* mElemType;
	};
}

#endif
