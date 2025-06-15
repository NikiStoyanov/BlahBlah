// Nikolay Stoyanov 2MI0600435

#include <iostream>

#include "String.h"

namespace Constants
{
	constexpr uint16_t REALLOCATE_FACTOR = 2;
	constexpr char TERMINATE_SYMBOL = '\0';
}

uint32_t get_strlen(const char* str)
{
	if (!str) return 0;

	uint32_t length = 0;
	while (str[length] != '\0')
	{
		length++;
	}

	return length;
}

void String::freeDynamicMemory()
{
	this->_capacity = 0;
	this->_size = 0;
	delete[] text;
}

void String::copyDynamicMemory(const String& other)
{
	_size = other._size;
	_capacity = other._size + 1;
	text = new char[_capacity];

	for (uint32_t i = 0; i < other._size; i++)
	{
		text[i] = other.text[i];
	}

	text[_size] = Constants::TERMINATE_SYMBOL;
}

void String::reallocate()
{
	this->_capacity *= Constants::REALLOCATE_FACTOR;

	char* newText = new char[this->_capacity];

	for (uint32_t i = 0; i < _size; i++)
	{
		newText[i] = text[i];
	}

	newText[_size] = Constants::TERMINATE_SYMBOL;

	delete[] text;
	text = newText;
}

String::String()
{
	_size = 0;
	_capacity = 1;
	text = new char[_capacity];

	text[0] = Constants::TERMINATE_SYMBOL;
}

String::String(uint32_t capacity)
{
	if (capacity == 0)
	{
		throw std::exception("Cannot create vector with no capacity");
	}

	_size = 0;
	_capacity = capacity;
	text = new char[capacity];

	text[0] = Constants::TERMINATE_SYMBOL;
}

String::String(uint32_t size, char initialValue)
{
	_capacity = size + 1;
	_size = size;
	text = new char[_capacity];

	for (uint32_t i = 0; i < _size; i++)
	{
		text[i] = initialValue;
	}

	text[_size] = Constants::TERMINATE_SYMBOL;
}

String::String(const char* str)
{
	if (!str)
	{
		_size = 0;
		_capacity = 1;
		text = new char[_capacity];
		text[0] = Constants::TERMINATE_SYMBOL;
		return;
	}

	_size = get_strlen(str);
	_capacity = _size + 1;
	text = new char[_capacity];

	for (uint32_t i = 0; i < _size; i++)
	{
		text[i] = str[i];
	}

	text[_size] = Constants::TERMINATE_SYMBOL;
}

String::String(const String& other)
{
	copyDynamicMemory(other);
}

String& String::operator=(const String& other)
{
	if (this != &other)
	{
		freeDynamicMemory();
		copyDynamicMemory(other);
	}

	return *this;
}

String::~String()
{
	freeDynamicMemory();
}

void String::assign(uint32_t count, const char& value)
{
	delete[] text;

	_size = count;
	_capacity = count + 1;
	text = new char[_capacity];

	for (uint32_t i = 0; i < count; i++)
	{
		text[i] = value;
	}

	text[_size] = Constants::TERMINATE_SYMBOL;
}

void String::assign(const char* s)
{
	if (!s)
	{
		_size = 0;
		_capacity = 1;
		text = new char[_capacity];
		text[0] = Constants::TERMINATE_SYMBOL;
		return;
	}

	delete[] text;

	_size = get_strlen(s);
	_capacity = _size + 1;
	text = new char[_capacity];

	for (uint32_t i = 0; i < _size; i++)
	{
		text[i] = s[i];
	}

	text[_size] = Constants::TERMINATE_SYMBOL;
}

char& String::at(uint32_t pos)
{
	if (pos >= _size)
	{
		throw std::out_of_range("String::at - index out of range");
	}

	return text[pos];
}

const char& String::at(uint32_t pos) const
{
	if (pos >= _size)
	{
		throw std::out_of_range("String::at - index out of range");
	}

	return text[pos];
}

char& String::operator[](uint32_t pos)
{
	return text[pos];
}

const char& String::operator[](uint32_t pos) const
{
	return text[pos];
}

char& String::front()
{
	if (_size == 0)
	{
		throw std::out_of_range("String::front - empty string");
	}

	return text[0];
}

const char& String::front() const
{
	if (_size == 0)
	{
		throw std::out_of_range("String::front - empty string");
	}

	return text[0];
}

