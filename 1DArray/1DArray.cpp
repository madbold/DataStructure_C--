#include "1DArray.h"
#include <algorithm>


Array1D::Array1D(size_t size) : _size(size)
 {
	
	 cout << " Array1D :: Array1D(size_t) >>" <<endl;
	 _str = new char[_size + 1];
	 _size = size;
	 cout << " << Array1D :: Array1D(size_t)" <<endl;
 }

void Array1D:: _assign(char* dest, const char* src)
{

	for (auto i = 0; i < this->_size; ++i)
	{
		dest[i] = src[i];
	}
	dest[_size] = '\0';
}

Array1D::Array1D(const char* str)
{
	cout << " Array1D :: Array1D(const char*) >>" <<endl;
	_size = strlen(str);
	_str = new char[_size + 1];
	_assign(this->_str, str);
	cout << " << Array1D :: Array1D(const char*)" <<endl;
}

Array1D::Array1D(const Array1D& src)
{
	cout << " Array1D :: Array1D(const Array1D&) >>" <<endl;
	_size = src._size;
	_str=new char[_size + 1];
	_assign(this->_str, src._str);
	cout << " << Array1D :: Array1D(const Array1D&)" <<endl;

} 

Array1D Array1D :: operator=(Array1D& src)
{
	cout << " Array1D :: operator=(Array1D& ) >>" << endl;
	// self assignment test
	if (this == &src)
		return (*this);


	_size = src._size;
	delete[] this->_str;
	 
	_str=new char[_size + 1];
	_assign(this->_str, src._str);

	return (*this);
	cout << " << Array1D :: operator=(Array1D& ) " <<endl;

} 

/*Array1D& Array1D :: operator=(Array1D src)
{
	// this is copy-swap idiom assignment operator
	cout << " Array1D :: operator=(Array1D --copy-swap) >>" << endl;
	// self assignment test
	if (this == &src)
		return (*this);

	swap(this->_size,src._size);
	swap(this->_str, src._str);
	
	cout << " << Array1D :: operator=(Array1D -- copy-swap) " << endl;
	return (*this);
	

} */


Array1D& Array1D :: operator=(Array1D&& src)
{

	cout << " Array1D :: operator=(Array1D&& rvalue) >>" << endl;

	this->_size = src._size;
	delete[] this->_str;
	this->_str = src._str; // here is memory leak , will fix later

	src._size = {};
	src._str = nullptr;

	return *this;

	cout << "<< Array1D :: operator=(Array1D&& rvalue)" << endl;
} 
ostream& operator<<(ostream& out, const Array1D& input)
{
	out <<'[';
	for (auto i = 0; i < input._size; ++i)
	{
		out <<input._str[i] << ',';

	}
	out << ']' << '\n';
	return out;
}

Array1D::~Array1D()
{
	cout << " ~Array1D() >>" << endl;
	delete[] _str;
	cout << " << ~Array1D()" << endl;
}


size_t Array1D:: size()
{
	return this->_size;
}

Array1D::Array1D(Array1D&& src)
{
	cout << "move ctor : Array1D( const Array1D&& src) >>" << endl;
	this->_size = src._size;
	this->_str = src._str;

	src._str = nullptr;
	src._size = {};
	cout << " << move ctor : Array1D( const Array1D&& src)" << endl;
} 
char& Array1D:: operator[](size_t index)
{
	//if (index < _size) throw exception;

	return this->_str[index];
   
}