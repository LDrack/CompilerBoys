#ifndef BASICTYPE_H__
#define BASICTYPE_H__

#include "Type.h"
#include "Kind.h"

namespace MIEC {
	class BasicType : public Type {
		public:
			BasicType(Kind kind);
			size_t getSize() override;
		private:
			Kind mKind;
	};
}

#endif
