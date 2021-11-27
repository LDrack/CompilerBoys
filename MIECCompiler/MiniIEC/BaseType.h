#ifndef BASETYPE_H_
#define BASETYPE_H_

#include "Type.h"

namespace MIEC {

	enum TypeKind { eINT, eFLOAT };

	template <enum TypeKind>
	class BaseType : public Type {};

	// Template specialization
	template <>
	class BaseType<eINT> : public Type {
		size_t getSize() { return 2; }
		TypeKind getKind() { return eINT; }

		void setValue(int v) { mVal = v; }
		int getValue() { return mVal; }
	private:
		int mVal;
	};

	template <>
	class BaseType<eFLOAT> : public Type {
		size_t getSize() { return 2; }
		TypeKind getKind() { return eFLOAT; }

		void setValue(float v) { mVal = v; }
		int getValue() { return mVal; }
	private:
		float mVal;
	};
}

#endif
