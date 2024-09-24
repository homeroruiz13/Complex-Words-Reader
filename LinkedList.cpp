#include "LinkedList.h"

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* toDelete = current;
        current = current->next;
        delete toDelete;
    }
}

void LinkedList::insertSorted(string word) {
    Node* newNode = new Node(word);
    
    // If the list is empty or the word should be the new head
    if (!head || word < head->data) {
        newNode->next = head;
        head = newNode;
        return;
    }
    
    // Traverse the list and insert in alphabetical order, ignoring duplicates
    Node* current = head;
    while (current->next && current->next->data < word) {
        current = current->next;
    }
    
    if (current->data != word && (!current->next || current->next->data != word)) {
        newNode->next = current->next;
        current->next = newNode;
    }
}

void LinkedList::printList() const {
    Node* current = head;
    int count = 0;
    
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
        if (++count % 10 == 0) {
            cout << endl;  // Print 10 words per line
        }
    }
    cout << endl;
}

int LinkedList::getUniqueWordCount() const {
    int count = 0;
    Node* current = head;
    while (current != nullptr) {
        ++count;
        current = current->next;
    }
    return count;
}
