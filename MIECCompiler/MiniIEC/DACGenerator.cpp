#include "DACGenerator.h"

namespace MIEC {
	DACGenerator::DACGenerator()
	{
	}

	bool DACGenerator::AddStat(OpKind op, Operand* first)
	{
		return false;
	}

	bool DACGenerator::AddStat(OpKind op, Operand* first, Operand* second)
	{
		return false;
	}

	void DACGenerator::Print(std::wostream& wost)
	{
		for (auto elem : mEntries) {
			elem.Print(wost);
			wost << std::endl;
		}
	}
}
