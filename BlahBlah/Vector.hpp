// Nikolay Stoyanov 2MI0600435

#pragma once

#include <cstdint>

#include "Constants.h"

template <typename T>
class Vector
{
private:
	T* elements;
	uint32_t _size;
	uint32_t _capacity;

	void freeDynamicMemory();
	void copyDynamicMemory(const Vector<T>& other);
	void reallocate();

public:
	Vector();
	Vector(uint32_t capacity);
	Vector(uint32_t size, T initialValue);
	Vector(const Vector& other);
	Vector& operator=(const Vector& other);
	~Vector();
	void assign(uint32_t count, const T& value);

	// Element access
	T& at(uint32_t pos);
	const T& at(uint32_t pos) const;
	T& operator[](uint32_t pos);
	const T& operator[](uint32_t pos) const;
	T& front();
	const T& front() const;
	T& back();
	const T& back() const;
	T* data();
	const T* data() const;

	// Capacity
	bool empty() const;
	uint32_t size() const;
	void reserve(uint32_t new_cap);
	uint32_t capacity() const;
	void shrink_to_fit();

	// Modifiers
	void clear();
	void insert(uint32_t pos, const T& value);
	void erase(uint32_t pos);
	void erase(uint32_t first, uint32_t last);
	void push_back(const T& value);
	void pop_back();
	void resize(uint32_t count);
	void resize(uint32_t count, const T& value);
	void swap(Vector<T>& other);

};

template <typename T>
void Vector<T>::freeDynamicMemory()
{
	this->_capacity = 0;
	this->_size = 0;
	delete[] elements;
}

template <typename T>
void Vector<T>::copyDynamicMemory(const Vector<T>& other)
{
	this->_size = other._size;
	_capacity = other._size;
	elements = new T[_capacity];

	for (uint32_t i = 0; i < other._size; i++)
	{
		elements[i] = other.elements[i];
	}
}

template <typename T>
void Vector<T>::reallocate()
{
	this->_capacity *= REALLOCATE_FACTOR;

	T* newElements = new T[this->_capacity];

	for (uint32_t i = 0; i < _size; i++)
	{
		newElements[i] = elements[i];
	}

	delete[] elements;
	elements = newElements;
}

template <typename T>
Vector<T>::Vector()
{
	elements = new T[1];
	_size = 0;
	_capacity = 1;
}

template <typename T>
Vector<T>::Vector(uint32_t capacity)
{
	if (capacity == 0)
	{
		throw std::exception("Cannot create vector with no capacity");
	}

	this->_capacity = capacity;
	elements = new T[capacity];
	_size = 0;
}

template <typename T>
Vector<T>::Vector(uint32_t size, T initialValue)
{
	this->_capacity = size == 0 ? 1 : size;

	this->_size = size;
	elements = new T[_capacity];

	for (uint32_t i = 0; i < _size; i++)
	{
		elements[i] = initialValue;
	}
}

template <typename T>
Vector<T>::Vector(const Vector<T>& other)
{
	copyDynamicMemory(other);
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
	if (this != &other)
	{
		freeDynamicMemory();
		copyDynamicMemory(other);
	}

	return *this;
}

template <typename T>
Vector<T>::~Vector()
{
	freeDynamicMemory();
}

template <typename T>
void Vector<T>::assign(uint32_t count, const T& value)
{
	if (count == 0)
	{
		throw std::invalid_argument("Cannot assign zero elements.");
	}

	freeDynamicMemory();

	this->_capacity = count;
	this->_size = count;
	elements = new T[count];

	for (uint32_t i = 0; i < count; i++)
	{
		elements[i] = value;
	}
}

// Element access
template <typename T>
T& Vector<T>::at(uint32_t pos)
{
	if (pos >= _size)
	{
		throw std::out_of_range("Position out of range.");
	}

	return elements[pos];
}

template <typename T>
const T& Vector<T>::at(uint32_t pos) const
{
	if (pos >= _size)
	{
		throw std::out_of_range("Position out of range.");
	}

	return elements[pos];
}

template <typename T>
T& Vector<T>::operator[](uint32_t pos)
{
	return elements[pos];
}

template <typename T>
const T& Vector<T>::operator[](uint32_t pos) const
{
	return elements[pos];
}

template <typename T>
T& Vector<T>::front()
{
	if (_size == 0)
	{
		throw std::out_of_range("Cannot access front of empty vector.");
	}

	return elements[0];
}

template <typename T>
const T& Vector<T>::front() const
{
	if (_size == 0)
	{
		throw std::out_of_range("Cannot access front of empty vector.");
	}

	return elements[0];
}

template <typename T>
T& Vector<T>::back()
{
	if (_size == 0)
	{
		throw std::out_of_range("Cannot access back of empty vector.");
	}

	return elements[_size - 1];
}

