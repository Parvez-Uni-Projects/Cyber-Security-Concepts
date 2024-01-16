#include <bits/stdc++.h>
using namespace std;
#define subBox vector<vector<int>>
#define endl "\n"

const vector<subBox> SUB_BOX = {

    { { 14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7 },
        { 0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8 },
        { 4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0 },
        { 15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13 } }, // s1
    {
        { 15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10 },
        { 3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5 },
        { 0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15 },
        { 13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9 } }, // s2

    {
        { 10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8 },
        { 13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1 },
        { 13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7 },
        { 1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12 } }, // s3

    {
        { 7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15 },
        { 13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9 },
        { 10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4 },
        { 3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14 } }, // s4

    {
        { 2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9 },
        { 14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6 },
        { 4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14 },
        { 11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3 } }, // s5

    {
        { 12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11 },
        { 10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8 },
        { 9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6 },
        { 4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13 } }, // s6

    {
        { 4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1 },
        { 13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6 },
        { 1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2 },
        { 6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12 } }, // s7

    {
        { 13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7 },
        { 1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2 },
        { 7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8 },
        { 2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11 } } // s8
};

vector<string> E_BIT_SELECTION_ARRAY = {
    "31", "0", "1", "2", "3", "4",
    "3", "4", "5", "6", "7", "8",
    "7", "8", "9", "10", "11", "12",
    "11", "12", "13", "14", "15", "16",
    "15", "16", "17", "18", "19", "20",
    "19", "20", "21", "22", "23", "24",
    "23", "24", "25", "26", "27", "28",
    "27", "28", "29", "30", "31", "0"
};
vector<string> PC_2_ARRAY = {
    "13", "16", "10", "23", "0", "4",
    "2", "27", "14", "5", "20", "9",
    "22", "18", "11", "3", "25", "7",
    "15", "6", "26", "19", "12", "1",
    "40", "51", "30", "36", "46", "54",
    "29", "39", "50", "44", "32", "47",
    "43", "48", "38", "55", "33", "52",
    "45", "41", "49", "35", "28", "31"
};
vector<string> PC_1_ARRAY = {
    "56", "48", "40", "32", "24", "16", "8", "0",
    "57", "49", "41", "33", "25", "17", "9",
    "1", "58", "50", "42", "34", "26", "18",
    "10", "2", "59", "51", "43", "35", "62",
    "54", "46", "38", "30", "22", "14", "6",
    "61", "53", "45", "37", "29", "21", "13",
    "5", "60", "52", "44", "36", "28", "20",
    "12", "4", "27", "19", "11", "3"
};
vector<string> IP_CAL_ARRAY = {
    "57", "49", "41", "33", "25", "17", "9", "1",
    "59", "51", "43", "35", "27", "19", "11", "3",
    "61", "53", "45", "37", "29", "21", "13", "5",
    "63", "55", "47", "39", "31", "23", "15", "7",
    "56", "48", "40", "32", "24", "16", "08", "0",
    "58", "50", "42", "34", "26", "18", "10", "2",
    "60", "52", "44", "36", "28", "20", "12", "4",
    "62", "54", "46", "38", "30", "22", "14", "6"
};
vector<string> SUB_BOX_PERMUTAION_ARRAY = {
    "15",
    "6",
    "19",
    "20",
    "28",
    "11",
    "27",
    "16",
    "0",
    "14",
    "22",
    "25",
    "4",
    "17",
    "30",
    "9",
    "1",
    "7",
    "23",
    "13",
    "31",
    "26",
    "2",
    "8",
    "18",
    "12",
    "29",
    "5",
    "21",
    "10",
    "3",
    "24",
};

vector<string> INVERSE_INITIAL_PERMUTATION_ARRAY = {
    "39", "7", "47", "15", "55", "23", "63", "31",
    "38", "6", "46", "14", "54", "22", "62", "30",
    "37", "5", "45", "13", "53", "21", "61", "29",
    "36", "4", "44", "12", "52", "20", "60", "28",
    "35", "3", "43", "11", "51", "19", "59", "27",
    "34", "2", "42", "10", "50", "18", "58", "26",
    "33", "1", "41", "9", "49", "17", "57", "25",
    "32", "0", "40", "8", "48", "16", "56", "24"
};
int getSubBoxVal(int i, int row, int col)
{
    return SUB_BOX[i][row][col];
}

