#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <cctype>
#include <stdexcept>

using namespace std;

string cleanWord(const string& word);
map<string, int> countWords(const string& fileName);
void writeWordDataToFile(const map<string, int>& wordCounts, const string& fileName);
void writeWordDataToTerminal(const map<string, int>& wordCounts);

#endif // HEADER_H_INCLUDED
