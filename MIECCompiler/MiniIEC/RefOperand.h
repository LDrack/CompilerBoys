#ifndef _REF_OPERAND__
#define _REF_OPERAND__

#include "Operand.h"
//#include "DACEntry.h"
#include "DACGenerator.h"

namespace MIEC {
	class RefOperand : public Operand {
	public:
		RefOperand(const DACEntry *entry);
		void Print(std::wostream& wost, size_t indent) const override;

	private:
		const DACEntry *mEntry;
	};
}

#endif
