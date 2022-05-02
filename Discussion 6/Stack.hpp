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

	void push(T aValue);
	T peek();
	void pop();


private:
	std::vector<T> stack;
};