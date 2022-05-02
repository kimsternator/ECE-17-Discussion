#include <iostream>

/*
Visitor Pattern
Building Stack/Queue using vector
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

int main() {
    Queue<KeyValue*> theQueue;
    theQueue.push(new KeyValue(1, 2));
    theQueue.push(new KeyValue(3, 4));
    theQueue.push(new KeyValue(5, 6));
    theQueue.push(new KeyValue(7, 8));
    theQueue.printQueue(std::cout);

    /*QueueKVVisitor theVisitor(std::cout);
    theQueue.visitWith(theVisitor);*/
    return 0;
}