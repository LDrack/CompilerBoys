#ifndef _DAC_ENRTY__
#define _DAC_ENTRY__

#include <string>
#include "Object.h"
#include "OpKind.h"
#include "Operand.h"

namespace MIEC {
	class DACEntry : Object {
	public:
		DACEntry(OpClass op, Operand* first, Operand* second, std::wstring label = 0);

		Operand* getFirst();
		Operand* getSecond();
		OpKind getOp();
		std::wstring* getLabel();

	private:
		Operand* mFirst;
		Operand* mSecond;
		OpKind mOp;
		std::wstring mLabel;
	};
}

#endif