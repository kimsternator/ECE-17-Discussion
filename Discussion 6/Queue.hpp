#pragma once

#include <vector>

#include "KeyValue.hpp"

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

	void push(T aValue) {
		queue.push_back(aValue);
	}

	T peek() {
		return *(queue.front());
	}
	void pop() {
		if (queue.empty()) {
			return;
		}
		
		queue.erase(queue.begin());
	}

	Queue& visitWith(IKeyValueVisitor& aVisitor) {
		for (auto item : queue) {
			(*item)(aVisitor);
		}
		return *this;
	}

private:
	std::vector<T> queue;
};