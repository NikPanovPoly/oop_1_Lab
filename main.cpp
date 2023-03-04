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



	cout << "\nDATA():\n";
	MyString str_1("Hello world!");
	std::string s_1;
	s_1 = str_1.data();
	cout << s_1 << endl;



	cout << "\nSIZE():\n";
	MyString str2("Hello world!");
	cout << str2.size() << endl;;



	cout << "\nEMPTY():\n";
	MyString str3("Hello world!");
	cout << str3.empty() << endl;



	cout << "\nCAPACITY():\n";
	MyString str4("Hello world!");
	cout << str4.capacity() << endl;



	cout << "\nSHRINK_TO_FIT():\n";
	MyString str5("Hello world!");
	str5.erase(5, 6);
	cout << str5;
	cout << " ";
	cout << str5.size();
	cout << " ";
	cout << str5.capacity();
	cout << endl;
	str5.shrink_to_fit();
	cout << str5;
	cout << " ";
	cout << str5.size();
	cout << " ";
	cout << str5.capacity();
	cout << endl;



	cout << "\nCLEAR():\n";
	MyString str6("Hello world!");
	cout << str6;
	cout << endl;
	str6.clear();
	cout << str6;
	cout << endl;



	cout << "\nINSERT():\n";
	MyString st1 = "aaaaa";
	st1.insert(0, 1, '!');
	cout << st1;
	cout << endl;
	st1.insert(3, 2, '@');
	cout << st1;
	cout << endl;
	//
	MyString st2 = "aaaaa";
	st2.insert(1, "@@@@@");
	cout << st2;
	cout << endl;
	//
	MyString st3 = "aaaaa";
	st3.insert(1, "@@@@@", 2);
	cout << st3;
	cout << endl;
	//
	MyString st4 = "aaaaa";
	std::string st5 = "@@@@@";
	st4.insert(1, st5);
	cout << st4;
	cout << endl;
	//
	MyString st6 = "aaaaa";
	std::string st7 = "@@@@@";
	st6.insert(1, st7, 2);
	cout << st6;
	cout << endl;



	cout << "\nERASE():\n";
	MyString stt1("Hello world!");
	stt1.erase(5, 6);
	cout << stt1;
	cout << endl;



	cout << "\nAPPEND():\n";
	MyString string_1;
	string_1.clear();
	string_1.append(3, '!');
	cout << string_1;
	cout << endl;
	string_1.append(3, '@');
	cout << string_1;
	cout << endl;
	/*
	MyString S2;
	S2.clear();
	S2.append("Hello ");
	cout << S2;
	cout << endl;
	S2.append("world");
	cout << S2;
	cout << endl;
	//
	MyString S3;
	S3.clear();
	S3.append("Hello world", 0, 6);
	cout << S3;
	cout << endl;
	S3.append("Hello world", 6, 5);
	cout << S3;
	cout << endl;
	//
	MyString S4;
	std::string S5 = "Hello ", S6 = "world";
	S4.clear();
	S4.append(S5);
	cout << S4;
	cout << endl;
	S4.append(S6);
	cout << S4;
	cout << endl;
	//
	MyString S7;
	std::string S8 = "Hello world";
	S7.clear();
	S7.append(S8, 0, 6);
	cout << S7;
	cout << endl;
	S7.append(S8, 6, 5);
	cout << S7;
	cout << endl;
	*/



	cout << "\nREPLACE():\n";
	MyString ST1 = "hello amazing world";
	ST1.replace(6, 7, "wonderful");
	cout << ST1;
	cout << endl;
	//
	MyString ST2 = "hello amazing world";
	std::string ST3 = "wonderful";
	ST2.replace(6, 7, ST3);
	cout << ST2;
	cout << endl;



	cout << "\nSUBSTR():\n";
	MyString STR1 = "hello amazing world", STR2;
	STR2 = STR1.substr(6);
	cout << STR2;
	cout << endl;
	//
	MyString STR3 = "hello amazing world", STR4;
	STR4 = STR3.substr(6, 7);
	cout << STR4;
	cout << endl;



	cout << "\nFIND():\n";
	MyString string1 = "hello amazing world amazing";
	int i1;
	i1 = string1.find("amazing");
	cout << i1 << endl;
	//
	MyString string2 = "hello amazing world amazing";
	int i2;
	i2 = string2.find("amazing", 7);
	cout << i2 << endl;
	//
	MyString string3 = "hello amazing world amazing";
	int i3;
	std::string s__3 = "amazing";
	i3 = string3.find(s__3);
	cout << i3 << endl;
	//
	MyString string4 = "hello amazing world amazing";
	int i4;
	std::string s__4 = "amazing";
	i4 = string4.find(s__4, 7);
	cout << i4 << endl;








	return EXIT_SUCCESS;
}