#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
void solve() { }

const int BITSET_LEN = 8;

vector<bitset<BITSET_LEN>> getPermutated(vector<vector<int>> initialPermutation, vector<bitset<BITSET_LEN>> binaryText)
{
    vector<bitset<BITSET_LEN>> initialPermutationText;
    for (int i = 0; i < initialPermutation.size(); i++) {
        bitset<BITSET_LEN> b;
        for (int j = 0; j < initialPermutation[i].size(); j++) {

            int pos = initialPermutation[i][j] - 1;
            int row = pos / BITSET_LEN;
            int col = pos % BITSET_LEN;
            col = BITSET_LEN - 1 - col;
            // cout << " [" << pos << " " << row << " " << col << " ] ";
            b[BITSET_LEN - 1 - j] = binaryText[row][col];
        }

        // cout << endl;

        initialPermutationText.push_back(b);
    }

    return initialPermutationText;
}

void printPermutation(vector<bitset<BITSET_LEN>> initialPermutationText)
{

    for (int i = 0; i < initialPermutationText.size(); i++) {
        cout << initialPermutationText[i] << endl;
    }
}

string leftShifNTimes(string s, int n)
{

    for (int i = 0 ; i < n ; i++)
    {
        string temp =  s.substr(1, s.length() - 1) + s.front();
        s = temp;
    }
    

    return s;
}
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string plainText;

    cin >> plainText;

    vector<bitset<BITSET_LEN>> binaryText;

    for (int i = 0; i < plainText.length(); i++) {
        bitset<BITSET_LEN> b(plainText[i]);
        binaryText.push_back(b);

        cout << plainText[i] << " " << b << endl;
    }

    // The input text is turned to 64 bit block(s) and for padding, 0x80 (10000000) is used.

    int padding = BITSET_LEN - (binaryText.size() % BITSET_LEN);
    for (int i = 0; i < padding; i++) {
        bitset<BITSET_LEN> b(0x80);
        binaryText.push_back(b);

        
    }

    // print the binary text
    // int cnt = 0;
    cout << "Binary Text: \n";
    printPermutation(binaryText);

    /*

    00110100
    00101101
    10110101
    10101000
    00011101
    11011011
    10010000
    00000100


    use it as the example key
    */

    vector<int> keyArr = {
        0x34, 0x2D, 0xB5, 0xA8, 0x1D, 0xDB, 0x90, 0x04
    };

    vector<bitset<BITSET_LEN>> key;

    for (int i = 0; i < keyArr.size(); i++) {
        bitset<BITSET_LEN> b(keyArr[i]);
        key.push_back(b);
    }

    cout << "\nKey: \n";
    printPermutation(key);

    vector<vector<int>> initialPermutation = {
        { 58, 50, 42, 34, 26, 18, 10, 2 },
        { 60, 52, 44, 36, 28, 20, 12, 4 },
        { 62, 54, 46, 38, 30, 22, 14, 6 },
        { 64, 56, 48, 40, 32, 24, 16, 8 },
        { 57, 49, 41, 33, 25, 17, 9, 1 },
        { 59, 51, 43, 35, 27, 19, 11, 3 },
        { 61, 53, 45, 37, 29, 21, 13, 5 },
        { 63, 55, 47, 39, 31, 23, 15, 7 }
    };

    vector<bitset<BITSET_LEN>> initialPermutationText, keyPermutationText;

    initialPermutationText = getPermutated(initialPermutation, binaryText);

    // print the initial permutation text

    cout << "\nInitial Permutation Text: \n";

    printPermutation(initialPermutationText);

    vector<vector<int>> PC1 = {
        { 57, 49, 41, 33, 25, 17, 9 },
        { 1, 58, 50, 42, 34, 26, 18 },
        { 10, 2, 59, 51, 43, 35, 27 },
        { 19, 11, 3, 60, 52, 44, 36 },
        { 63, 55, 47, 39, 31, 23, 15 },
        { 7, 62, 54, 46, 38, 30, 22 },
        { 14, 6, 61, 53, 45, 37, 29 },
        { 21, 13, 5, 28, 20, 12, 4 }
    };

    keyPermutationText = getPermutated(PC1, key);

    string C, D;

    for (int i = 0; i < keyPermutationText.size(); i++) {
        if (i < 4) {
            C += keyPermutationText[i].to_string();
            // remove the last element of C
            C.pop_back();
        } else {
            D += keyPermutationText[i].to_string();
            // remove the last element of D
            D.pop_back();
        }
    }

    cout << "\nKEY PERMUTAION " << endl;

    printPermutation(keyPermutationText);



    // now left shift C and D

    vector<int> leftShift = {
        0 , 1, 1, 2, 2, 2, 2, 2, 2,
        1, 2, 2, 2, 2, 2, 2, 1
    };

    vector<string> CShift, DShift;

    CShift.push_back(C);
    DShift.push_back(D);

    cout << "\nC and D after left shift: \n";

    for (int i = 1; i < leftShift.size(); i++) {

        

        string tempC = leftShifNTimes(CShift[i-1], leftShift[i]);
        string tempD = leftShifNTimes(DShift[i-1], leftShift[i]);

        cout << tempC << " " << tempD << endl;

         CShift.push_back(tempC);
         DShift.push_back(tempD);
    }

    return 0;
}