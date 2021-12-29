#include "DACGenerator.h"

namespace MIEC {
	//bool DACGenerator::AddStat(OpKind op, Operand* first)
	//{
	//	return false;
	//}

	//bool DACGenerator::AddStat(OpKind op, Operand* first, Operand* second)
	//{
	//	return false;
	//}

	void DACGenerator::AddStat(std::unique_ptr<DACEntry> entry)
	{
		mEntries.emplace_back(*entry);
	}

	void DACGenerator::Print(std::wostream& wost)
	{
		wost << "--- DAC ---" << std::endl;
		for (auto & elem : mEntries) {
			elem.Print(wost, 3);
		}
	}
}
