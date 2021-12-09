#ifndef _OPERAND__
#define _OPERAND__

#include "Object.h"
#include "OpClass.h"

namespace MIEC {
	class Operand : Object {
	public:
		virtual ~Operand() = default;
		OpClass getOpClass();

	protected:
		Operand();
		OpClass mClass;
	};
}

#endif