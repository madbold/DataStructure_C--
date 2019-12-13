#include "VString.h"
#include <utility>
#include <algorithm>

VString::VString(size_t size) : _size(size)
 {
	
	 cout << " VString :: VString(size_t) >>" <<endl;
	 _str = new char[_size + 1];
	 _size = size;
	 cout << " << VString :: VString(size_t)" <<endl;
 }

bool VString::_check(size_t index)
{
	if (index < 0 || index >= _size) throw "Invalid index";
}
void VString:: _assign(char* dest, const char* src)
{

	for (auto i = 0; i < this->_size; ++i)
	{
		dest[i] = src[i];
	}
	dest[_size] = '\0';
}

VString::VString(initializer_list<int> lst)
{
    	     
	_size = lst.size();

	_str=new char[_size + 1];
	std::copy(lst.begin(), lst.end(), _str);
	_str[_size] = '\0';
	

}
VString::VString(const char* str)
{
	cout << " VString :: VString(const char*) >>" <<endl;
	_size = strlen(str);
	_str = new char[_size + 1];
	_assign(this->_str, str);
	cout << " << VString :: VString(const char*)" <<endl;
}

VString::VString(const VString& src)
{
	cout << " VString :: VString(const VString&) >>" <<endl;
	_size = src._size;
	_str=new char[_size + 1];
	_assign(this->_str, src._str);
	cout << " << VString :: VString(const VString&)" <<endl;

}

char VString::at(size_t index)
{
	_check(index);
	return _str[index];
}
#ifndef COPY_SWAP

VString& VString :: operator=(VString&& src)
{

	cout << " VString :: operator=(VString&& rvalue) >>" << endl;

	this->_size = src._size;
	delete[] this->_str;
	this->_str = src._str;

	src._size = {};
	src._str = nullptr;

	return *this;

	cout << "<< VString :: operator=(VString&& rvalue)" << endl;
}
VString VString :: operator=(VString& src)
{
	cout << " VString :: operator=(VString& ) >>" << endl;
	// self assignment test
	if (this == &src)
		return (*this);


	_size = src._size;
	delete[] this->_str;
	 
	_str=new char[_size + 1];
	_assign(this->_str, src._str);

	return (*this);
	cout << " << VString :: operator=(VString& ) " <<endl;

}

VString& VString :: operator=(const char* ptr)
{
	cout << " VString :: operator=(const char* ) >>" << endl;
    
	_size = strlen(ptr);
	delete[] this->_str;

	_str = new char[_size + 1];
	_assign(this->_str, ptr);
	cout << " << VString :: operator=(const char*) " << endl;
	return (*this);
	

}

VString::VString(VString&& src)
{
	cout << "move ctor : VString( const VString&& src) >>" << endl;
	cout << "array value : " << src << endl;
	this->_size = src._size;
	this->_str = src._str;

	src._str = nullptr;
	src._size = 0;
	cout << " << move ctor : VString( const VString&& src)" << endl;
}


#else
 VString& VString :: operator=(VString src)
{
	 
	// this is copy-swap idiom assignment operator
	cout << " VString :: operator=(VString --copy-swap) >>" << endl;
	// self assignment test
	if (this == &src)
		return (*this);
	using std::swap;
	//swap(*this, src); // using this causes infine recursion. swap again call operator=
	swap(this->_size,src._size);
	swap(this->_str, src._str);
	
	cout << " << VString :: operator=(VString -- copy-swap) " << endl;
	return (*this);
	

} 

#endif

ostream& operator<<(ostream& out, const VString& input)
{

	out << input._str;

	
	return out;
}

istream& operator>>(istream& in, VString& out)
{

	char ch[100];
	in.getline(ch, 100 ,'\n');
	out = ch;

	return in;
}

VString::~VString()
{
	cout << " ~VString() >>" << endl;
	delete[] _str;
	cout << " << ~VString()" << endl;
}


size_t VString:: size()
{
	return this->_size;
}

char& VString:: operator[](size_t index)
{
	//if (index < _size) throw exception;

	return this->_str[index];
   
}

