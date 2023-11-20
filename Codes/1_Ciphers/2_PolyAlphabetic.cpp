#include <bits/stdc++.h>
using namespace std;

map<char, string> polyalphabeticMapping;

string mainString = "qwertyuiopasdfghjklzxcvbnm";
string mainStringUpper = "QWERTYUIOPASDFGHJKLZXCVBNM";
string allChars = "abcdefghijklmnopqrstuvwxyz";



void init()
{
    for (int i = 0; i < allChars.length(); ++i) {
        char currentChar = allChars[i];
        string characterMap = mainString;
        string characterMapUpper = mainStringUpper;

        polyalphabeticMapping[currentChar] = characterMapUpper;
        polyalphabeticMapping[toupper(currentChar)] = characterMap;

        // right shift
        mainString = mainString.back() + mainString.substr(0, mainString.length() - 1);
        mainStringUpper = mainStringUpper.back() + mainStringUpper.substr(0, mainStringUpper.length() - 1);
    }

}

string applyPolyAlphabetic(string plainText)
{
    string cipherText = "";

    int position = 0;

    for (int i = 0; i < plainText.length(); ++i) {
        char currentChar = plainText[i];

        if (currentChar == ' ') {
            cipherText += ' ';
            position = 0;
        } else {
            string mapping = polyalphabeticMapping[currentChar];
            char cipherChar = mapping[position];
            cipherText += cipherChar;
            ++position;
        }
    }

    return cipherText;
}

int main()
{
    init();
    string plainText, cipherText;

    while (cin >> plainText) {
        cipherText = applyPolyAlphabetic(plainText);
        cout << cipherText << " ";
        cipherText.clear();
    }
}
// sample input: atTack me naruto
// sample output: QOpREC GB FWSPSK