string performXOR(string v, string q, int len)
{
    string result = "";

    for (int i = 0; i < len; i++)
        result += (v[i] == q[i]) ? '0' : '1';

    return result;
}

string XORwithSubkey(string v, string q)
{
    return performXOR(v, q, 48);
}

string performBitSelectionOperation(string e, vector<string> selectedArray)
{

    string result = "";

    for (int i = 0; i < selectedArray.size(); i++) {
        result += e[stoi(selectedArray[i])];
    }

    return result;
}

string E_bit_selection(string e)
{

    string r;
    for (int i = 32; i < 64; i++) {
        r += e[i];
    }

    return performBitSelectionOperation(r, E_BIT_SELECTION_ARRAY);
}

string pc_2(string pc2)
{

    return performBitSelectionOperation(pc2, PC_2_ARRAY);
}

string leftShift(string cdls, int n)
{
    string cls, dls;

    for (int i = 0; i < cdls.length(); i++) {
        if (i < 28) {
            cls += cdls[i];
        } else {
            dls += cdls[i];
        }
    }

    if (n == 0 || n == 1 || n == 8 || n == 15) {
        char temp1 = cls[0];
        char temp3 = dls[0];

        for (int i = 0; i < 28; i++) {
            if (i < 27) {
                cls[i] = cls[i + 1];
                dls[i] = dls[i + 1];
            } else if (i == 27) {
                cls[i] = temp1;
                dls[i] = temp3;
            }
        }
    } else {
        for (int i = 0; i < 2; i++) {
            char temp1 = cls[0];
            char temp3 = dls[0];

            for (int i = 0; i < 28; i++) {
                if (i < 27) {
                    cls[i] = cls[i + 1];
                    dls[i] = dls[i + 1];
                } else if (i == 27) {
                    cls[i] = temp1;
                    dls[i] = temp3;
                }
            }
        }
    }

    return cls + dls;
}
string C = "", D = "";
string pc_1(string pc)
{

    for (int i = 0; i < 56; i++) {
        if (i <= 27) {
            string t;
            t = PC_1_ARRAY[i];
            int x = stoi(t);
            C += pc[x];
            t.clear();
        } else {
            string t;
            t = PC_1_ARRAY[i];
            int x = stoi(t);
            D += pc[x];
            t.clear();
        }
    }

    return (C + D);
}

string ip_cal(string ip)
{
    return performBitSelectionOperation(ip, IP_CAL_ARRAY);
}

string getBinaryofLen_8(int k)
{
    if (k > 255) {
        cout << "Invalid input" << endl;
        return "00000000";
    }
    return bitset<8>(k).to_string();
}

string convertKeyToBinary(int k[])
{
    string rev;
    for (int i = 0; i < 8; i++) {
        rev += getBinaryofLen_8(k[i]);
    }
    return rev;
}

string convertToBinary(string s)
{
    int length = s.length();
    string rev;

    for (int i = 0; i < length; i++) {
        rev += getBinaryofLen_8(s[i]);
    }

    if (rev.length() < 64) {
        int y = 64 - rev.length();
        for (int i = 0; i < y; i++) {
            if (rev.length() < 64) {
                rev += "10000000";
            }
        }
    } else {
        while (rev.length() % 64 != 0) {
            rev += "10000000";
        }
    }

    return rev;
}
int binaryStringToInt(string s)
{
    int ans = 0;
    for (int i = 0; i < s.length(); i++) {
        ans = ans * 2 + (s[i] - '0');
    }
    return ans;
}

// takes the expected result and checks if it is in the vector
// if it is in the vector then it returns the integer of the result else it returns 0
int getIndice(string result, vector<string> v)
{
    return find(v.begin(), v.end(), result) != v.end() ? binaryStringToInt(result) : 0;
}

int giveRow(string (&xor_res_arr)[6])
{

    vector<string> v = { "00", "01", "10", "11" };
    string result = xor_res_arr[0] + xor_res_arr[5];

    return getIndice(result, v);
}

