/*
Gary Tou
Program 7: ArrayList<E>
5/26/2021
*/

#pragma once

#include <string>
#include <stdexcept>

template <typename T>
class ArrayList {

public:
	ArrayList();
	ArrayList(int capacity);

	int size();
	T& get(int index);
	std::string to_string();
	int indexOf(T value);
	bool isEmpty();
	bool contains(T value);
	void add(T value);
	void add(int index, T value);
	void remove(int index);
	void set(int index, T value);
	void clear();
	void addAll(ArrayList<T> other);
	ArrayList<T>& operator=(const ArrayList<T>& other);

private:
	T* elementData;
	int mSize;

	const static int DEFAULT_CAPACITY = 10;

	void ensureCapacity(int capacity);
	void checkIndex(int index);
};

template <typename T>
ArrayList<T>::ArrayList() {
	elementData = new T[DEFAULT_CAPACITY];
	mSize = 0;
}

template <typename T>
ArrayList<T>::ArrayList(int capacity) {
	if (capacity < 0) {
		throw std::invalid_argument("capacity: " + capacity);
	}
	elementData = new T[capacity];
	mSize = 0;
}

template <typename T>
int ArrayList<T>::size() {
	return mSize;
}

template <typename T>
T& ArrayList<T>::get(int index) {
	checkIndex(index);
	return elementData[index];
}

template <typename T>
std::string ArrayList<T>::to_string() {
	if (mSize == 0) {
		return "[]";
	}
	else {
		std::string result = "[" + std::to_string(this->get(0));
		for (int i = 1; i < mSize; i++) {
			result += ", " + std::to_string(this->get(i));
		}
		result += "]";
		return result;
	}
}

template <typename T>
int ArrayList<T>::indexOf(T value) {
	for (int i = 0; i < mSize; i++) {
		if (elementData[i] == value) {
			return i;
		}
	}
	return -1;
}

template <typename T>
bool ArrayList<T>::isEmpty() {
	return mSize == 0;
}

template <typename T>
bool ArrayList<T>::contains(T value) {
	return indexOf(value) >= 0;
}

template <typename T>
void ArrayList<T>::add(T value) {
	ensureCapacity(mSize + 1);
	elementData[mSize] = value;
	mSize++;
}

template <typename T>
void ArrayList<T>::add(int index, T value) {
	if (index < 0 || index > mSize) {
		throw std::out_of_range("index: " + index);
	}
	ensureCapacity(mSize + 1);
	for (int i = mSize; i >= index + 1; i--) {
		elementData[i] = elementData[i - 1];
	}
	elementData[index] = value;
	mSize++;
}

template <typename T>
void ArrayList<T>::remove(int index) {
	checkIndex(index);
	for (int i = index; i < mSize - 1; i++) {
		elementData[i] = elementData[i - 1];
	}
	// delete elementData[mSize - 1]; //TODO
	elementData[mSize - 1] = NULL;
	mSize--;
}

template <typename T>
void ArrayList<T>::set(int index, T value) {
	checkIndex(index);
	elementData[index] = value;
}

template <typename T>
void ArrayList<T>::clear() {
	for (int i = 0; i < mSize; i++) {
		// delete elementData[i]; //TODO
		elementData[i] = NULL;
	}
	mSize = 0;
}

template <typename T>
void ArrayList<T>::addAll(ArrayList<T> other) {
	for (int i = 0; i < other.size(); i++) {
		this->add(other.get(i));
	}
}

template <typename T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& other) {
	this->mSize = other.mSize;
	this->elementData = other.elementData;

	return *this;
}

template <typename T>
void ArrayList<T>::ensureCapacity(int capacity) {
	if (capacity > sizeof(*elementData)) {
		int newCapacity = sizeof(*elementData) * 2 + 1;
		if (capacity > newCapacity) {
			newCapacity = capacity;
		}

		T* newElementData = new T[newCapacity];
		for (int i = 0; i < mSize; i++) {
			newElementData[i] = elementData[i];
		}
		elementData = newElementData;
	}
}

template <typename T>
void ArrayList<T>::checkIndex(int index) {
	if (index < 0 || index >= mSize) {
		throw std::out_of_range("index: " + index);
	}
}
