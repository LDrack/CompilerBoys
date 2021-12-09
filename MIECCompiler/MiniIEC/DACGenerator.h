#ifndef _DAC_GENERATOR__
#define _DAC_GENERATOR__

#include <ostream>
#include <vector>
#include "Object.h"
#include "DACEntry.h"
#include "OpClass.h"
#include "Operand.h"

namespace MIEC {
	class DACGenerator : Object {
	public:
		DACGenerator();

		bool AddStat(OpKind op, Operand* first);
		bool AddStat(OpKind op, Operand* first, Operand* second);


		void Print(std::wostream &wost);
	private:
		std::vector<DACEntry> mEntries;
	};

}

#endif