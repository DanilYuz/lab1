#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "Node.h"

template <typename T>
class Stack {
private:
    Node<T>* topNode;

public:
    Stack() : topNode(nullptr) {}
    Stack(Node<T>* a) : topNode(a) {}
    void push(T element) {
        Node<T>* newNode = new Node<T>(element);
        newNode->next = topNode;
        topNode = newNode;
    }

    void pop() {
        if (!isEmpty()) {
            Node<T>* temp = topNode;
            topNode = topNode->next;
            delete temp;
        }
        else {
            std::cerr << "Error: Stack is empty. Cannot pop." << std::endl;
        }
    }

    T top() {
        if (!isEmpty()) {
            return topNode->data;
        }
        else {
            std::cerr << "Error: Stack is empty. Cannot get top element." << std::endl;
            return T(); 
        }
    }

    bool isEmpty(){
        return topNode == nullptr;
    }
};
#endif