int giveColumn(string (&xor_res_arr)[6])
{

    string result = xor_res_arr[1] + xor_res_arr[2] + xor_res_arr[3] + xor_res_arr[4];

    vector<string> v = { "0000", "0001", "0010", "0011", "010", "0101", "0110",
        "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111" };

    return getIndice(result, v);
}

string convetSValues(int x[])
{
    string t, rev;
    for (int i = 0; i < 8; i++) {
        int k = x[i], ct = 0;
        t = bitset<4>(k).to_string();
        rev += t;
        t.clear();
    }
    return rev;
}

string SBoxPermutation(string sp)
{
    return performBitSelectionOperation(sp, SUB_BOX_PERMUTAION_ARRAY);
}

string XORLeftandRight(string first, string second)
{
    string res_xor, cls;

    for (int i = 0; i < 32; i++) {
        cls += first[i];
    }

    res_xor = performXOR(cls, second, 32);

    return res_xor;
}

string afterXORLR(string first, string second)
{
    string res_afterXORLR;
    for (int i = 32; i < 64; i++) {
        res_afterXORLR += first[i];
    }
    for (int i = 0; i < 32; i++) {
        res_afterXORLR += second[i];
    }

    return res_afterXORLR;
}

string InverseInitialPermutation(string b)
{
    return performBitSelectionOperation(b, INVERSE_INITIAL_PERMUTATION_ARRAY);
}

string swap(string s)
{
    string swap;

    for (int i = 32; i < 64; i++) {
        swap += s[i];
    }
    for (int i = 0; i < 32; i++) {
        swap += s[i];
    }
    return swap;
}

string xorWithPlaintext(string first, string second)
{
    return performXOR(first, second, 32);
}

void Decryption(string ivAfterBinary, string plaintextAftBin, string keyAfterBinary, string cipherText)
{
    string ip_result = ip_cal(ivAfterBinary);

    string pc_1_result = pc_1(keyAfterBinary);

    string subKeys[16], g;

    for (int i = 0; i < 16; i++) {
        subKeys[i] = (i == 0) ? leftShift(pc_1_result, i) : leftShift(g, i);
        g = subKeys[i];
    }

    string pc_2_result[16];
    for (int i = 0; i < 16; i++) {
        pc_2_result[i] = pc_2(subKeys[i]);
    }
    cout << "All keys: " << endl;
    for (int i = 0; i < 16; i++) {
        cout << pc_2_result[i] << endl;
    }
    cout << endl;
    string SvaluesAfterBinary;
    string SBoxPermuteResult;
    string XORLeftandRightResult;
    string main_s_permute;
    string afterXORLRResult[16];
    string e_result;
    string xor_result;
    string xor_res_arr[8][6];
    string rev_S_permatution[8][4];
    int sbox_result[8];
    int row1[8], col1[8];
    int t = 15;
    string ip_result2 = ip_cal(ivAfterBinary);
    for (int i = 0; i < 16; i++) {

        if (i == 0) {
            e_result = E_bit_selection(ip_result2);

            int p = 0;

            xor_result = XORwithSubkey(e_result, pc_2_result[i]);
            t--;

            for (int j = 0; j < 8; j++) {
                for (int k = 0; k < 6; k++) {
                    xor_res_arr[j][k] = xor_result[p];
                    p++;
                }
            }

            for (int u = 0; u < 8; u++) {
                row1[u] = giveRow(xor_res_arr[u]);
            }
            for (int u = 0; u < 16; u++) {
                col1[u] = giveColumn(xor_res_arr[u]);
            }

            for (int l = 0; l < 8; l++) {
                sbox_result[l] = getSubBoxVal(l, row1[l], col1[l]);
            }

            SvaluesAfterBinary = convetSValues(sbox_result);

            SBoxPermuteResult = SBoxPermutation(SvaluesAfterBinary);

            int b = 0;
            for (int x = 0; x < 8; x++) {
                for (int y = 0; y < 4; y++) {
                    rev_S_permatution[x][y] = SBoxPermuteResult[b];
                    b++;
                }
            }
            for (int c = 0; c < 4; c++) {
                for (int r = 7; r <= 0; r--) {
                    main_s_permute += rev_S_permatution[r][c];
                }
            }

            XORLeftandRightResult = XORLeftandRight(ip_result, main_s_permute);

            afterXORLRResult[i] = afterXORLR(ip_result2, XORLeftandRightResult);
            cout << "Round (";
            cout << i + 1;
            cout << "): ";
            cout << afterXORLRResult[i] << endl;
        } else {
            e_result = E_bit_selection(afterXORLRResult[i - 1]);

            int p = 0;

            xor_result = XORwithSubkey(e_result, pc_2_result[i]);
            t--;

            for (int j = 0; j < 8; j++) {
                for (int k = 0; k < 6; k++) {
                    xor_res_arr[j][k] = xor_result[p];
                    p++;
                }
            }

            for (int u = 0; u < 8; u++) {
                row1[u] = giveRow(xor_res_arr[u]);
            }
            for (int u = 0; u < 16; u++) {
                col1[u] = giveColumn(xor_res_arr[u]);
            }

            for (int l = 0; l < 8; l++) {
                sbox_result[l] = getSubBoxVal(l, row1[l], col1[l]);
            }
            SvaluesAfterBinary = convetSValues(sbox_result);

            SBoxPermuteResult = SBoxPermutation(SvaluesAfterBinary);

            int b = 0;
            for (int x = 0; x < 8; x++) {
                for (int y = 0; y < 4; y++) {
                    rev_S_permatution[x][y] = SBoxPermuteResult[b];
                    b++;
                }
            }
            for (int c = 0; c < 4; c++) {
                for (int r = 7; r <= 0; r--) {
                    main_s_permute += rev_S_permatution[r][c];
                }
            }

            XORLeftandRightResult = XORLeftandRight(afterXORLRResult[i - 1], SBoxPermuteResult);

            afterXORLRResult[i] = afterXORLR(afterXORLRResult[i - 1], XORLeftandRightResult);
            cout << "Round (";
            cout << i + 1;
            cout << "): ";
            cout << afterXORLRResult[i] << endl;
        }
    }
    string swapResult2 = swap(afterXORLRResult[15]);
    string InverseInitialPermutationResult2 = InverseInitialPermutation(afterXORLRResult[15]);
    cout << endl;
    string plainText = xorWithPlaintext(InverseInitialPermutationResult2, cipherText);
    cout << "Final plaint text: ";
    cout << plainText;
    cout << endl;
    cout << endl;
}

