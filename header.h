#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <cctype>
#include <stdexcept>
#include <set>
#include <iomanip>

using namespace std;

struct wordInfo {
    int count;
    set<int> lineNumbers;
};

string cleanWord(const string& word);
map<string, wordInfo> countWords(const string& fileName);
void writeWordInfoToFile(const map<string, wordInfo>& wordInfo, const string& fileName);
void writeWordInfoToTerminal(const map<string, wordInfo>& wordInfo);

#endif // HEADER_H_INCLUDED
