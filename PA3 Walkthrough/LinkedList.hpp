//
//  Header.h
//  LinkedList
//
//  Created by rick gessner on 10/7/20.
//

#ifndef linkedlist_h
#define linkedlist_h

namespace ECE17 {

    struct Node {
        Node() {
            next = nullptr;
        }
        int value;
        Node* next;
    };


    class LinkedList {
        Node* first();
        size_t  size() {
            /* 
            Way 1 - Counting each node
            1) Traverse Node
                a) Assign temp variable (iterator)
                b) Loop until temp is nullptr
                    1) Increment count
                    2) Assign temp to temp->next

            Way 2 - Keeping a running sum
            1) Include a running sum data member
            2) Increment sum every time we add a Node
            3) Decrement sum every time we remove a Node
            4) return count;
            */
            return 0;
        }
        // In this function anOrigin has a default argument
        /*
        Default argument -> if no parameter is passed in, it will automatically have default value
        find(1);
        find(1, Node(2));
        */
        Node* find(const int& aValue, Node* anOrigin = nullptr) {
            /*
            Edge Cases
            1) anOrigin == nullptr
                a) traversal starts at root (temp = root)

            2) anOrigin == Node
                a) traversal starts at anOrigin (temp = anOrigin)

            Function Body
            1) Determine where to start
            2) Traverse
                a) compare traversal temp variable to aValue
                    1) implement Node::operater=(...)
                    2) compare temp->aValue to aValue
            */

            return nullptr;
        }

        Node* append(const int& aValue) {
            /*
            Edge Cases
            1) List is Empty
                a) if root == nullptr
                    1) Create a new Node with aValue
                    2) ... TBD How would you attach this new Node to your LinkedList class? --------------------------------

            2) List is not Empty
                WAY 1
                a) if root != nullptr
                b) Traverse the List to get to end (Node end)
                    1) end->next is nullptr
                    2) Create a new Node with aValue
                    3) end->next to new Node

                WAY 2 (Challenge: way to implement so we don't have to traverse entire list)
                a) if root != nullptr
                b) Create a new Node with aValue
                c) end->next to Node (data member)
            */
            return nullptr;
        }

        Node* insertAfter(const int& aValue, Node* anOrigin = nullptr) {
            /*
            Edge Cases
            1) anOrigin == nullptr (insert at front)
                a) Create new Node
                b) new Node->next = root
                c) root = new Node

                Scenario 1 - root = newNode
                {A->B->C} root = A
                1) Create a new Node
                2) Assign root = newNode (H)
                root = H
                {H} => lost A->B->C->nullptr

                Scenario 2 - newNode = root
                1) Create a new Node
                2) newNode->next = A (root)
                3) set root = H
                {H->A->B->C}

            2) anOrigin is in middle
                {A->B->C->D} insert H after B
                Scenario 1
                B->next = H then, H->next == nullptr, we've lost C->D
                Therefore we do this:
                1) Save B->next in a temp variable
                2) Assign B->next = H
                3) Assign H->next = C
                {A->B->H->C->D}

            3) anOrigin is the last Node
                a) Create new Node
                b) set anOrigin->next to the new Node
            */
        }

        Node* remove(const int& aValue) {
            /*
            1) Call Find
                a) if found => find returns a Node (not nullptr)
                    1) Remove root
                        a) Assign temp variable to root
                        b) Assign root variable to root->next
                        c) return temp

                        Scenario 1 - set root = B then delete A
                        {A->B->C}

                    2) Remove middle
                        a) Assign temp to middle
                        b) Assign previous->next to temp->next
                        c) return temp

                    3) Remove end
                        a) assign end to temp variable
                        b) Assign previous->next to nullptr (How do we get previous?) {Traversal}
                            1) ... TBD
                        c) return end

                        Scenario 1
                        {A->B->C}
                        1) delete C
                        {A->B->*garbage*}
                b) if not found
                    a) return nullptr
            */
        }

    protected:
        Node* root;
        // size_t count;

    };


}

#endif /* linkedlist_h */
