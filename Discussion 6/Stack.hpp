#pragma once

#include <vector>

template <typename T>
class Stack {
public:
	Stack() = default;

	Stack(const Stack& aCopy) {
		*this = aCopy;
	}

	~Stack() {
		for (auto& item : stack) {
			delete item;
		}
	}

	Stack& operator=(const Stack& aCopy) {
		stack = aCopy.stack;
		return *this;
	}

	size_t size() const {
		return stack.size();
	}	

	void printStack(std::ostream& anOutput) const {
		for (auto& item : stack) {
			anOutput << item << " ";
		}
		anOutput << "\n";
	}
	// LIFO - Last in first out
	// push_back
	// Defined the back of the vector to be the top of the
	// stack
	void push(T aValue) {
		stack.push_back(aValue);
	}

	T peek() {
		return stack[size() - 1];
	}

	void pop() {
		stack.erase(stack.begin() + size() - 1)
	}



private:
	std::vector<T> stack;
};