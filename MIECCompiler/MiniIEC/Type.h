#ifndef TYPE_H__
#define TYPE_H__

#include "Object.h"
#include <cstddef>
//#include "TypeSymbol.h"

namespace MIEC {
	class Type : public Object {
	public:
		virtual ~Type() = default;
		virtual size_t getSize() = 0;
	protected:
		Type() = default;
	};
}

#endif