template <typename T>
const T& Vector<T>::back() const
{
	if (_size == 0)
	{
		throw std::out_of_range("Cannot access back of empty vector.");
	}

	return elements[_size - 1];
}

template <typename T>
T* Vector<T>::data()
{
	return elements;
}

template <typename T>
const T* Vector<T>::data() const
{
	return elements;
}

// Capacity
template <typename T>
bool Vector<T>::empty() const
{
	bool isEmpty = _size == 0;
	return isEmpty;
}

template <typename T>
uint32_t Vector<T>::size() const
{
	return _size;
}

template <typename T>
void Vector<T>::reserve(uint32_t new_cap)
{
	if (new_cap <= _capacity)
	{
		return;
	}

	T* newElements = new T[new_cap];

	for (uint32_t i = 0; i < _size; i++)
	{
		newElements[i] = elements[i];
	}

	delete[] elements;
	elements = newElements;
	_capacity = new_cap;
}

template <typename T>
uint32_t Vector<T>::capacity() const
{
	return _capacity;
}

template <typename T>
void Vector<T>::shrink_to_fit()
{
	if (_size == _capacity)
	{
		return;
	}

	T* newElements = new T[_size];

	for (uint32_t i = 0; i < _size; i++)
	{
		newElements[i] = elements[i];
	}

	delete[] elements;
	elements = newElements;
	_capacity = _size;
}

// Modifiers
template <typename T>
void Vector<T>::clear()
{
	_size = 0;
}

template <typename T>
void Vector<T>::insert(uint32_t pos, const T& value)
{
	if (pos > _size)
	{
		throw std::out_of_range("Insert position out of range.");
	}

	if (_size == _capacity)
	{
		reallocate();
	}

	for (uint32_t i = _size; i > pos; --i)
	{
		elements[i] = elements[i - 1];
	}

	elements[pos] = value;
	++_size;
}

template <typename T>
void Vector<T>::erase(uint32_t pos)
{
	if (pos >= _size)
	{
		throw std::out_of_range("Erase position out of range.");
	}

	for (uint32_t i = pos; i < _size - 1; i++)
	{
		elements[i] = elements[i + 1];
	}

	_size--;
}

template <typename T>
void Vector<T>::erase(uint32_t first, uint32_t last)
{
	if (first > last || last >= _size)
	{
		throw std::out_of_range("Invalid erase range.");
	}

	uint32_t rangeLength = last - first + 1;

	for (uint32_t i = last + 1; i < _size; i++)
	{
		elements[i - rangeLength] = elements[i];
	}

	_size -= rangeLength;
}

template <typename T>
void Vector<T>::push_back(const T& value)
{
	if (_size == _capacity)
	{
		reallocate();
	}

	elements[_size] = value;
	_size++;
}

template <typename T>
void Vector<T>::pop_back()
{
	if (_size == 0)
	{
		throw std::out_of_range("Cannot pop_back from empty vector.");
	}

	_size--;
}

template <typename T>
void Vector<T>::resize(uint32_t count)
{
	if (count == _size)
	{
		return;
	}

	if (count < _size)
	{
		_size = count;
		return;
	}

	if (count > _capacity)
	{
		reserve(count);
	}

	_size = count;
}

template <typename T>
void Vector<T>::resize(uint32_t count, const T& value)
{
	if (count == _size)
	{
		return;
	}

	if (count < _size)
	{
		_size = count;
		return;
	}

	if (count > _capacity)
	{
		reserve(count);
	}

	for (uint32_t i = _size; i < count; i++)
	{
		elements[i] = value;
	}

	_size = count;
}

template <typename T>
void Vector<T>::swap(Vector<T>& other)
{
	T* tempElements = elements;
	elements = other.elements;
	other.elements = tempElements;

	uint32_t tempSize = _size;
	_size = other._size;
	other._size = tempSize;

	uint32_t tempCapacity = _capacity;
	_capacity = other._capacity;
	other._capacity = tempCapacity;
}

// Operators
template <typename T>
bool operator==(const Vector<T>& lhs, const Vector<T>& rhs)
{
	uint32_t left_size = lhs.size();
	if (left_size != rhs.size())
		return false;

	for (uint32_t i = 0; i < left_size; ++i)
	{
		if (lhs[i] != rhs[i])
			return false;
	}

	return true;
}

template <typename T>
bool operator!=(const Vector<T>& lhs, const Vector<T>& rhs)
{
	uint32_t left_size = lhs.size();
	if (left_size != rhs.size())
		return true;

	for (uint32_t i = 0; i < left_size; ++i)
	{
		if (lhs[i] != rhs[i])
			return true;
	}

	return false;
}