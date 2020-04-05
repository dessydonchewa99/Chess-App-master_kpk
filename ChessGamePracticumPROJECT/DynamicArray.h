#pragma once

template<typename T>
CONST int DEFAULT_SIZE = 0;
CONST int DEFAULT_CAPACITY = 20;
class DynamicArray {
private:
	T * arr;
	unsigned size;
	unsigned capacity;

	void resize() {
		capacity *= 2;
		T* temp = new T[capacity];
		for (unsigned i = 0; i < size; i++) {
			temp[i] = arr[i];
		}
		delete[] arr;
		arr = temp;
	}

	void copy(const DynamicArray<T>& otherArr) {
		size = otherArr.size;
		capacity = otherArr.capacity;
		arr = new T[capacity];
		for (unsigned i = 0; i < size; i++) {
			arr[i] = otherArr.arr[i];
		}
	}
public:
	DynamicArray() {
		size = DEFAULT_SIZE;
		capacity = DEFAULT_CAPACITY;
		arr = new T[capacity];
	}
	DynamicArray(const DynamicArray<T>& otherArr) {
		copy(otherArr);
	}
	DynamicArray& operator = (const DynamicArray<T>& otherArr) {
		if (this != &otherArr) {
			delete[] arr;
			copy(otherArr);
		}
		return *this;
	}
	~DynamicArray() {
		for (unsigned int i = 0; i < size; i++) {

			delete arr[i];
		}
	}

	void unionWithOther(const DynamicArray<T>& otherArr) {
		for (int i = 0; i < otherArr.get_size(); i++) {
			this->push_back(otherArr.get_ElementAtIndex(i));
		}

	}

	void push_back(const T& new_element) {
		if (size == capacity) {
			resize();
		}
		arr[size] = new_element;
		size++;
	}

	T& operator[] (unsigned index) {
		return arr[index];
	}
	T operator[] (unsigned index) const {
		return arr[index];
	}

	unsigned get_size() const {
		return size;
	}
	T get_ElementAtIndex(unsigned index) const {
		return arr[index];
	}
	void remove_by_index(unsigned index) {
		for (unsigned i = index; i <= this->size - 1; i++) {
			arr[i] = arr[i + 1];
		}
		size--;
	}
};