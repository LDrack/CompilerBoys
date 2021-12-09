#ifndef _DAC_ENRTY__
#define _DAC_ENTRY__

#include <string>
#include "Object.h"
#include "OpKind.h"
#include "Operand.h"

namespace MIEC {
	class DACEntry : Object {
	public:
		DACEntry(OpKind op, Operand* first, Operand* second, int nr, std::wstring label = 0);

		Operand* getFirst();
		Operand* getSecond();
		OpKind getOp();
		int getNr();
		std::wstring* getLabel();
		void Print(std::wostream& wost);

	private:
		Operand* mFirst;
		Operand* mSecond;
		OpKind mOp;
		std::wstring mLabel;
		int mNr;
	};
}

#endif