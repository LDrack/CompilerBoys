#include "BasicType.h"

namespace MIEC{
	BasicType::BasicType(int kind) : mKind((Kind)kind)
	{}

	size_t BasicType::getSize() {
		switch (mKind) {
			case Kind::eInt:
				return sizeof(int);
			default:
				return 0;
		}
	}
}