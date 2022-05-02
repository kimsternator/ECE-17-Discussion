#pragma once

#include <iostream>
#include <utility>
#include <string>

// Forward Declaration
class KeyValue;

class IKeyValueVisitor {
public:
	virtual ~IKeyValueVisitor() = default;
	virtual void visit(const KeyValue& aKV) = 0;
};

class KeyValue {
public:
	KeyValue() {
		key = 0;
		value = 0;
	}

	KeyValue(int aKey, int aValue) {
		key = aKey;
		value = aValue;
	}

	KeyValue(const KeyValue& aCopy) = default;

	~KeyValue() = default;

	KeyValue& operator=(const KeyValue& aCopy) = default;

	std::pair<int, int> getKV() const {
		return { key, value };
	}

	std::string to_string() const {
		return std::to_string(key) + "->" + std::to_string(value);
	}

	friend std::ostream& operator<<(std::ostream& anOutput, const KeyValue& aKV) {
		anOutput << aKV.key << "->" << aKV.value;
		return anOutput;
	}

	friend std::ostream& operator<<(std::ostream& anOutput, const KeyValue* aKV) {
		anOutput << aKV->key << "->" << aKV->value;
		return anOutput;
	}

	void operator()(IKeyValueVisitor& aVisitor) const {
		aVisitor.visit(*this);
	}

private:
	int key;
	int value;
};

