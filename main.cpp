#include <iostream>
#include "mystring.h"
using namespace std;

int main()
{
	cout << "CONSTRUCTORS:\n";
	MyString a1;
	cout << a1;
	cout << ' ' << a1.size() << ' ' << a1.capacity() << std::endl;

	MyString a2("Hello world!");
	cout << a2;
	cout << ' ' << a2.size() << ' ' << a2.capacity() << std::endl;
	//
	MyString a3({ 'h','e','l','l','o' });
	cout << a3;
	cout << ' ' << a3.size() << ' ' << a3.capacity() << std::endl;
	//
	std::string s = "hello";
	MyString a4(s);
	cout << a4;
	cout << ' ' << a4.size() << ' ' << a4.capacity() << std::endl;
	//
	MyString a5("hello", 4);
	cout << a5;
	cout << ' ' << a5.size() << ' ' << a5.capacity() << std::endl;
	//
	MyString a6(5, '!');
	cout << a6;
	cout << ' ' << a6.size() << ' ' << a6.capacity() << std::endl;
	//
	MyString a7("hello");
	MyString a8(a7);
	cout << a8;
	cout << ' ' << a8.size() << ' ' << a8.capacity() << std::endl;



	cout << "\nOPERATORS (+,=):\n";
	MyString s1("hel"), s2("lo"), s3;
	s3 = s1 + s2;
	cout << s1;
	cout << ' ';
	cout << s2;
	cout << ' ';
	cout << s3;
	cout << std::endl;

	//
	MyString s4("hel"), s5;
	s5 = s4 + "lo";
	cout << s4;
	cout << ' ';
	cout << s5;
	cout << endl;
	//
	MyString s6("hel"), s7;
	std::string s_x = "lo";
	s7 = s6 + s_x;
	cout << s6;
	cout << ' ';
	cout << s7;
	cout << endl;
	//
	MyString s9("hel"), s10("lo");
	s9 += s10;
	cout << s10;
	cout << ' ';
	cout << s9;
	cout << endl;
	//
	MyString s11("hel");
	std::string s12 = "lo";
	s11 += s12;
	cout << s11;
	cout << endl;
	//
	MyString s13;
	s13 = "hello";
	cout << s13;
	cout << endl;
	//
	MyString s14;
	std::string s15 = "hello";
	s14 = s15;
	cout << s14;
	cout << endl;
	//
	MyString s16;
	s16 = '!';
	cout << a3;
	cout << endl;



	cout << "\nOPERATOR INDEX INT:\n";
	MyString str1;
	str1 = "hello";
	std::cout << a4[2] << std::endl;



	cout << "\nLOGICAL OPERATORS:\n";
	MyString a, b;
	a = "abcd";
	b = "abce";
	std::cout << (a == b) << (a != b) << (a > b) << (a >= b) << (a < b) << (a <= b) << std::endl;





	cout << "\nSIZE():\n";
	MyString str2("Hello world!");
	cout << str2.size() << endl;;





	cout << "\nCAPACITY():\n";
	MyString str4("Hello world!");
	cout << str4.capacity() << endl;




	return EXIT_SUCCESS;
}