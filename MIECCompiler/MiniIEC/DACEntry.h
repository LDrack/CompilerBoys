#ifndef _DAC_ENRTY_H__
#define _DAC_ENTRY_H__

#include <string>
#include "Object.h"
#include "OpKind.h"
#include "Operand.h"
#include <memory>

namespace MIEC {

	class DACEntry : public Object {
		public:
			DACEntry(OpKind op,
					std::unique_ptr<Operand> first,
					std::unique_ptr <Operand> second,
					int nr,
					std::wstring label = 0);

			//Operand* getFirst();
			//Operand* getSecond();
			//OpKind getOp();
			//int getNr();
			//std::wstring* getLabel();

			void Print(std::wostream& wost, size_t indent = 0) const;

		private:
			std::unique_ptr<Operand> mFirst, mSecond;
			OpKind mOp;
			std::wstring mLabel;
			int mNr;
	};
}

#endif
