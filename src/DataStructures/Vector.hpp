#pragma once

#include <memory>
#include <stdexcept>

template<typename T>
struct Vector {
private:
	T* data = nullptr;

	size_t currentLength = 0;
	size_t currentPosition = 0;

public:
	/*
	* @brief Creates a brand new vector. This data structure is also called as List
	* @param Length of the vector
	* @author ZaneDevv
	*/
	Vector() {
		this->currentLength = 1;
		this->data = (T*)malloc(sizeof(T));

		// Ensures that we have space enough to create our vector.
		if (this->data == nullptr) {
			free(this->data);
			this->currentLength = 0;

			throw std::runtime_error("No memory enough to create this vector!");
		}
	}

	/*
	* @brief Frees memory
	* @author ZaneDevv
	*/
	~Vector() {
		if (this->data != nullptr) {
			free(this->data);

			this->currentLength = 0;
			this->currentPosition = 0;
		}
	}

	/*
	* @brief Set the next position of the vector to a new value
	* @param The element we want to allocate
	* @author ZaneDevv
	*/
	void PushBack(T element) {
		if (this->data != nullptr) { // Ensures that data is not 

			// If the vector is full, we allocate all our vector in a new memory address.
			if (currentPosition >= currentLength) {
				currentLength *= 2;
				T* newAllocation = (T*)malloc(sizeof(T) * currentLength);

				for (size_t i = 0; i < this->currentLength - 1; i++) {
					newAllocation[i] = this->data[i];
				}

				free(this->data);
				this->data = newAllocation;
			}

			this->data[this->currentPosition] = element;
			this->currentPosition++;
		}
	}

	/*
	* @brief Removes the last value of the vector
	* @author ZaneDevv
	*/
	void PopBack() {
		if (this->data == nullptr) return; // Ensures that data is not null

		this->data[this->currentLength - 1] = NULL;
		this->currentPosition--;
	}

	/*
	* @return Returns the current length of the vector
	* @author ZaneDevv
	*/
	size_t Length() { return this->currentLength; }

	T& operator[](size_t index) { return data[index]; }
	const T& operator[](size_t index) const { return data[index]; }
};
