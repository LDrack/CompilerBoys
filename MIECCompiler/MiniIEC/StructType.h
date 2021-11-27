#ifndef STRUCTTYPE_H_
#define STRUCTTYPE_H_

#include "Type.h"

namespace MIEC {
	class StructType : public Type {
		size_t getSize() { return 4711; }
	};
}

#endif
