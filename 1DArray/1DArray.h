
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
	Array1D operator=(Array1D& src);
	friend ostream& operator<<(ostream & out, Array1D& input);
	char& operator[](size_t index);
	Array1D(const Array1D&& src);
	Array1D operator=(Array1D&& src);
	~Array1D();

	size_t	size();


private:
	char * _str;
	size_t _size;
	int _index;

	void _assign(const Array1D& src);
};