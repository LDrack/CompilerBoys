#ifndef BASETYPE_H_
#define BASETYPE_H_

#include "Type.h"

enum TypeKind {
	eINT,
	eFLOAT
};

class BaseType : private Type {
	size_t getSize();
	TypeKind getKind();

private:
	TypeKind mTypeKind;
};

#endif
