#include <iostream>
#include <algorithm>

/*
Building Stack/Queue using vector
Visitor Pattern
*/

#include "KeyValue.hpp"
#include "Queue.hpp"

class QueueKVVisitor : public IKeyValueVisitor {
public:
    QueueKVVisitor(std::ostream& anOutput) : output(anOutput) {}

    void visit(const KeyValue& aKV) override {
        output << "| " << aKV << " |, ";
    }

private:
    std::ostream& output;
 };

void queueExample() {
    Queue<KeyValue*> theQueue;
    theQueue.push(new KeyValue(1, 2));
    theQueue.push(new KeyValue(3, 4));
    theQueue.push(new KeyValue(5, 6));
    theQueue.push(new KeyValue(7, 8));
    //theQueue.printQueue(std::cout);

    QueueKVVisitor theVisitor(std::cout);
    theQueue.visitWith(theVisitor);
}

bool KVcallback(const KeyValue& aKV) {
    return aKV.getKV() == std::pair<int, int>{5, 6};
}

void visitorPatternExample() {
    std::vector<KeyValue> theVec = {
        KeyValue(1, 2),
        KeyValue(3, 4),
        KeyValue(5, 6),
        KeyValue(7, 8),
        KeyValue(9, 10)
    };

    auto iter = std::find_if(theVec.begin(), theVec.end(), KVcallback);
    std::cout << (iter == theVec.end() ? "Not found" : (*iter).to_string());
}

int main() {
    //queueExample();
    //visitorPatternExample();

    return 0;
}