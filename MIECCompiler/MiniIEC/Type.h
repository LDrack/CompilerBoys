#ifndef TYPE_H__
#define TYPE_H__

#include "Object.h"
//#include "TypeSymbol.h"

namespace MIEC {
	class Type : public Object {
	public:
		virtual ~Type();
		Type();
		virtual size_t getSize() = 0;
		//TypeSymbol getNameSymbol() {
		//	return mNameSymbol;
		//}

	private:
		//TypeSymbol mNameSymbol;
	};
}

#endif
