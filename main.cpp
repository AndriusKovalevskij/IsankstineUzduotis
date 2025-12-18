#include "header.h"
#include <iostream>

int main() {

    std::string inputFile;
    std::string outputFile;

    std::cout << "Irasykite failo su tekstu pavadinima (pvz.: text1.txt): ";
    std::getline(std::cin, inputFile);

    map<string, int> wordCounts = countWords(inputFileName);

    cout << "Ar isvesti rezultatus i terminala? (taip/ne) ";
    std::char choice;
    std::getline(std::cin, choice);

    if (choice == 'taip') {
        writeWordCountsToTerminal(wordCounts);
    }
    else {
        cout << "Output file name: ";
        cin >> outputFileName;
        writeWordCountsToFile(wordCounts, outputFileName);
    }

    cout << "Padaryta." << endl;
    return 0;
}