char& String::back()
{
	if (_size == 0)
	{
		throw std::out_of_range("String::back - empty string");
	}

	return text[_size - 1];
}

const char& String::back() const
{
	if (_size == 0)
	{
		throw std::out_of_range("String::back - empty string");
	}

	return text[_size - 1];
}

const char* String::data() const
{
	return text;
}

const char* String::c_str() const
{
	return text;
}

bool String::empty() const
{
	bool isEmpty = _size == 0;
	return isEmpty;
}

uint32_t String::size() const
{
	return _size;
}

uint32_t String::length() const
{
	return _size;
}

void String::reserve(uint32_t new_cap)
{
	if (new_cap <= _capacity) {
		return;
	}

	char* newText = new char[new_cap];

	for (uint32_t i = 0; i < _size; i++)
	{
		newText[i] = text[i];
	}

	delete[] text;
	text = newText;
	_capacity = new_cap;

	text[_size] = Constants::TERMINATE_SYMBOL;
}

uint32_t String::capacity() const
{
	return _capacity;
}

void String::shrink_to_fit()
{
	if (_size == _capacity)
	{
		return;
	}

	char* newText = new char[_size + 1];

	for (uint32_t i = 0; i < _size; i++)
	{
		newText[i] = text[i];
	}

	delete[] text;
	text = newText;
	_capacity = _size + 1;

	text[_size] = Constants::TERMINATE_SYMBOL;
}

void String::clear()
{
	_size = 0;
	text[0] = Constants::TERMINATE_SYMBOL;
}

void String::insert(uint32_t pos, const char& value)
{
	if (pos > _size)
	{
		throw std::out_of_range("String::insert - position out of range");
	}

	if (_size + 1 == _capacity)
	{
		reallocate();
	}

	for (uint32_t i = _size; i > pos; i--)
	{
		text[i] = text[i - 1];
	}

	text[pos] = value;

	_size++;
	text[_size] = Constants::TERMINATE_SYMBOL;
}

void String::erase(uint32_t pos)
{
	if (pos >= _size)
	{
		throw std::out_of_range("String::erase - index out of range");
	}

	for (uint32_t i = pos; i < _size - 1; i++)
	{
		text[i] = text[i + 1];
	}

	_size--;
	text[_size] = Constants::TERMINATE_SYMBOL;
}

void String::erase(uint32_t first, uint32_t last)
{
	if (first > last || last >= _size)
	{
		throw std::out_of_range("String::erase - invalid range");
	}

	uint32_t rangeLength = last - first + 1;

	for (uint32_t i = last + 1; i < _size; i++)
	{
		text[i - rangeLength] = text[i];
	}

	_size -= rangeLength;
	text[_size] = Constants::TERMINATE_SYMBOL;
}

void String::push_back(char ch)
{
	if (_size + 1 == _capacity)
	{
		reallocate();
	}

	text[_size] = ch;
	_size++;
	text[_size] = Constants::TERMINATE_SYMBOL;
}

void String::pop_back()
{
	if (_size == 0)
	{
		throw std::out_of_range("Cannot pop_back from empty string.");
	}

	_size--;
	text[_size] = Constants::TERMINATE_SYMBOL;
}

String& String::operator+=(const String& other)
{
	if (_size + other._size + 1 > _capacity)
	{
		reserve(_size + other._size + 1);
	}

	for (uint32_t i = 0; i < other._size; ++i)
	{
		text[_size + i] = other.text[i];
	}

	_size += other._size;
	text[_size] = Constants::TERMINATE_SYMBOL;

	return *this;
}

String& String::operator+=(char ch)
{
	if (_size + 1 == _capacity)
	{
		reallocate();
	}

	text[_size] = ch;
	_size++;

	text[_size] = Constants::TERMINATE_SYMBOL;

	return *this;
}

uint32_t String::copy(char* dest, uint32_t count, uint32_t pos) const
{
	if (pos >= _size)
	{
		throw std::out_of_range("String::copy - position out of range");
	}

	uint32_t copyCount = std::min(count, _size - pos);

	for (uint32_t i = 0; i < copyCount; ++i)
	{
		dest[i] = text[pos + i];
	}

	return copyCount;
}

