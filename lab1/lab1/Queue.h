#include <iostream>
#include "Node.h"

template <typename T>
class Queue {
private:
    Node<T>* frontNode; // Pointer to the front of the queue
    Node<T>* rearNode;  // Pointer to the rear of the queue

public:
    // Default constructor
    Queue() : frontNode(nullptr), rearNode(nullptr) {}

    // Destructor to free memory
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    // Function to enqueue an element into the queue
    void enqueue(const T& element) {
        Node<T>* newNode = new Node<T>(element);
        if (isEmpty()) {
            frontNode = rearNode = newNode;
        }
        else {
            rearNode->next = newNode;
            rearNode = newNode;
        }
    }

    // Function to dequeue an element from the queue
    void dequeue() {
        if (!isEmpty()) {
            Node<T>* temp = frontNode;
            frontNode = frontNode->next;
            delete temp;

            if (frontNode == nullptr) {
                rearNode = nullptr; // If the queue becomes empty
            }
        }
        else {
            std::cerr << "Error: Queue is empty. Cannot dequeue." << std::endl;
        }
    }

    // Function to get the front element of the queue
    T front() const {
        if (!isEmpty()) {
            return frontNode->data;
        }
        else {
            std::cerr << "Error: Queue is empty. Cannot get front element." << std::endl;
            return T(); // Default value for type T
        }
    }

    // Function to check if the queue is empty
    bool isEmpty() const {
        return frontNode == nullptr;
    }
};