string Encryption(string ivAfterBinary, string plaintextAftBin, string keyAfterBinary)
{
    string ip_result = ip_cal(ivAfterBinary);

    string pc_1_result = pc_1(keyAfterBinary);

    string subKeys[16], g;

    for (int i = 0; i < 16; i++) {
        if (i == 0) {
            subKeys[i] = leftShift(pc_1_result, i);
            g = subKeys[i];
        } else {
            subKeys[i] = leftShift(g, i);
            g = subKeys[i];
        }
    }

    string pc_2_result[16];
    for (int i = 0; i < 16; i++) {
        pc_2_result[i] = pc_2(subKeys[i]);
    }
    cout << "All keys: " << endl;
    for (int i = 0; i < 16; i++) {
        cout << pc_2_result[i] << endl;
    }
    cout << endl;
    string SvaluesAfterBinary;
    string SBoxPermuteResult;
    string XORLeftandRightResult;
    string main_s_permute;
    string afterXORLRResult[16];
    string e_result;
    string xor_result;
    string xor_res_arr[8][6];
    string rev_S_permatution[8][4];
    int sbox_result[8];
    int row1[8], col1[8];
    int t = 15;

    for (int i = 0; i < 16; i++) {

        if (i == 0) {
            e_result = E_bit_selection(ip_result);

            int p = 0;

            xor_result = XORwithSubkey(e_result, pc_2_result[i]);

            for (int j = 0; j < 8; j++) {
                for (int k = 0; k < 6; k++) {
                    xor_res_arr[j][k] = xor_result[p];
                    p++;
                }
            }

            for (int u = 0; u < 8; u++) {
                row1[u] = giveRow(xor_res_arr[u]);
            }
            for (int u = 0; u < 8; u++) {
                col1[u] = giveColumn(xor_res_arr[u]);
            }

            for (int l = 0; l < 8; l++) {
                sbox_result[l] = getSubBoxVal(l, row1[l], col1[l]);
            }

            SvaluesAfterBinary = convetSValues(sbox_result);

            SBoxPermuteResult = SBoxPermutation(SvaluesAfterBinary);
            int b = 0;
            for (int x = 0; x < 8; x++) {
                for (int y = 0; y < 4; y++) {
                    rev_S_permatution[x][y] = SBoxPermuteResult[b];
                    b++;
                }
            }
            for (int c = 0; c < 4; c++) {
                for (int r = 7; r >= 0; r--) {
                    main_s_permute += rev_S_permatution[r][c];
                }
            }
            XORLeftandRightResult = XORLeftandRight(ip_result, main_s_permute);

            afterXORLRResult[i] = afterXORLR(ip_result, XORLeftandRightResult);
            cout << "Round (";
            cout << i + 1;
            cout << "): ";
            cout << afterXORLRResult[i] << endl;
        } else {
            e_result = E_bit_selection(afterXORLRResult[i - 1]);

            int p = 0;

            xor_result = XORwithSubkey(e_result, pc_2_result[i]);

            for (int j = 0; j < 8; j++) {
                for (int k = 0; k < 6; k++) {
                    xor_res_arr[j][k] = xor_result[p];
                    p++;
                }
            }

            for (int u = 0; u < 8; u++) {
                row1[u] = giveRow(xor_res_arr[u]);
            }
            for (int u = 0; u < 8; u++) {
                col1[u] = giveColumn(xor_res_arr[u]);
            }

            for (int l = 0; l < 8; l++) {
                sbox_result[l] = getSubBoxVal(l, row1[l], col1[l]);
            }
            SvaluesAfterBinary = convetSValues(sbox_result);

            SBoxPermuteResult = SBoxPermutation(SvaluesAfterBinary);

            int b = 0;
            for (int x = 0; x < 8; x++) {
                for (int y = 0; y < 4; y++) {
                    rev_S_permatution[x][y] = SBoxPermuteResult[b];
                    b++;
                }
            }
            for (int c = 0; c < 4; c++) {
                for (int r = 7; r <= 0; r--) {
                    main_s_permute += rev_S_permatution[r][c];
                }
            }
            XORLeftandRightResult = XORLeftandRight(ip_result, main_s_permute);

            afterXORLRResult[i] = afterXORLR(ip_result, XORLeftandRightResult);

            XORLeftandRightResult = XORLeftandRight(afterXORLRResult[i - 1], SBoxPermuteResult);

            afterXORLRResult[i] = afterXORLR(afterXORLRResult[i - 1], XORLeftandRightResult);
            cout << "Round (";
            cout << i + 1;
            cout << "): ";
            cout << afterXORLRResult[i] << endl;
        }
    }
    string swapResult = swap(afterXORLRResult[15]);
    string InverseInitialPermutationResult = InverseInitialPermutation(afterXORLRResult[15]);
    cout << endl;
    string cipherText = xorWithPlaintext(InverseInitialPermutationResult, plaintextAftBin);
    cout << "Final cipher text: ";
    cout << cipherText;
    cout << endl;
    cout << endl;

    return cipherText;
}

