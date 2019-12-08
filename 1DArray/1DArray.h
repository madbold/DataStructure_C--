
#include <iostream>
#include <string>

using namespace std;

class Array1D
{
public:
	Array1D()= default;
	explicit Array1D(size_t size);
	Array1D(const char* str);
	Array1D(const Array1D& src);
	Array1D operator=(Array1D& src); // comment this if you use copy-swap idiom
	//Array1D& operator=(Array1D src); //copy and swap
	friend ostream& operator<<(ostream & out, const Array1D& input);
	char& operator[](size_t index);
	Array1D(Array1D&& src); 
	Array1D& operator=(Array1D&& src); // this gives compile error with copy and idiom
	~Array1D();

	size_t	size();


private:
	char * _str;
	size_t _size;
	

	void _assign(char* dest,const char* src);
};