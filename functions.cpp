#include "header.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>

string cleanWord(const string& word) {
    string cleaned;
    for (char c : word) {
        if (isalpha(c)) {
            cleaned += tolower(c);
        }
    }
    return cleaned;
}

map<string, wordInfo> countWords(const string& fileName) {
    ifstream inputFile(fileName);

    if (!inputFile.is_open()) {
        throw runtime_error("Nepavyko atidaryti input failo: " + fileName);
    }

    map<string, wordInfo> wordInfo;
    string line;
    int lineNumbers = 0;

    while (getline(inputFile, line)) {
        lineNumbers++;
        stringstream ss(line);
        string word;

        while (ss >> word) {
            string cleanedWord = cleanWord(word);
            if (!cleanedWord.empty()) {
                wordInfo[cleanedWord].count++;
                wordInfo[cleanedWord].lineNumbers.insert(lineNumbers);
            }
        }
    }

    inputFile.close();
    return wordInfo;
}

void writeWordInfoToFile(const map<string, wordInfo>& wordInfo, const string& fileName) {
    ofstream outputFile(fileName);

    if (!outputFile.is_open()) {
        throw std::runtime_error("Nepavyko atidaryti output failo: " + fileName);
    }

    outputFile << setw(15) << left << "Zodis"
               << setw(10) << "Kiekis"
               << "Eilute" << endl;
    outputFile << "------------------------------------------------------------------------------" << endl;

    for (const auto& entry : wordInfo) {
        if (entry.second.count > 1) {
            outputFile << setw(15) << left << entry.first
                       << setw(10) << entry.second.count;
            for (const int lineNumbers : entry.second.lineNumbers) {
                            outputFile << lineNumbers << " ";
            }
            outputFile << endl;
        }
    }

    outputFile.close();
}

void writeWordInfoToTerminal(const map<string, wordInfo>& wordInfo) {
    cout << setw(15) << left << "Zodis"
         << setw(10) << "Kiekis"
         << "Eilute" << endl;
    cout << "------------------------------------------------------------------------------" << endl;

    for (const auto& entry : wordInfo) {
        if (entry.second.count > 1) {
            cout << setw(15) << left << entry.first
                 << setw(10) << entry.second.count;

            for (const int lineNumbers : entry.second.lineNumbers) {
                cout << lineNumbers << " ";
            }
            cout << endl;
        }
    }
}
