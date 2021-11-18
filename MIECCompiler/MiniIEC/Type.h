//#include <TypeSymbol.h>

class Type {
	Type();
	virtual ~Type();
	virtual size_t getSize();
	//TypeSymbol getType() {
		//return mType;
	//}
private:
	size_t mSize;
	//TypeSymbol mType;
};
