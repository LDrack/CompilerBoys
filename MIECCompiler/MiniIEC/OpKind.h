#ifndef _OPKIND__
#define _OPKIND__

#include "Object.h"

namespace MIEC {
	enum class OpKind {
		eNop, eAdd, eSubtract, eMultiply, eDivide, eIsEqual, eIsLessEqual, eIsGreaterEqual,
		eIsNotEqual, eIsLess, eIsGreater, eAssign, eJump, eIfJump, eIfFalseJump, ePrint,
		eExit
	};

	static const std::wstring opstrings[] = {L"NOP",		L"Add",        L"Subtract",
										     L"Multiply",   L"Divide",      L"IsEqual",   L"IsLessEqual", L"IsGreaterEqual",
										     L"IsNotEqual", L"IsLess",      L"IsGreater", L"Assign",      L"Jump",
										     L"IfJump",     L"IfFalseJump", L"Print",     L"Exit"
	};

	const std::wstring OpKindToString(OpKind op) {
		return opstrings[static_cast<size_t>(op)];
	}
}

#endif