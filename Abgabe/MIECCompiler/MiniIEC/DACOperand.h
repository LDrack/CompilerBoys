#ifndef _DAC_OPERAND__
#define _DAC_OPERAND__

#include "Operand.h"
//#include "DACEntry.h"
#include "DACGenerator.h"

namespace MIEC {
	class DACOperand : public Operand {
	public:
		DACOperand(std::unique_ptr<DACEntry> entry);
		void Print(std::wostream& wost, size_t indent) const override;

	private:
		std::unique_ptr<DACEntry> mEntry;
	};
}

#endif
