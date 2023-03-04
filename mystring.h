#ifndef _MYSTRING_H_
#define _MYSTRING_H_
#include <string.h>
#include <iostream>
#include <Initializer_list>
#include <string>


class MyString
{
	char* ptr;
	char* substr_f;
	int length_f;
	int capacity_f;
	void EqSupliment(const int len, const char* str);
	void Resize(const int newsize); // & save data
	void InsertSupliment(const int idx, const int len, const char* str);
	MyString PlusSupliment(const char* str, const int len);
	char* CharStrConstructor(const int count, const int chr);
	MyString& PlusEqSupliment(const char* str, const int len);
	int FindSupliment(const char* str, const int index);
	inline void Init(char* p, int len, int cap);


public:
	MyString operator+(MyString& str);
	MyString operator+(std::string str);
	MyString operator+(const char* str);
	MyString operator=(const std::string str);
	MyString operator=(const MyString& newstr);
	MyString operator=(const char* charstr);
	MyString operator=(const char chr);
	MyString& operator+=(MyString& newstr);
	MyString& operator+=(const char* newstr);
	MyString& operator+=(std::string newstr);
	bool operator==(MyString&) const;
	bool operator<(MyString&) const;
	bool operator>(MyString&) const;
	bool operator>=(MyString&) const;
	bool operator<=(MyString&) const;
	bool operator!=(MyString&) const;
	char& operator[](const int n);
	const char* c_str() const;
	const char* data() const;
	int length() const;
	int capacity() const;
	bool empty() const;
	void shrink_to_fit();
	void clear();
	void insert(const int idx, const int count, const char chr);
	void insert(const int idx, const char* str);
	void insert(const int idx, std::string str);
	void insert(const int idx, const char* str, const int count);
	void insert(const int idx, std::string str, const int count);
	void erase(const int index, const int count);
	
	
	
	
	MyString();
	MyString(std::string);
	MyString(const char* newstr, size_t num);
	MyString(size_t num, char chr);
	MyString(std::initializer_list<char>);
	MyString(const char* newstr);
	MyString(const MyString& newstr);
	int size(void) const
	{
		return this->length_f;
	}
	~MyString()
	{
		delete[] ptr;
		delete[] substr_f;
	}
	friend void operator<<(std::ostream& stream, MyString& str);
	friend void operator>>(std::istream& stream, MyString& str);
};

#endif