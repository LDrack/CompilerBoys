#ifndef _OPERAND__
#define _OPERAND__

#include "Object.h"
#include "OpClass.h"
#include <iostream>

namespace MIEC {
	class Operand : Object {
	public:
		virtual ~Operand() = default;
		OpClass getOpClass();
		virtual void Print(std::wostream& wost) = 0;

	protected:
		Operand();
		OpClass mClass;
	};
}

#endif