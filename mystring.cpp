#define _CRT_SECURE_NO_WARNINGS
#include "mystring.h"

inline void MyString::Init(char* p, int len, int cap)
{
	this->substr_f = NULL;
	ptr = p;
	length_f = len;
	capacity_f = cap;
}

MyString::MyString(size_t num, char chr)
{
	Init(new char[num + 1]{ 0 }, num, num + 1);
	for (int i = 0; i < num; ++i)
		ptr[i] = chr;
}

MyString::MyString(const char* newstr, size_t num)
{
	Init(new char[num + 1]{ 0 }, num, num + 1);
	strncpy(ptr, newstr, num);
}

MyString::MyString(std::string str) : MyString(str.c_str(), str.size()) { }

MyString::MyString()
{
	Init(NULL, 0, 0);
}

MyString::MyString(std::initializer_list<char> list)
{
	int i = -1;
	Init(new char[list.size() + 1], list.size(), list.size() + 1);
	for (auto chr : list)
	{
		this->ptr[++i] = chr;
	}
	this->ptr[this->length_f] = '\0';
}

MyString::MyString(const char* newstr) : MyString(newstr, strlen(newstr)) { }

MyString::MyString(const MyString & newstr) : MyString(newstr.ptr, newstr.length_f) { }

void MyString::shrink_to_fit()
{
	Resize(strlen(this->ptr) + 1);
}

void MyString::clear()
{
	if (this->capacity_f)
		this->ptr[0] = '\0';
	this->length_f = 0;
}

void MyString::Resize(const int newsize)
{
	char* tmp = new char[newsize];
	strcpy(tmp, this->ptr);
	delete[] this->ptr;
	this->ptr = tmp;
	this->capacity_f = newsize;
}

void MyString::InsertSupliment(const int idx, const int len, const char* str)
{
	if (idx > this->length_f || idx < 0)
		return;
	if (len + 1 + this->length_f > this->capacity_f)
		Resize(len + 1 + this->length_f);
	for (int i = len + this->length_f - 1, j = this->length_f - 1; j >= idx; i--, j--)
	{
		this->ptr[i] = this->ptr[j];
	}
	this->ptr[len + this->length_f] = 0;
	strncpy(&this->ptr[idx], str, len);
	this->length_f += len;
}

void MyString::insert(const int idx, const char* str)
{
	InsertSupliment(idx, strlen(str), str);
}

void MyString::insert(const int idx, std::string str)
{
	InsertSupliment(idx, str.size(), str.c_str());
}

void MyString::insert(const int idx, std::string str, const int count)
{
	insert(idx, str.c_str(), count);
}

void MyString::insert(const int idx, const char* str, const int count)
{
	char* newstr = new char[count + 1]{ 0 };
	if (count > strlen(str))
		return;
	strncpy(newstr, str, count);
	InsertSupliment(idx, count, newstr);
	delete[] newstr;
}

char* MyString::CharStrConstructor(const int count, const int chr)
{
	char* newstr = new char[count + 1];
	memset(newstr, chr, count);
	newstr[count] = '\0';
	return newstr;
}

void MyString::insert(const int idx, const int count, const char chr)
{
	char* newstr = CharStrConstructor(count, chr);
	InsertSupliment(idx, count, newstr);
	delete[] newstr;
}

void MyString::erase(const int index, const int count)
{
	if (index < 0 || index > this->length_f - 1 || count < 0 || index + count > this->length_f)
		return;
	for (int i = index, j = index + count; j <= this->length_f; ++i, ++j)
		this->ptr[i] = this->ptr[j];
	this->length_f -= count;
}


int MyString::FindSupliment(const char* str, const int index)
{
	if (index < 0 || index > this->length_f - 1)
		return -1;
	char* ptr = strstr(this->ptr + index, str);
	return ptr ? (int)(ptr - this->ptr) : -1;
}



