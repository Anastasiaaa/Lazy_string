// Main.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdio.h>
#include <string>
#include <cstring>
#include <iostream>
#include <windows.h>
#include "lazy_string.h"


//int main()
void main()
{
//	lazy_string string1 = "Hello!";
//	std::cout << "string1: " << string1.c_str() << "size: " << string1.size() << std::endl;

	std::string str_1 = "Nastia!";
	lazy_string* string2 = new lazy_string(str_1);
	std::cout << "string2: " << string2->c_str() << " size: " << string2->size() << std::endl;
	
	string2->clear();
	std::cout << "new string2: " << string2->c_str() << " new size: " << string2->size() << std::endl;

	char* str_char = "one";
	lazy_string* string3 = new lazy_string(str_char);
	std::cout << "string3: " << string3->c_str() << " size: " << string3->size() << std::endl;

	lazy_string string4 = "Dima!";
	lazy_string string5 = string4;
	std::cout << "string5: " << string5.c_str() << " size: " << string5.size() << std::endl;

	system("pause");
//	return 0;
}

