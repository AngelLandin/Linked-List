#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#pragma
#include <iostream>

class LinkedList{
    private:
        struct  Node
        {
            int value;
            Node* next;
            Node(int value){
                this->value = value;
                next = nullptr;
            }
        };

        Node* head;
        Node* tail;
        int length; 

    public:
        LinkedList();
        LinkedList(int value);
        ~LinkedList();
       
        Node* get(int index);

        void insertAtBeginning(int value); //O(1)
       
        void insertAtEnd(int value); //O(1)

        bool insertAtPosition(int index, int value); //O(n)

        void deleteValue(int value); // O(n)

        bool search(int value); // O(n)

        void display(); // O(n)
                          
};


#endif // LINKEDLIST_H

