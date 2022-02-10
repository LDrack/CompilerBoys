#ifndef _DAC_OPERAND__
#define _DAC_OPERAND__

#include "Operand.h"
//#include "DACEntry.h"
#include "DACGenerator.h"

namespace MIEC {
	class DACOperand : public Operand {
	public:
		DACOperand(DACEntry* entry);
		DACEntry* getDACEntry();
		void Print(std::wostream& wost, size_t indent) const override;

	private:
		DACEntry* mEntry;
	};
}

#endif
