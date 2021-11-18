#ifndef STRINGTYPE_H_
#define STRINGTYPE_H_

#include "Type.h"

class StringType : private Type {
	size_t getSize();

private:
	size_t mLen;
};

#endif
