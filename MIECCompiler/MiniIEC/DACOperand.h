#ifndef _DAC_OPERAND__
#define _DAC_OPERAND__

#include "Object.h"
#include "Operand.h"
#include "DACEntry.h"

namespace MIEC {
	class DACOperand : Operand {
	public:
		DACOperand(DACEntry* entry);
		DACEntry* getDACEntry();
		void Print(std::wostream& wost, size_t indent) const override;

	private:
		DACEntry* mEntry;
	};
}

#endif