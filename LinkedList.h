#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* next;
    Node(string value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList();
    ~LinkedList();
    void insertSorted(string word);
    void printList() const;
    int getUniqueWordCount() const;
};

#endif // LINKEDLIST_H
