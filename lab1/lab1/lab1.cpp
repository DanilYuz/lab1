#include <iostream>
#include "Queue.h"
#include "Stack.h"
#include "Deque.h"
#include "Book.h"
// ** + ***
int main()
{
    Stack<int> myStack;
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    std::cout << "Top element in the stack: " << myStack.top() << std::endl;

    Queue<int> myQueue;

    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);

    std::cout << "Front element in the queue: " << myQueue.front() << std::endl;


    Deque<int> myDeque;

    myDeque.enqueueFront(10);
    myDeque.enqueueRear(20);
    myDeque.enqueueFront(5);

    std::cout << "Front element in the deque: " << myDeque.front() << std::endl;
    std::cout << "Rear element in the deque: " << myDeque.rear() << std::endl;

    myDeque.dequeueFront();
    std::cout << "Front element after dequeue from the front: " << myDeque.front() << std::endl;

    myDeque.dequeueRear();
    std::cout << "Rear element after dequeue from the rear: " << myDeque.rear() << std::endl;


    std::string title = "title";
    std::string date = "12.23.2023";
    std::string abstr = "a short book about OOP";
    Stack<std::string>authors = Stack<std::string>(new Node<std::string>("B. F. Hoyo"));
    Book a = Book(title, authors, date, 456, abstr);


    Stack<std::string>names = Stack<std::string>(new Node<std::string>("LowHP"));
    Stack<std::string>books = Stack<std::string>(new Node<std::string>("HarryPotter"));
    Stack<std::string>roles = Stack<std::string>(new Node<std::string>("main"));

    a.addCherecter(names, books, roles);
    std::cout << a.getAllInfo();
    return 0;
}
