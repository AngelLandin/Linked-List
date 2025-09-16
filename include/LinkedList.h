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

       void insertAtBeginning(int value);
       
       void insertAtEnd(int value);

       bool insertAtPosition(int index, int value);

       void deleteValue(int value);

       bool search(int value);

       void display();
                          
};


#endif // LINKEDLIST_H

