#include "header.h"

string cleanWord(const string& word) {
    string cleaned;
    for (char c : word) {
        if (isalpha(c)) {
            cleaned += tolower(c);
        }
    }
    return cleaned;
}

map<string, wordInfo> countWords(const string& text) {
    map<string, wordInfo> words;
    stringstream textStream(text);
    string line;
    int lineNumber = 0;

    while (getline(textStream, line)) {
        lineNumber++;

        stringstream lineStream(line);
        string word;

        while (lineStream >> word) {
            string cleanedWord = cleanWord(word);
            if (!cleanedWord.empty()) {
                words[cleanedWord].count++;
                words[cleanedWord].lineNumbers.insert(lineNumber);
            }
        }
    }

    return words;
}

vector<string> extractURLs(const string& text) {
    vector<string> urls;
    regex urlRegex(R"(\b((https?|http?://|www\.)?[a-zA-Z0-9-]+\.(com|org|net|edu|arpa|gov|mil|int|info|biz|xyz|name|io|ai|museum|travel|tech|lt|lv|uk|academy|blog|bot|[a-zA-Z]{2})(/[^\s]*)?)\b)");
    auto wordsBegin = sregex_iterator(text.begin(), text.end(), urlRegex);
    auto wordsEnd = sregex_iterator();

    for (sregex_iterator i = wordsBegin; i != wordsEnd; ++i) {
        urls.push_back(i->str());
    }

    return urls;
}

void writeWordInfoToFile(const map<string, wordInfo>& wordInfo, const string& fileName, const string& text) {
    ofstream outputFile(fileName);
    vector<string> urls = extractURLs(text);
    if (!outputFile.is_open()) {
        throw runtime_error("Nepavyko atidaryti output failo: " + fileName);
    }

    outputFile << setw(15) << left << "Zodis"
               << setw(10) << "Kiekis"
               << "Eilute" << endl;
    outputFile << "------------------------------------------------------------------------------" << std::endl;

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

    outputFile << "------------------------------------------------------------------------------" << endl;
    outputFile << "URLs:" << endl;

    for (const auto& url : urls) {
        outputFile << url << endl;
    }

    outputFile.close();
}

void writeWordInfoToTerminal(const map<string, wordInfo>& wordInfo, const string& text) {
    vector<string> urls = extractURLs(text);

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

    cout << "------------------------------------------------------------------------------" << endl;
    cout << "URLs:" << endl;

    for (const auto& url : urls) {
        cout << url << endl;
    }
}