void MyString::EqSupliment(const int len, const char* str)
{
	if (len + 1 > this->capacity_f || !this->ptr)
	{
		delete[] this->ptr;
		Init(new char[strlen(str) + 1], strlen(str), strlen(str) + 1);
	}
	this->length_f = len;
	strcpy(this->ptr, str);
}

MyString MyString::operator=(const char chr)
{
	char newstr[2] = { 0, 0 };
	newstr[0] = chr;
	EqSupliment(1, newstr);
	return *this;
}

MyString MyString::operator=(const MyString & newstr)
{
	EqSupliment(newstr.length_f, newstr.ptr);
	return *this;
}

MyString MyString::operator=(const char* charstr)
{
	EqSupliment(strlen(charstr), charstr);
	return *this;
}

MyString MyString::operator=(std::string str)
{
	EqSupliment(str.size(), str.c_str());
	return *this;
}

MyString MyString::PlusSupliment(const char* str, const int len)
{
	MyString tmp;
	tmp.Init(new char[this->length_f + len + 1], this->length_f + len, this->length_f + len + 1);
	strcpy(tmp.ptr, this->ptr);
	strcat(tmp.ptr, str);
	return tmp;
}

MyString MyString::operator+(std::string str)
{
	return PlusSupliment(str.c_str(), str.size());
}

MyString MyString::operator+(const char* str)
{
	return PlusSupliment(str, strlen(str));
}

MyString MyString::operator+(MyString & str)
{
	return PlusSupliment(str.ptr, str.length_f);
}

MyString& MyString::PlusEqSupliment(const char* str, const int len)
{
	if (this->length_f + len + 1 > this->capacity_f || !this->ptr)
	{
		char* newptr = new char[this->length_f + len + 1];
		this->capacity_f = this->length_f + len + 1;
		strcpy(newptr, this->ptr);
		delete[] this->ptr;
		this->ptr = newptr;
	}
	strcat(this->ptr, str);
	this->length_f += len;
	return *this;
}

MyString& MyString::operator+=(MyString & str)
{
	return PlusEqSupliment(str.ptr, str.length_f);
}

MyString& MyString::operator+=(const char* newstr)
{
	return PlusEqSupliment(newstr, strlen(newstr));
}

MyString& MyString::operator+=(std::string newstr)
{
	return PlusEqSupliment(newstr.c_str(), newstr.size());
}

bool MyString::operator==(MyString & str) const
{
	return !strcmp(this->ptr, str.ptr);
}

bool MyString::operator!=(MyString & str) const
{
	return strcmp(this->ptr, str.ptr);
}

bool MyString::operator<(MyString & str) const
{
	return strcmp(this->ptr, str.ptr) < 0 ? true : false;
}

bool MyString::operator>(MyString & str) const
{
	return strcmp(this->ptr, str.ptr) > 0 ? true : false;
}

bool MyString::operator>=(MyString & str) const
{
	return strcmp(this->ptr, str.ptr) >= 0 ? true : false;
}

bool MyString::operator<=(MyString & str) const
{
	return strcmp(this->ptr, str.ptr) <= 0 ? true : false;
}

char& MyString::operator[](const int n)
{
	return this->ptr[n];
}

const char* MyString::c_str() const
{
	return this->ptr;
}

const char* MyString::data() const
{
	return this->ptr;
}

int MyString::length() const
{
	return this->length_f;
}

bool MyString::empty() const
{
	return this->length_f ? false : true;
}

int MyString::capacity() const
{
	return this->capacity_f;
}


void operator<<(std::ostream & stream, MyString & str)
{
	if (str.ptr)
		stream << str.ptr;
}

void operator>>(std::istream & stream, MyString & str)
{
	int i = 0;
	char chr = 'a';
	if (!str.capacity_f)
		str.Init(new char[10], 0, 10);
	do
	{
		stream.get(chr);
		chr = chr == ' ' || chr == '\n' ? chr = 0 : chr;
		if (i + 2 >= str.capacity_f)
			str.Resize(str.capacity_f + 16);
		str.ptr[i++] = chr;
	} while (chr);
	str.length_f = i - 1;
}
