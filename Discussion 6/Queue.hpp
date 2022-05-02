#pragma once

#include <vector>

#include "KeyValue.hpp"
// FIFO - FIrst in first out

template <typename T>
class Queue {
public:
	Queue() = default;

	Queue(const Queue& aCopy) {
		*this = aCopy;
	}

	~Queue() {
		queue.clear();
	}

	Queue& operator=(const Queue& aCopy) {
		queue = aCopy.queue;
		return *this;
	}

	size_t size() const {
		return queue.size();
	}

	void printQueue(std::ostream& anOutput) const {
		for (auto& item : queue) {
			anOutput << item << ", ";
		}
		anOutput << "\n";
	}
	// push_back
	/*
	1) {} - initial
	2) {1} - push(1)
	3) {1, 2} - push(2)
	4) {2} - pop()
	*/
	void push(T aValue) {
		queue.push_back(aValue);
	}

	T peek() { 
		return queue.front();
	}

	void pop() {
		// remove the front of the vector
		queue.erase(queue.begin());
	}

	/* print a queue
	temp vector;
	while (queue.size() > 0) {
		vector.push_back(queue.peek());
		queue.pop();
	}
	print vector
	while (vector.size() > 0) {
		queue.push(vector[0])
		vector remove first element
		}
	*/

	/* print a stack
	temp vector;
	while (stack.size() > 0) {
		vector.push_back(stack.peek());
		stack.pop();
	}
	print(vector)
	while (vector.size() > 0) {
		queue.push(vector[vector.size() - 1])
		vector remove first element
		}
	*/

	Queue& visitWith(IKeyValueVisitor& aVisitor) {
		for (auto item : queue) {
			(*item)(aVisitor);
		}
		return *this;
	}

private:
	std::vector<T> queue;
};