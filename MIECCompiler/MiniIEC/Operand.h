#ifndef _OPERAND_H__
#define _OPERAND_H__

#include <iostream>
#include "Object.h"

namespace MIEC {

	enum class OpClass { eSymOp, eDACOp, eRefOp };

	class Operand : public Object {
	public:
		virtual ~Operand() = default;
		OpClass getOpClass();
		virtual void Print(std::wostream& wost, size_t indent) const = 0;

	protected:
		Operand() = default;
		OpClass mClass;
	};
}

#endif
