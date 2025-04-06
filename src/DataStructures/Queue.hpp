#pragma once

#include <memory>
#include <stdexcept>

template<typename T>
struct Queue {
private:
	size_t length = 0;
	size_t currentPosition = 0;

	T* data = nullptr;

public:
	/*
	* @brief Creates a brand new queue
	* @param Length of the queue
	* @author ZaneDevv
	*/
	Queue(size_t length) {
		this->length = length;
		this->data = (T*)malloc(sizeof(T) * length);

		// Checks if you have memory enough to save this data
		if (this->data == nullptr) {
			free(this->data);
			this->length = 0;

			throw std::runtime_error("No memory enough to create this queue!");
		}
	}
	/*
	* @brief Frees memory
	* @author ZaneDevv
	*/
	~Queue() {
		if (this->data != nullptr) {
			free(this->data);
			this->length = 0;
			this->currentPosition = 0;
		}
	}

	/*
	* @brief Sets the next value in the queue to the specified value
	* @param Value to set in the queue
	* @author ZaneDevv
	*/
	void PushBack(T element) {
		if (this->data == nullptr) return;

		this->data[this->currentPosition] = element;
		this->currentPosition++;
	}

	/*
	* @brief Removes the first element in the queue
	* @author ZaneDevv
	*/
	void PopFront() {
		if (this->data == nullptr) return;

		this->currentPosition--;

		for (size_t i = 0; i <= this->currentPosition; i++) {
			this->data[i] = this->data[i + 1];
		}
	}

	/*
	* @return The current length of the queue
	* @author ZaneDevv
	*/
	size_t Length() { return this->length; }

	T& operator[](size_t index) { return data[index]; }
	const T& operator[](size_t index) const { return data[index]; }
};