int main()
{
    cout << "Enter Initial Vector: ";
    int iv[8], c;
    for (int i = 0; i < 8; i++) {
        cin >> c;
        iv[i] = c;
    }
    string ivAfterBinary = convertKeyToBinary(iv);

    string s;
    cout << "PlainText: ";
    cin >> s;
    string plaintextAftBin = convertToBinary(s);

    cout << "Enter Key: ";
    int key[8], b;
    for (int i = 0; i < 8; i++) {
        cin >> b;
        key[i] = b;
    }
    string keyAfterBinary = convertKeyToBinary(key);

    cout << endl;

    int noOfBlock, ct = 0, j = 0;
    string noOfPlaintext[100];
    noOfBlock = (plaintextAftBin.length() / 64);

    for (int i = 0; i < noOfBlock; i++) {
        for (; j < plaintextAftBin.length();) {
            noOfPlaintext[i] += plaintextAftBin[j];
            int p = j + 1;
            j++;
            if ((p) % 64 == 0) {
                break;
            }
        }
    }

    string a = Encryption(ivAfterBinary, plaintextAftBin, keyAfterBinary);

    Decryption(ivAfterBinary, plaintextAftBin, keyAfterBinary, a);
}

/*
sample input
4 5 7 9 12 15 17 51
parvezRocks
1 2 3 4 5 6 7 8

*/

