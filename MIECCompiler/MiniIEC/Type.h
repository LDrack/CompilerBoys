#ifndef TYPE_H__
#define TYPE_H__

#include "Object.h"
#include <cstddef>
#include <memory>

namespace MIEC {

	enum class TypeKind { BasicType, StructType, ArrayType };

	class Type : public Object {
	public:
		virtual ~Type() = default;
		virtual size_t getSize() const = 0;
		virtual TypeKind getTypeKind() const = 0;
		virtual std::unique_ptr<Type> getUniquePtr() const = 0;

	//protected:
	//	Type() = default;
	};
}

#endif
