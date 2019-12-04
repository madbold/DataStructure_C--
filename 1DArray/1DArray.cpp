#include "1DArray.h"


 Array1D::Array1D() : _size(0), _index(-1),_str(nullptr)
{
	cout << " Array1D :: Array1D() >>" << endl;
	cout << " << Array1D :: Array1D()" << endl;
}
Array1D::Array1D(size_t size) : _size(size)
 {
	
	 cout << " Array1D :: Array1D(size_t) >>" <<endl;
	 _str = new char[_size + 1];
	 _size = size;
	 cout << " << Array1D :: Array1D(size_t)" <<endl;
 }

Array1D::Array1D(const char* str)
{
	cout << " Array1D :: Array1D(const char*) >>" <<endl;
	_size = strlen(str);
	_str = new char[_size + 1];
	for (auto i = 0; i < _size; ++i)
	{
		_str[i] = str[i];
	}
	_str[_size] = '\0';
	cout << " << Array1D :: Array1D(const char*)" <<endl;
}

Array1D::Array1D(const Array1D& src)
{
	cout << " Array1D :: Array1D(const Array1D&) >>" <<endl;
	_size = src._size;
	_str=new char[_size + 1];
	for (auto i = 0; i < _size; ++i)
	{
		_str[i] = src._str[i];
	}
	cout << " << Array1D :: Array1D(const Array1D&)" <<endl;

}

Array1D Array1D :: operator=(Array1D& src)
{
	cout << " Array1D :: operator=(Array1D& ) >>" << endl;
	// self assignment test
	if (this == &src)
		return (*this);
	_size = src._size;
	auto tmp = this->_str;
	_str=new char[_size + 1];
	for (auto i = 0; i < _size; ++i)
	{
		_str[i] = src._str[i];
	}

	delete[] tmp;

	return (*this);
	cout << " << Array1D :: operator=(Array1D& ) " <<endl;

}
ostream& operator<<(ostream& out, Array1D& input)
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

char& Array1D:: operator[](size_t index)
{
	//if (index < _size) throw exception;

	return this->_str[index];
   
}