#ifndef DAC_ENTRY_FAC_H
#define DAC_ENTRY_FAC_H

#include "Object.h"
#include "DACEntry.h"
#include "Operand.h"
#include "DACOperand.h"
#include "SymOperand.h"
#include "DACOperand.h"

namespace MIEC {

	class DACFactory : public Object {
	public:
        static std::unique_ptr<DACEntry> createEntry(const OpKind op,
            std::unique_ptr<Operand>&& arg1 = nullptr,
            std::unique_ptr<Operand>&& arg2 = nullptr,
            std::wstring label = L"") {
            return std::make_unique<DACEntry>(op, std::move(arg1), std::move(arg2));
        }

        static std::unique_ptr<SymOperand> createSymOperand(const Symbol* symbol) {
            return std::make_unique<SymOperand>(symbol);
            //return std::make_unique<Operand>(symbol);
        }

        static std::unique_ptr<DACOperand> createDACOperand(std::unique_ptr<DACEntry> entry) {
            return std::make_unique<DACOperand>(entry.get());
            //return std::make_unique<Operand>(entry.get());
        }




	};


}

#endif
