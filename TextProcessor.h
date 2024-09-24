#ifndef TEXTPROCESSOR_H
#define TEXTPROCESSOR_H

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include "LinkedList.h"  // Add this line to include LinkedList class

using namespace std;

class TextProcessor {
public:
    void processFile(const string& filename, LinkedList& list);
    string cleanWord(const string& word);
};

#endif // TEXTPROCESSOR_H
