#include <bits/stdc++.h>
using namespace std;
vector<string> MATRIX, REARRANGED_MATRIX;
int ROWS = 0;
string KEY, PLAINTEXT = "";
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

   
    int keyLength = KEY.length();
    int plainTextLength = PLAINTEXT.length();
    for (int i = 0, k = 0; i < ROWS; i++) {
        for (int j = 0; j < keyLength; j++) {


            while (k < plainTextLength && !isalnum(PLAINTEXT[k])) {
                k++;
            }

            MATRIX[i][j] = (k < PLAINTEXT.length()) ? PLAINTEXT[k++] : 'x';
        }
    }
}
void rearrangeTheMatrix()
{

    vector<pair<int, int>> keyWithIndex;
    for (int i = 0; i < KEY.length(); ++i) {
        keyWithIndex.push_back({i, KEY[i] - '0'});

       // cout << "i " << i << " key " << KEY[i] - '0' << endl;
    }

    
   // sort(keyWithIndex.begin(), keyWithIndex.end());

    for (int i = 0; i < KEY.length(); i++)
        cout << keyWithIndex[i].second << " ";

    for (int i = 0; i < KEY.length(); i++) {
        int col = keyWithIndex[i].second - 1;
        for (int j = 0; j < ROWS; j++) {
            int row = j;
            REARRANGED_MATRIX[row][i] = MATRIX[row][col];
        }
    }
}
string applyRowTransposition()
{
    ROWS = ceil((double)PLAINTEXT.length() / KEY.length());
    MATRIX.resize(ROWS, string(KEY.length(), ' '));
    REARRANGED_MATRIX.resize(MATRIX.size(), string(KEY.length(), ' '));
    

    fillTheMatrixWithPlainText();

    rearrangeTheMatrix();

    cout << endl;
    printMatrix(MATRIX);

    cout << endl;
    printMatrix(REARRANGED_MATRIX);

    string cipher;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < KEY.length(); j++) {
            cipher += REARRANGED_MATRIX[i][j];
        }
    }

    return cipher;
}
int main()
{

    cin >> KEY;

    string s;

    while (cin >> s) {
        PLAINTEXT += s;
    }

    string cipherText = applyRowTransposition();
    cout << "\n"
         << cipherText << endl;
}

// Sample input : 41532  the simplest possible transpositions
// Sample Output :

/*
4 1 5 3 2
4 1 5 3 2
t h e s i
m p l e s
t p o s s
i b l e t
r a n s p
o s i t i
o n s x x

s t i e h
e m s l p
s t s o p
e i t l b
s r p n a
t o i i s
x o x s n

stiehemslpstsopeitlbsrpnatoiisxoxsn
*/
