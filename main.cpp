#include "header.h"
#include <iostream>

int main() {

    string inputFileName;
    string outputFileName;

    char choice;

    cout << "Irasykite failo su tekstu pavadinima (pvz.: text1.txt): ";
    cin >> inputFileName;

    map<string, wordInfo> wordInfo = countWords(inputFileName);

    cout << "Ar isvesti rezultatus i terminala? (taip-t/ne-n) ";
    cin >> choice;

    if (choice == 't') {
        writeWordInfoToTerminal(wordInfo);
    }
    else {
        cout << "Output file name: ";
        cin >> outputFileName;
        writeWordInfoToFile(wordInfo, outputFileName);
    }

    cout << "Padaryta." << endl;
    return 0;
}
