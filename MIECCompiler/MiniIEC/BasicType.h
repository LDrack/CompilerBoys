#ifndef BASICTYPE_H__
#define BASICTYPE_H__

#include "Type.h"
#include "Kind.h"

namespace MIEC {

	enum class BasicTypeKind { None, Integer };

	class BasicType : public Type {
		public:
			BasicType(BasicTypeKind basicType);
			size_t getSize() const override;
			TypeKind getTypeKind() const override;
			BasicTypeKind getBasicTypeKind() const;
			std::unique_ptr<Type> getUniquePtr() const override;
		private:
			BasicTypeKind mBasicTypeKind;
	};
}

#endif
