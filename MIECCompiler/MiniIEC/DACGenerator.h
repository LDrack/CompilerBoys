#ifndef _DAC_GENERATOR__
#define _DAC_GENERATOR__

#include <ostream>
#include <vector>
#include "Object.h"
//#include "DACEntry.h"
#include "Operand.h"


namespace MIEC {
	class DACEntry;
	class DACGenerator : Object {
	public:
		//bool AddStat(OpKind op, Operand* first);
		//bool AddStat(OpKind op, Operand* first, Operand* second);

		void AddStat(std::unique_ptr<DACEntry> entry);

		void Print(std::wostream &wost);
	private:
		std::vector<std::unique_ptr<DACEntry>> mEntries;
	};

}

#endif
