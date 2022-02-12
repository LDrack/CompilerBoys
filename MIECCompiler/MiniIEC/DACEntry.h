#ifndef _DAC_ENRTY_H__H_
#define _DAC_ENTRY_H__H_


#include <memory>
#include <string>
#include "Object.h"
#include "OpKind.h"
#include "Operand.h"

namespace MIEC {

	class DACEntry : public Object {
		public:
			DACEntry(OpKind op,
					std::unique_ptr<Operand> first,
					std::unique_ptr <Operand> second,
					std::wstring label = 0);

			void Print(std::wostream& wost, size_t indent = 0) const;

		private:
			std::unique_ptr<Operand> mFirst, mSecond;
			OpKind mOp;
			std::wstring mLabel;
	};
}

#endif
