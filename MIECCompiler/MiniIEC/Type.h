#ifndef TYPE_H__
#define TYPE_H__

#include "Object.h"
//#include "TypeSymbol.h"

class Type : Object {
	virtual ~Type();
	virtual size_t getSize();
	//TypeSymbol getNameSymbol() {
		//return mNameSymbol;
	//}

protected:
	Type();
	size_t mSize;

private:
	//TypeSymbol mNameSymbol;
};

#endif
