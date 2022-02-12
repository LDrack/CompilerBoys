#ifndef STRUCTTYPE_H_
#define STRUCTTYPE_H_

#include "Type.h"

namespace MIEC {
	class StructType : public Type {
		size_t getSize() const override { return 4711; }
		TypeKind getTypeKind() const override { return TypeKind::StructType; };
		std::unique_ptr<Type> getUniquePtr() const override { return std::make_unique<StructType>(*this);  };

	};
}

#endif
