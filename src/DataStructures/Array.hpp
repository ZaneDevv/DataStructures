#pragma once

#include <memory>
#include <stdexcept>

template<typename T>
struct Array
{
private:
	size_t length = 0;
	T* data = nullptr;

public:
	/*
	* @brief Creates a brand new array
	* @param Length of the array
	* @author ZaneDevv
	*/
	Array(size_t length) {
		this->length = length;
		this->data = (T*)malloc(sizeof(T) * length);

		// You may no have enough memory on your device. Therefore, we must throw an error and remove whatever we made.
		if (this->data == nullptr) {
			free(this->data);
			this->length = 0;

			throw std::runtime_error("No memory enough to create this array!");
		}
	}

	/*
	* @brief Frees memory
	* @author ZaneDevv
	*/
	~Array() {
		// It might has an error and the data is null. To avoid issues, we ensure data actually exists.
		if (data != nullptr) {
			free(data);
			this->length = 0;
		}
	}

	T& operator[](size_t index) { return data[index]; }
	const T& operator[](size_t index) const { return data[index]; }

	/*
	* @brief Returns the length of the array
	* @return Length of the array
	* @author ZaneDevv
	*/
	size_t Length() { return this->length; }
};
