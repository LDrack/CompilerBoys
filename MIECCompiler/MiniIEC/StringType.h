#ifndef STRINGTYPE_H_
#define STRINGTYPE_H_

#include "Type.h"

namespace MIEC {

	class StringType : public Type {
		size_t getSize() { return mLen; }

	private:
		size_t mLen;
	};

}

#endif
