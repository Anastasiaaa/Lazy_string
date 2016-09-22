#include "stdafx.h"
#include "lazy_string.h"

//#define _CRT_NONSTDC_NO_WARNINGS
//#pragma warning(disable : 4996)

lazy_string::lazy_string() : my_size(0), l_string(new char[0])
{
}


lazy_string::~lazy_string()
{
	delete[] l_string;
	size_t size_del = std::strlen(l_string);
	my_size = 0;
}

lazy_string::lazy_string(const char* str_ch) : my_size(std::strlen(str_ch) + 1), l_string(new char[my_size])
{
	std::strncpy(l_string, str_ch, my_size);
}

lazy_string::lazy_string(const std::string &str) : my_size(str.size() + 1), l_string(new char[my_size]) {
	std::copy(str.begin(), str.end(), l_string);
	l_string[str.size()] = '\0';
}

/*lazy_string::lazy_string(char symbol) {
	l_string = new char(symbol);
	my_size = std::strlen(l_string) + 1;
	l_string[my_size] = '\0';
}*/

lazy_string::lazy_string(const lazy_string& copy_str) {
	l_string = new char[copy_str.my_size];
	std::strncpy(l_string, copy_str.l_string, copy_str.my_size);
	my_size = copy_str.my_size;
}

char* lazy_string::c_str() const {
	return l_string;
}

void lazy_string::clear() {
	l_string[0] = '\0';
	my_size = std::strlen(l_string);
}

size_t lazy_string::size() const {
	return my_size;
}

lazy_string& lazy_string::operator=(const lazy_string& other) {
	if (this != &other) {
		lazy_string* tmp;
		tmp = new lazy_string(other);
		swap(*this, *tmp);
		delete tmp;
	}
	return *this;
}

void swap(lazy_string& one, lazy_string& two) {
	std::swap(one.l_string, two.l_string);
	std::swap(one.my_size, two.my_size);
}