
#include <iostream>
#include <string>
//#define COPY_SWAP
using namespace std;

/*
    1) //https://stackoverflow.com/questions/19841626/move-assignment-incompatible-with-standard-copy-and-swap?rq=1

*/

class Array1D
{
public:
	Array1D()= default;
	explicit Array1D(size_t size);
	Array1D(const char* str);
	Array1D(const Array1D& src);
	
#ifdef COPY_SWAP
	Array1D& operator=(Array1D src); //copy and swap
#else
	Array1D(Array1D&& src);
	Array1D operator=(Array1D& src); // comment this if you use copy-swap idiom
	Array1D& operator=(Array1D&& src); // this gives compile error with copy and idiom
#endif
	friend ostream& operator<<(ostream & out, const Array1D& input);
	char& operator[](size_t index);
	 
	
	~Array1D();

	size_t	size();


private:
	char * _str;
	size_t _size;
	

	void _assign(char* dest,const char* src);
};