void String::replace(uint32_t pos, uint32_t count, const String& str)
{
	if (pos > _size)
	{
		throw std::out_of_range("String::replace - position out of range");
	}

	if (pos + count > _size)
	{
		count = _size - pos;
	}

	uint32_t newSize = pos + count;

	if (newSize + 1 > _capacity)
	{
		reserve(newSize + 1);
	}

	for (uint32_t i = 0; i < str.length(); ++i)
	{
		text[pos + i] = str[i];
	}

	_size = newSize;
	text[_size] = Constants::TERMINATE_SYMBOL;
}

void String::replace(uint32_t pos, uint32_t count, const char* str)
{
	if (!str) {
		throw std::invalid_argument("String::replace - null pointer");
	}

	if (pos > _size) {
		throw std::out_of_range("String::replace - position out of range");
	}

	if (pos + count > _size) {
		count = _size - pos;
	}

	uint32_t strLength = get_strlen(str);
	uint32_t newSize = pos + count;

	if (newSize + 1 > _capacity)
	{
		reserve(newSize + 1);
	}

	for (uint32_t i = pos; i < newSize; i++)
	{
		text[pos + i] = str[i];
	}

	_size = newSize;
	text[_size] = Constants::TERMINATE_SYMBOL;
}

void String::swap(String& other)
{
	uint32_t tempSize = _size;
	_size = other._size;
	other._size = tempSize;

	uint32_t tempCapacity = _capacity;
	_capacity = other._capacity;
	other._capacity = tempCapacity;

	char* tempText = text;
	text = other.text;
	other.text = tempText;
}

// Search
int32_t String::find(char ch, uint32_t pos) const
{
	if (pos >= _size)
	{
		return -1;
	}

	for (uint32_t i = pos; i < _size; i++)
	{
		if (text[i] == ch)
		{
			return i;
		}
	}

	return -1;
}

int32_t String::find(const char* str, uint32_t pos) const
{
	if (!str)
	{
		throw std::invalid_argument("String::find - null pointer");
	}

	uint32_t len = get_strlen(str);
	if (len == 0 || len > _size || pos > _size - len)
	{
		return -1;
	}

	for (uint32_t i = pos; i <= _size - len; ++i)
	{
		bool match = true;
		for (uint32_t j = 0; j < len; ++j)
		{
			if (text[i + j] != str[j])
			{
				match = false;
				break;
			}
		}

		if (match)
		{
			return i;
		}
	}

	return -1;
}

int32_t String::find(const String& str, uint32_t pos) const
{
	return find(str.c_str(), pos);
}

int32_t String::rfind(char ch, uint32_t pos) const
{
	if (_size == 0)
	{
		return -1;
	}

	if (pos >= _size)
	{
		pos = _size - 1;
	}

	for (int32_t i = pos; i >= 0; i--)
	{
		if (text[i] == ch)
		{
			return i;
		}
	}

	return -1;
}

int32_t String::rfind(const char* str, uint32_t pos) const
{
	if (!str)
	{
		throw std::invalid_argument("String::rfind - null pointer");
	}

	uint32_t strLen = get_strlen(str);
	if (strLen == 0 || strLen > _size)
	{
		return -1;
	}


	if (pos > _size - strLen)
	{
		pos = _size - strLen;
	}


	for (int32_t i = pos; i >= 0; i--)
	{
		bool match = true;
		for (uint32_t j = 0; j < strLen; j++)
		{
			if (text[i + j] != str[j])
			{
				match = false;
				break;
			}
		}

		if (match)
		{
			return i;
		}
	}

	return -1;
}

int32_t String::rfind(const String& str, uint32_t pos) const
{
	return rfind(str.c_str(), pos);
}

// Operations
int String::compare(const char* s) const
{
	if (!s)
	{
		throw std::invalid_argument("String::compare - null pointer");
	}

	uint32_t i = 0;
	while (i < _size && s[i] != '\0')
	{
		if (text[i] != s[i])
		{
			return (text[i] - s[i]);
		}

		i++;
	}

	if (i < _size)
	{
		return 1;
	}


	if (s[i] != '\0')
	{
		return -1;
	}


	return 0;
}

int String::compare(const String& str) const
{
	return compare(str.c_str());
}

bool String::starts_with(const char* prefix) const
{
	if (!prefix)
	{
		return false;
	}

	uint32_t i = 0;
	while (prefix[i] != '\0')
	{
		if (i >= _size || text[i] != prefix[i])
		{
			return false;
		}

		i++;
	}

	return true;
}

