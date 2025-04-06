#pragma once

#include <memory>
#include <stdexcept>

template<typename T>
struct Stack {
private:
	size_t length = 0;
	T* data = nullptr;

public:
	/*
	* @brief Creates a brand new stack.
	* @param Length of the stack
	* @author ZaneDevv
	*/
	Stack(size_t length) {
		this->length = length;
		this->data = (T*)malloc(sizeof(T) * length);

		// Checks if you have memory enough to save this data
		if (this->data == nullptr) {
			free(this->data);
			this->length = 0;

			throw std::runtime_error("No memory enough to create this stack!");
		}
	}

	/*
	* @brief Frees memory
	* @author ZaneDevv
	*/
	~Stack() {
		if (this->data != nullptr) {
			free(this->data);
			this->length = 0;
		}
	}

	/*
	* @brief Sets the value to the first position
	* @param Value to push on the first position
	* @author ZaneDevv
	*/
	void Push(T element) {
		if (this->data == nullptr) return;

		for (size_t i = this->length; i > 0 ; i--) {
			if (this->data[i - 1] == NULL) { continue; };

			this->data[i] = this->data[i - 1];
		}
		this->data[0] = element;
	}

	/*
	* @brief Removes the first element in the stack
	* @author ZaneDevv
	*/
	void Pop() {
		if (this->data == nullptr) return;

		for (size_t i = 0; i < this->length - 1; i++) {
			if (this->data[i + 1] == NULL) { break; }

			this->data[i] = this->data[i + 1];
		}
	}

	/*
	* @return Returns the current length of the stack
	* @author ZaneDevv
	*/
	size_t Length() { return this->length; }

	T& operator[](size_t index) { return data[index]; }
	const T& operator[](size_t index) const { return data[index]; }
};
