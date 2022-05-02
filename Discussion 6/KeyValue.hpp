#pragma once

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

