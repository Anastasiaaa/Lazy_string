#pragma once
//#define _CRT_SECURE_NO_WARNINGS
#include <string>

class lazy_string
{
public:
	lazy_string();										
	~lazy_string();										
	lazy_string(const char*);							// constructor for symbols
	lazy_string(const std::string&);					// constructor for string
//	lazy_string(char);									// may be don't need

	lazy_string(const lazy_string&);					// copy constructor
	lazy_string& operator=(const lazy_string&);			//copy assignment operator
	lazy_string(lazy_string&&) noexcept;							//move constructor
	lazy_string& operator=(lazy_string&&);				//move assignment operator

	void clear();										// clean of string
	char* c_str() const;								// convert lazy_string to const char* () This method must return pointer to an array that contains of characters and null - symbol
	size_t size() const;								// return size of user's string
	friend void swap(lazy_string&, lazy_string&);
	

private:
	size_t my_size;
	char* l_string = nullptr;
};

