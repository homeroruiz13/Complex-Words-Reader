#include "TextProcessor.h"
#include "LinkedList.h"

void TextProcessor::processFile(const string& filename, LinkedList& list) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    string word;
    while (file >> word) {
        word = cleanWord(word);
        if (!word.empty()) {
            list.insertSorted(word);
        }
    }
    file.close();
}

string TextProcessor::cleanWord(const string& word) {
    string cleanWord = "";
    for (char ch : word) {
        if (isalpha(ch)) {
            cleanWord += tolower(ch);
        }
    }
    return cleanWord;
}
