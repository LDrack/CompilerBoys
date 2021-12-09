#ifndef _OPKIND__
#define _OPKIND__

#include "Object.h"

namespace MIEC {
	enum class OpKind {
		eAdd, eSubtract, eMultiply, eDivide, eIsEqual, eIsLessEqual, eIsGreaterEqual,
		eIsNotEqual, eIsLess, eIsGreater, eAssign, eJump, eIfJump, eIfFalseJump, ePrint,
		eExit
	};
}

#endif