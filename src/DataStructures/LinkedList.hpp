#pragma once

#include <memory>

template<typename T>
struct Node {
	T Value = NULL;
	Node* NextNode = nullptr;
	Node* PreviousNode = nullptr;
	Node* StartNode = nullptr;

	/*
	* @brief Creates a new node woth the value set
	* @param Value to set on the node
	* @author ZaneDevv
	*/
	Node(T element) {
		this->Value = element;
	}

	/*
	* @brief Clears the node
	* @author ZaneDevv
	*/
	~Node() {
		this->Value = NULL;
		this->NextNode = nullptr;
		this->PreviousNode = nullptr;
		this->StartNode = nullptr;
	}
};

template<typename T>
struct LinkedList {
private:
	Node<T>* startingNode = nullptr;
	Node<T>* currentNode = nullptr;

	size_t nodesAmount = 0;

public:
	LinkedList() {}

	/*
	* @brief Removes the whole list with all its nodes
	* @author ZaneDevv
	*/
	~LinkedList() {
		if (startingNode != nullptr) {
			Node<T>* currentNode = this->startingNode;

			do {

				Node<T>* nextNode = currentNode->NextNode;
				
				delete currentNode;
				currentNode = nextNode;

			} while (currentNode->NextNode != nullptr);
		}
	}

	/*
	* @brief Creates a new node to this list with the specified value
	* @param Value to set in the new node
	* @author ZaneDevv
	*/
	void AddNode(T element) {
		Node<T>* newNode = new Node<T>(element);

		if (this->startingNode == nullptr) {
			this->startingNode = newNode;
			this->currentNode = newNode;
		}
		else {
			this->currentNode->NextNode = newNode;
			newNode->PreviousNode = this->currentNode;
			this->currentNode = newNode;
		}

		this->nodesAmount++;
	}

	/*
	* @brief Creates a new connection with the last node and the new one
	* @param Node to add to the list
	* @author ZaneDevv
	*/
	void AddNode(Node<T>* newNode) {
		if (this->startingNode == nullptr) {
			this->startingNode = newNode;
		}
		else {
			this->currentNode->NextNode = newNode;
			newNode->PreviousNode = this->currentNode;
			this->currentNode = newNode;
		}

		this->nodesAmount++;
	}

	/*
	* @brief Removes a specifid node in the list
	* @param Node to be removed
	* @author ZaneDevv
	*/
	void RemoveNode(Node<T>& node) {
		if (startingNode != nullptr) {
			Node<T>* currentNode = this->startingNode;

			while (currentNode != nullptr) {
				if (&node == currentNode) {

					currentNode->PreviousNode->NextNode = currentNode->NextNode;
					delete currentNode;

					break;
				}

				currentNode = currentNode->NextNode;
			}

			this->nodesAmount--;
		}
	}

	/*
	* @brief Remove a node by its value
	* @param Value of the node to remove
	* @author ZaneDevv
	*/
	void RemoveNodeByValue(T value) {
		if (startingNode != nullptr) {
			Node<T>* currentNode = this->startingNode;

			while (currentNode != nullptr) {
				if (currentNode->Value == value) {

					currentNode->PreviousNode->NextNode = currentNode->NextNode;
					delete currentNode;

					break;
				}

				currentNode = currentNode->NextNode;
			}

			this->nodesAmount--;
		}
	}

	/*
	* @brief Gets the starting node
	* @return Returns the first node on the list
	* @author ZaneDevv
	*/
	Node<T>* GetStartingNode() { return this->startingNode; }

	/*
	* @brief Gets the amount of nodes in the list
	* @return Amount of nodes
	* @author ZaneDevv
	*/
	size_t GetNodesAmount() { return this->nodesAmount; }
};
