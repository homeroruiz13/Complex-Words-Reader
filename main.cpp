#include "LinkedList.h"
#include "TextProcessor.h"
#include <iostream>
using namespace std;

int main() {
    LinkedList wordList;
    TextProcessor processor;

    string filename = "LittleWomen.txt";  // Change this to your desired input file
    processor.processFile(filename, wordList);

    cout << "Unique Words List:" << endl;
    wordList.printList();
    
    int uniqueWords = wordList.getUniqueWordCount();
    cout << "Total unique words: " << uniqueWords << endl;

    return 0;
}
