#include <iostream>
#include "./DataStructures/Array.hpp"
#include "./DataStructures/Vector.hpp"
#include "./DataStructures/LinkedList.hpp"
#include "./DataStructures/Stack.hpp"
#include "./DataStructures/Queue.hpp"
#include "./DataStructures/Set.hpp"

class Person {
private:
	short age;

public:
	Person(short age) {
		this->age = age;
	}

	int GetAge() { return this->age; }
};

int main() {
	/*
		Array<Person> array(3);

		Person a(14);
		Person b(17);
		Person c(30);

		array[0] = a;
		array[1] = b;
		array[2] = c;

		for (int i = 0; i < array.Length(); i++) {
			std::cout << i << ": " << array[i].GetAge() << std::endl;
		}
	*/

	/*
		Vector<int> vector = Vector<int>();
		for (int i = 0; i < 10; i++) {
			vector.PushBack(i);
		}

		vector.PopBack();
		vector.PopBack();
		vector.PopBack();
		vector.PopBack();

		for (int i = 0; i < 20; i++) {
			vector.PushBack(i + 40);
		}

		for (int i = 0; i < vector.Length(); i++) {
			std::cout << i << ": " << vector[i] << std::endl;
		}

		vector.~Vector();
	*/

	/*
		LinkedList<int> list = LinkedList<int>();
		list.AddNode(5);
		list.AddNode(4);
		list.AddNode(3);
		list.AddNode(2);
		list.AddNode(1);

		Node<int>* currentNode = list.GetStartingNode();
		do {
			std::cout << currentNode->Value << std::endl;
			currentNode = currentNode->NextNode;
		} while (currentNode != nullptr);

		std::cout << std::endl;

		list.RemoveNodeByValue(4);
		currentNode = list.GetStartingNode();
		do {
			std::cout << currentNode->Value << std::endl;
			currentNode = currentNode->NextNode;
		} while (currentNode != nullptr);
	*/

	/*
		Stack<int> stack = Stack<int>(10);

		for (int i = 0; i < 8; i++) {
			stack.Push(i * 2);
		}

		for (int i = 0; i < stack.Length(); i++) {
			std::cout << i << ": " << stack[i] << std::endl;
		}

		stack.Pop();
		stack.Pop();
		stack.Pop();
		std::cout << std::endl;

		for (int i = 0; i < stack.Length(); i++) {
			std::cout << i << ": " << stack[i] << std::endl;
		}
	*/

	/*
		Queue<char> queue = Queue<char>(10);
		for (int i = 0; i < 8; i++) {
			queue.PushBack((char)(i * 2 + 'A'));
		}

		for (int i = 0; i < queue.Length(); i++) {
			std::cout << i << ": " << queue[i] << std::endl;
		}

		queue.PopFront();
		queue.PopFront();
		std::cout << std::endl;

		for (int i = 0; i < queue.Length(); i++) {
			std::cout << i << ": " << queue[i] << std::endl;
		
	*/

	/*
		Set<int> set = Set<int>();

		for (int i = 5; i <= 10; i++) {
			set.Add(i);
		}

		for (int i = 0; i < set.Length(); i++) {
			std::cout << set[i] << std::endl;
		}
		std::cout << std::endl;
	*/

	std::cin.get();
	return 0;
}
