#include <bits/stdc++.h>
using namespace std;

map<char, char> monoalphabeticMapping;
string mainString = "qwertyuiopasdfghjklzxcvbnm";
string allChars = "abcdefghijklmnopqrstuvwxyz";
void init()
{

    for (int i = 0; i < allChars.size(); i++) {

        char currentChar = allChars[i];
        char characterMap = mainString[i];

        monoalphabeticMapping[currentChar] = toupper(characterMap);
        monoalphabeticMapping[toupper(currentChar)] = characterMap;
    }
}

string applyMonoAlphabetic(string plainText)
{
    string cipherText = "";

    for (char& ch : plainText) {
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            cipherText += monoalphabeticMapping[ch];
        } else
            cipherText += ch;
    }

    return cipherText;
}

int main()
{

    init();
    string plainText, cipher;

    while (cin >> plainText) {

        cipher = applyMonoAlphabetic(plainText);
        cout << cipher << " ";
        cipher.clear();
    }
}

// sample input: attack
// sample output: QZZQEA
