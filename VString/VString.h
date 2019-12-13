
#include <iostream>
#include <string>
#include <initializer_list>
//#define COPY_SWAP
using namespace std;

/*
    1) //https://stackoverflow.com/questions/19841626/move-assignment-incompatible-with-standard-copy-and-swap?rq=1

*/

class VString
{
public:
	explicit VString(size_t size=0);
	VString(const char* str); // 
	VString(const VString& src);
	VString(initializer_list<int>);
	char at(size_t index);
	
#ifdef COPY_SWAP
	VString& operator=(VString src); //copy and swap
#else
	VString(VString&& src);
	VString operator=(VString& src); // comment this if you use copy-swap idiom
	VString& operator=(VString&& src); // this gives compile error with copy and idiom
#endif
	friend ostream& operator<<(ostream & out, const VString& input);
	friend istream& operator>>(istream& in, VString& out);
	VString& operator=(const char* ptr);
	char& operator[](size_t index);

	~VString();

	size_t	size();


private:
	char* _str ;
	size_t _size ;
	
	bool _check(size_t index);
	void _assign(char* dest,const char* src);
};