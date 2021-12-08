#ifndef BASICTYPE_H__
#define BASICTYPE_H__

#include "Type.h"

namespace MIEC {
	class BasicType : public Type {
		public:
			enum Kind{eUndef = 0, eInt = 1};
			BasicType(int kind);
			size_t getSize() override;
		private:
			Kind mKind;
	};
}

#endif
