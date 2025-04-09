#pragma once

#include "./Vector.hpp"

template<typename T>
struct Set {
private:
	Vector<T> data = Vector<T>();

	/*
	* @brief Checks if a value is in a specific vector
	* @return If the element is in the vector, returns true, if it is not, returns false
	* @author ZaneDevv
	*/
	bool IsValueInVector(T element, Vector<T>* vector) {
		for (size_t i = 0; i < vector->Length(); i++) {
			if (element == (*vector)[i]) {
				return true;
			}
		}

		return false;
	}

public:
	Set() {}

	/*
	* @brief Creates a new set copying another one
	* @param Another set
	* @author ZaneDevv
	*/
	Set(Vector<T> vector) {
		// Removing the repeated data
		for (size_t i = 0; i < vector.Length() - 1; i++) {
			for (size_t j = 0; j < vector.Length(); j++) {
				if (i == j) { continue; }

				T element1 = vector[i];
				T element2 = vector[j];

				if (element1 == element2) {
					for (size_t k = j + 1; k < vector.Length(); k++) {
						vector[k - 1] = vector[k];
					}
				}
			}
		}

		this->data = vector;
	}

	/*
	* @brief Frees the memory
	* @author ZaneDevv
	*/
	~Set() = default;

	/*
	* @brief Adds a new value in the set
	* @param Value to add
	* @author ZaneDevv
	*/
	void Add(T element) {
		bool canAddValue = !(this->IsValueInVector(element, &this->data)); // Ensures the value is not repeated

		if (canAddValue) {
			this->data.PushBack(element);
		}
	}

	/*
	* @brief Removes an element of the set in a specific position
	* @param Position of the element to remove
	* @author ZaneDevv
	*/
	void Remove(size_t index) {
		if (index <= this->data.Length()) {
			
			for (size_t i = index; i < this->data.Length(); i++) {
				this->data[i] = this->data[i + 1];
			}
		}
	}

	/*
	* @brief A∪B: Creates a new set with all the element in the current set and another one
	* @param Another set
	* @return A new set with all the elements of both sets
	* @author ZaneDevv
	*/
	Set<T> Union(Set<T> other) {
		Set<T> newSet(this->data);

		for (size_t i = 0; i < other.Length(); i++) {
			T element = other[i];

			if (!(this->IsValueInVector(element, &newSet.data))) {
				newSet->Add(element);
			}
		}

		return newSet;
	}

	/*
	* @brief A∩B: Creates a new set with the element that have in common the current set with another one
	* @param Another set
	* @return A new set with the elements in common
	* @author ZaneDevv
	*/
	Set<T> Intersection(Set<T> other) {
		Set<T> newSet();

		for (size_t i = 0; i < this->data.Length(); i++) {
			if (IsValueInVector(this->data[i], other.data)) {
				newSet.Add(this->data[i]);
			}
		}

		return newSet;
	}

	/*
	* @brief Gives the length of the set
	* @return Current length of the set
	* @author ZaneDevv
	*/
	size_t Length() { return this->data.Length(); }

	T& operator[](size_t index) { return this->data[index]; }
	const T& operator[](size_t index) const { return this->data[index]; }
};
