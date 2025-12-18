#include "header.h"

int main() {

    string inputFileName;
    string outputFileName;

    char choice;

    cout << "Irasykite failo su tekstu pavadinima (pvz.: text1.txt): ";
    cin >> inputFileName;

    cout << "Ar isvesti rezultatus i terminala? (taip-t/ne-n) ";
    cin >> choice;

    ifstream inputFile(inputFileName);
    if (!inputFile.is_open()) {
        cerr << "Nepavyko atidaryti failo: " << inputFileName << endl;
        return 1;
    }

    stringstream buffer;
    buffer << inputFile.rdbuf();
    string text = buffer.str();
    inputFile.close();

    map<string, wordInfo> wordInfo = countWords(text);

    if (choice == 't') {
        writeWordInfoToTerminal(wordInfo, text);
    }
    else {
        cout << "Output file name: ";
        cin >> outputFileName;
        writeWordInfoToFile(wordInfo, outputFileName, text);
    }

    cout << "PABAIGA." << endl;

    return 0;

}
