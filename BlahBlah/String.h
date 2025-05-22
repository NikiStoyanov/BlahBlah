#pragma once
#include <cstdint>
#include <istream>

#include "Vector.hpp"

class String
{
private:
	char* text;
	uint32_t _size;
	uint32_t _capacity;

	void freeDynamicMemory();
	void copyDynamicMemory(const String& other);
	void reallocate();
public:
	String();
	String(uint32_t capacity);
	String(uint32_t size, char initialValue);
	String(const char* str);
	String(const String& other);
	String& operator=(const String& other);
	~String();
	void assign(uint32_t count, const char& value);
	void assign(const char* s);

	// Element access
	char& at(uint32_t pos);
	const char& at(uint32_t pos) const;
	char& operator[](uint32_t pos);
	const char& operator[](uint32_t pos) const;
	char& front();
	const char& front() const;
	char& back();
	const char& back() const;
	const char* data() const;
	const char* c_str() const;

	// Capacity
	bool empty() const;
	uint32_t size() const;
	uint32_t length() const;
	void reserve(uint32_t new_cap);
	uint32_t capacity() const;
	void shrink_to_fit();

	// Modifiers
	void clear();
	void insert(uint32_t pos, const char& value);
	void erase(uint32_t pos);
	void erase(uint32_t first, uint32_t last);
	void push_back(char ch);
	void pop_back();
	String& operator+=(const String& other);
	String& operator+=(char ch);
	uint32_t copy(char* dest, uint32_t count, uint32_t pos) const;
	void replace(uint32_t pos, uint32_t count, const String& str);
	void replace(uint32_t pos, uint32_t count, const char* str);
	void swap(String& other);

	// Search
	int32_t find(char ch, uint32_t pos = 0) const;
	int32_t find(const char* str, uint32_t pos = 0) const;
	int32_t find(const String& str, uint32_t pos = 0) const;
	int32_t rfind(char ch, uint32_t pos = 0) const;
	int32_t rfind(const char* str, uint32_t pos = 0) const;
	int32_t rfind(const String& str, uint32_t pos = 0) const;

	// Operations
	int32_t compare(const char* s) const;
	int32_t compare(const String& str) const;
	bool starts_with(const char* prefix) const;
	bool starts_with(const String& prefix) const;
	bool ends_with(const char* suffix) const;
	bool ends_with(const String& suffix) const;
	bool contains(const char* substring) const;
	bool contains(const String& substring) const;
	String substr(uint32_t pos = 0, uint32_t count = 0) const;

	Vector<String> split(char delimiter = ' ') const;
};

String operator+(const String& lhs, const String& rhs);

bool operator==(const String& lhs, const String& rhs);
bool operator!=(const String& lhs, const String& rhs);
bool operator<(const String& lhs, const String& rhs);
bool operator>(const String& lhs, const String& rhs);
bool operator<=(const String& lhs, const String& rhs);
bool operator>=(const String& lhs, const String& rhs);

std::ostream& operator<<(std::ostream& os, const String& str);
std::istream& operator>>(std::istream& is, String& str);

std::istream& getline(std::istream& is, String& str);