/*
Enter Initial Vector: PlainText: Enter Key:
All keys:
000000000000000000000000000100110010101010000010
000000000000000000000000000100000010001100000111
000000000000000000000000101101100000000010000100
000000000000000000000000010000000010001111000011
000000000000000000000000001101101010000000001001
000000000000000000000000011000100001010101000010
000000000000000000000000000011001010000100101010
000000000000000000000000011001000101110001000000
000000000000000000000000010010101001100001000000
000000000000000000000000110000001100010100111000
000000000000000000000000000010010001111000001000
000000000000000000000000110110000101000000110000
000000000000000000000000000000010100101000101100
000000000000000000000000100100000011100010010000
000000000000000000000000101000010000001000110101
000000000000000000000000101000110100001010000000

Round (1): 0000000010000000001110001010010011110111111101110100101011111101
Round (2): 1111011111110111010010101111110111010110101000010010010001001000
Round (3): 1101011010100001001001000100100001100100011100000111101100001110
Round (4): 0110010001110000011110110000111010010010011111100110001010010011
Round (5): 1001001001111110011000101001001100110101110001101011101011011011
Round (6): 0011010111000110101110101101101111111100110001010000001010000010
Round (7): 1111110011000101000000101000001000111010000001101000001111110110
Round (8): 0011101000000110100000111111011011110101110010111010011100110111
Round (9): 1111010111001011101001110011011101000101000111101101111000001010
Round (10): 0100010100011110110111100000101010111110001101010100010010011011
Round (11): 1011111000110101010001001001101110111100111010010101010101000110
Round (12): 1011110011101001010101010100011010101001110100100100011100111101
Round (13): 1010100111010010010001110011110100110100110010110111101010001001
Round (14): 0011010011001011011110101000100100011011011011010001011010101101
Round (15): 0001101101101101000101101010110101101101010010111110001101111000
Round (16): 0110110101001011111000110111100000111101111111011000011001101110

Final cipher text: 10000100011111111001100010000101

All keys:
000000000000000000000000000000000000000000000000
000000000000000000000000000000000000000000000000
000000000000000000000000000000000000000000000000
000000000000000000000000000000000000000000000000
000000000000000000000000000000000000000000000000
000000000000000000000000000000000000000000000000
000000000000000000000000000000000000000000000000
000000000000000000000000000000000000000000000000
000000000000000000000000000000000000000000000000
000000000000000000000000000000000000000000000000
000000000000000000000000000000000000000000000000
000000000000000000000000000000000000000000000000
000000000000000000000000000000000000000000000000
000000000000000000000000000000000000000000000000
000000000000000000000000000000000000000000000000
000000000000000000000000000000000000000000000000

Round (1): 0000000010000000001110001010010011111111111111111111111111111111
Round (2): 1111111111111111111111111111111111110011111010101000001111000110
Round (3): 1111001111101010100000111100011010100100110001010101010110100001
Round (4): 1010010011000101010101011010000110110100100000000101000001010011
Round (5): 1011010010000000010100000101001101110001000011011000010100011001
Round (6): 0111000100001101100001010001100110111111001000000000110100010110
Round (7): 1011111100100000000011010001011010111111111001110011100010010000
Round (8): 1011111111100111001110001001000011010111111110001000010101110011
Round (9): 1101011111111000100001010111001100111100010101110011100110100011
Round (10): 0011110001010111001110011010001111100001101100001010010100001100
Round (11): 1110000110110000101001010000110010011000001001100110000100000111
Round (12): 1001100000100110011000010000011101000100001010001100111011001100
Round (13): 0100010000101000110011101100110001111111101110101000101000111111
Round (14): 0111111110111010100010100011111100000001100100111110001010101001
Round (15): 0000000110010011111000101010100111100000010111110100000110111110
Round (16): 1110000001011111010000011011111011001111110010111001011001011101

Final plaint text: 00110010110001100000001100110110

*/