bool String::starts_with(const String& prefix) const
{
	return starts_with(prefix.c_str());
}

bool String::ends_with(const char* suffix) const
{
	if (!suffix)
	{
		return false;
	}

	uint32_t suffixLen = get_strlen(suffix);
	if (suffixLen > _size)
	{
		return false;
	}

	uint32_t offset = _size - suffixLen;
	for (uint32_t i = 0; i < suffixLen; ++i)
	{
		if (text[offset + i] != suffix[i])
		{
			return false;
		}
	}

	return true;
}

bool String::ends_with(const String& suffix) const
{
	return ends_with(suffix.c_str());
}

bool String::contains(const char* substring) const
{
	if (!substring)
	{
		return false;
	}

	uint32_t substrLen = get_strlen(substring);

	if (substrLen == 0 || substrLen > _size)
	{
		return false;
	}

	for (uint32_t i = 0; i <= _size - substrLen; ++i)
	{
		uint32_t j = 0;
		while (j < substrLen && text[i + j] == substring[j])
		{
			++j;
		}

		if (j == substrLen)
		{
			return true;
		}
	}

	return false;
}

bool String::contains(const String& substring) const
{
	return contains(substring.c_str());
}

String String::substr(uint32_t pos, uint32_t count) const
{
	if (pos > _size)
	{
		throw std::out_of_range("String::substr - position out of range");
	}

	if (count == 0 || pos + count > _size)
	{
		count = _size - pos;
	}

	String result(count, Constants::TERMINATE_SYMBOL);

	for (uint32_t i = 0; i < count; i++)
	{
		result[i] = text[pos + i];
	}

	result._size = count;
	result.text[count] = Constants::TERMINATE_SYMBOL;

	return result;
}

Vector<String> String::split(char delimiter) const
{
	Vector<String> result;
	String current;

	uint32_t size = this->size();
	for (uint32_t i = 0; i < size; i++) 
	{
		char c = this->at(i);

		if (c == delimiter) 
		{
			if (!current.empty()) 
			{
				result.push_back(current);
				current.clear();
			}
		}
		else 
		{
			current += c;
		}
	}

	if (!current.empty()) 
	{
		result.push_back(current);
	}

	return result;
}

void String::reverse()
{
	uint32_t halfLength = _size / 2;

	for (uint32_t i = 0; i < halfLength; i++)
	{
		char temp = text[i];
		text[i] = text[_size - 1 - i];
		text[_size - 1 - i] = temp;
	}
}

String operator+(const String& lhs, const String& rhs)
{
	String result;
	result.reserve(lhs.size() + rhs.size() + 1);

	for (uint32_t i = 0; i < lhs.size(); ++i) {
		result.push_back(lhs[i]);
	}

	for (uint32_t i = 0; i < rhs.size(); ++i) {
		result.push_back(rhs[i]);
	}

	return result;
}

bool operator==(const String& lhs, const String& rhs)
{
	if (lhs.size() != rhs.size())
	{
		return false;
	}

	for (uint32_t i = 0; i < lhs.size(); ++i) {
		if (lhs[i] != rhs[i]) {
			return false;
		}
	}

	return true;
}

bool operator!=(const String& lhs, const String& rhs)
{
	return !(lhs == rhs);
}

bool operator<(const String& lhs, const String& rhs)
{
	uint32_t minSize = lhs.size() < rhs.size() ? lhs.size() : rhs.size();

	for (uint32_t i = 0; i < minSize; ++i) {
		if (lhs[i] < rhs[i]) return true;
		if (lhs[i] > rhs[i]) return false;
	}

	return lhs.size() < rhs.size();
}

bool operator>(const String& lhs, const String& rhs)
{
	return rhs < lhs;
}

bool operator<=(const String& lhs, const String& rhs)
{
	return !(rhs < lhs);
}

bool operator>=(const String& lhs, const String& rhs)
{
	return !(lhs < rhs);
}

std::ostream& operator<<(std::ostream& os, const String& str)
{
	os << str.c_str();

	return os;
}

std::istream& operator>>(std::istream& is, String& str)
{
	std::string input;
	is >> input;
	str.assign(input.c_str());

	return is;
}

std::istream& getline(std::istream& is, String& str)
{
	str.clear();

	char ch;
	while (is.get(ch)) 
	{
		if (ch == '\n')
		{
			break;
		}

		str.push_back(ch);
	}

	return is;
}