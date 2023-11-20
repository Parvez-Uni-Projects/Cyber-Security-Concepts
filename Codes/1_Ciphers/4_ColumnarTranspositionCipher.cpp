#include <bits/stdc++.h>
using namespace std;
string KEY, PLAINTEXT;

int ROWS = 0;
vector<string> MATRIX;
vector<pair<int, int>> INDEX;
map<char, int> CHAR_NUMBER;
void printMatrix(const vector<string>& MATRIX)
{
    for (string row : MATRIX) {
        for (char ch : row) {
            cout << ch << " ";
        }
        cout << endl;
    }
}

void fillTheMatrixWithPlainText()
{
    for (int i = 0, k = 0; i < ROWS; ++i) {
        for (int j = 0; j < KEY.length(); ++j) {
            while (k < PLAINTEXT.length() && !isalnum(PLAINTEXT[k])) {
                k++;
            }

            MATRIX[i][j] = (k < PLAINTEXT.length()) ? PLAINTEXT[k++] : 'x';
        }
    }
}

void rearrangeTheMatrix()
{

    string tempkey = KEY;
    sort(tempkey.begin(), tempkey.end());
    for (int i = 0; i < KEY.length(); ++i) {
        CHAR_NUMBER[tempkey[i]] = i + 1;
    }

    vector<pair<int, char>> INDEXED_KEY;
    for (int i = 0; i < KEY.length(); ++i) {
        INDEXED_KEY.push_back({ CHAR_NUMBER[KEY[i]], KEY[i] });
    }

    for (int i = 0; i < KEY.length(); ++i) {
        INDEX.push_back({ CHAR_NUMBER[KEY[i]], i + 1 });
    }

    sort(INDEX.begin(), INDEX.end());
}

string applyColumnarTransposition()
{

    ROWS = ceil((double)(PLAINTEXT.length()) / KEY.length());
    MATRIX.resize(ROWS, string(KEY.length(), ' '));

    fillTheMatrixWithPlainText();
    rearrangeTheMatrix();

    printMatrix(MATRIX);

    string cipherText;
    for (int i = 0; i < KEY.length(); i++) {
        for (int j = 0; j < ROWS; j++) {
            cipherText += MATRIX[j][INDEX[i].second - 1];
        }
    }

    return cipherText;
}

int main()
{

    cin >> KEY >> PLAINTEXT;

    string s;

    while (cin >> s) {
        PLAINTEXT += s;
    }

    string cipherText = applyColumnarTransposition();
    cout << "\n"
         << cipherText << endl;
}

// Sample Input : HACK meet me after the party
// Sample Output :

/*
m e e t
m e a f
t e r t
h e p a
r t y x

eeeetearpymmthrtftax
*/
