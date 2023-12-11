#pragma once
template <typename K>
class Node {
public:
    K data;
    Node* next;
    Node* prev;
    Node(const K& value) : data(value), next(nullptr), prev(nullptr) {}
};