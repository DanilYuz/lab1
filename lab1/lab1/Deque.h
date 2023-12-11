#pragma once
#include "Node.h"
#include <iostream>

template <typename T>
class Deque {
private:
    Node<T>* frontNode; // Pointer to the front of the deque
    Node<T>* rearNode;  // Pointer to the rear of the deque

public:
    // Default constructor
    Deque() : frontNode(nullptr), rearNode(nullptr) {}

    // Destructor to free memory
    ~Deque() {
        while (!isEmpty()) {
            dequeueFront();
        }
    }

    // Function to enqueue an element at the front of the deque
    void enqueueFront(const T& element) {
        Node<T>* newNode = new Node<T>(element);
        if (isEmpty()) {
            frontNode = rearNode = newNode;
        }
        else {
            newNode->next = frontNode;
            frontNode->prev = newNode;
            frontNode = newNode;
        }
    }

    // Function to enqueue an element at the rear of the deque
    void enqueueRear(const T& element) {
        Node<T>* newNode = new Node<T>(element);
        if (isEmpty()) {
            frontNode = rearNode = newNode;
        }
        else {
            rearNode->next = newNode;
            newNode->prev = rearNode;
            rearNode = newNode;
        }
    }

    // Function to dequeue an element from the front of the deque
    void dequeueFront() {
        if (!isEmpty()) {
            Node<T>* temp = frontNode;
            frontNode = frontNode->next;
            if (frontNode != nullptr) {
                frontNode->prev = nullptr;
            }
            else {
                rearNode = nullptr; // If the deque becomes empty
            }
            delete temp;
        }
        else {
            std::cerr << "Error: Deque is empty. Cannot dequeue from the front." << std::endl;
        }
    }

    // Function to dequeue an element from the rear of the deque
    void dequeueRear() {
        if (!isEmpty()) {
            Node<T>* temp = rearNode;
            rearNode = rearNode->prev;
            if (rearNode != nullptr) {
                rearNode->next = nullptr;
            }
            else {
                frontNode = nullptr; // If the deque becomes empty
            }
            delete temp;
        }
        else {
            std::cerr << "Error: Deque is empty. Cannot dequeue from the rear." << std::endl;
        }
    }

    // Function to get the front element of the deque
    T front() const {
        if (!isEmpty()) {
            return frontNode->data;
        }
        else {
            std::cerr << "Error: Deque is empty. Cannot get front element." << std::endl;
            return T(); // Default value for type T
        }
    }

    // Function to get the rear element of the deque
    T rear() const {
        if (!isEmpty()) {
            return rearNode->data;
        }
        else {
            std::cerr << "Error: Deque is empty. Cannot get rear element." << std::endl;
            return T(); // Default value for type T
        }
    }

    // Function to check if the deque is empty
    bool isEmpty() const {
        return frontNode == nullptr;
    }
};