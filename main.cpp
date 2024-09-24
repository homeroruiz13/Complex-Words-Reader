#include "LinkedList.h"
#include "TextProcessor.h"
#include <iostream>
using namespace std;

int main() {
    LinkedList wordList;
    TextProcessor processor;

    // Get the filename from the user
    string filename;
    cout << "Input file name: ";
    cin >> filename;  // User will input: books/CallWild.txt (or any valid file)

    // Process the file to extract and insert unique words into the linked list
    processor.processFile(filename, wordList);

    // Calculate and print the total number of unique words
    int uniqueWordCount = wordList.getUniqueWordCount();
    cout << "Number of unique words: " << uniqueWordCount << endl;

    // To get the total word count, you can keep track of every word extracted in the processor
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        return 1;
    }

    // Count total words in the file
    string word;
    int totalWordCount = 0;
    while (file >> word) {
        ++totalWordCount;  // Count every word read from the file
    }
    file.close();

    cout << "Total number of words: " << totalWordCount << endl;

    return 0;
}
