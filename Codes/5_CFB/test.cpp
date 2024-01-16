#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

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

string performBitSelectionOperation(string e, vector<string> selectedArray)
{

    string result = "";

    int size = selectedArray.size();

    for (int i = 0; i < size; i++) {
        result += e[stoi(selectedArray[i])];
    }

    return result;
}

string E_bit_selection(string e)
{

    string result = "", r;
    for (int i = 32; i < 64; i++) {
        r += e[i];
    }

    result = performBitSelectionOperation(r, E_BIT_SELECTION_ARRAY);
    return result;
}

int giveColumn(string (&xor_res_arr)[6])
{
    // int *col = new int[16];
    // int co = 0;
    int col;
    // string res = xor_res_arr[1] + xor_res_arr[2] + xor_res_arr[3] + xor_res_arr[4];

    // int val = stoi(res, nullptr, 2);

    // if (val > 15) {
    //     return 0;
    // }

    // return val;

    if (xor_res_arr[1] == "0" && xor_res_arr[2] == "0" && xor_res_arr[3] == "0" && xor_res_arr[4] == "0") {
        col = 0;
        return col;
    }
    if (xor_res_arr[1] == "0" && xor_res_arr[2] == "0" && xor_res_arr[3] == "0" && xor_res_arr[4] == "1") {
        col = 1;
        return col;
    }
    if (xor_res_arr[1] == "0" && xor_res_arr[2] == "0" && xor_res_arr[3] == "1" && xor_res_arr[4] == "0") {
        col = 2;
        return col;
    }
    if (xor_res_arr[1] == "0" && xor_res_arr[2] == "0" && xor_res_arr[3] == "1" && xor_res_arr[4] == "1") {
        col = 3;
        return col;
    }
    if (xor_res_arr[1] == "0" && xor_res_arr[2] == "1" && xor_res_arr[3] == "0" && xor_res_arr[4] == "") {
        col = 4;
        return col;
    }
    if (xor_res_arr[1] == "0" && xor_res_arr[2] == "1" && xor_res_arr[3] == "0" && xor_res_arr[4] == "1") {
        col = 5;
        return col;
    }
    if (xor_res_arr[1] == "0" && xor_res_arr[2] == "1" && xor_res_arr[3] == "1" && xor_res_arr[4] == "0") {
        col = 6;
        return col;
    }
    if (xor_res_arr[1] == "0" && xor_res_arr[2] == "1" && xor_res_arr[3] == "1" && xor_res_arr[4] == "1") {
        col = 7;
        return col;
    }
    if (xor_res_arr[1] == "1" && xor_res_arr[2] == "0" && xor_res_arr[3] == "0" && xor_res_arr[4] == "0") {
        col = 8;
        return col;
    }
    if (xor_res_arr[1] == "1" && xor_res_arr[2] == "0" && xor_res_arr[3] == "0" && xor_res_arr[4] == "1") {
        col = 9;
        return col;
    }
    if (xor_res_arr[1] == "1" && xor_res_arr[2] == "0" && xor_res_arr[3] == "1" && xor_res_arr[4] == "0") {
        col = 10;
        return col;
    }
    if (xor_res_arr[1] == "1" && xor_res_arr[2] == "0" && xor_res_arr[3] == "1" && xor_res_arr[4] == "1") {
        col = 11;
        return col;
    }
    if (xor_res_arr[1] == "1" && xor_res_arr[2] == "1" && xor_res_arr[3] == "0" && xor_res_arr[4] == "0") {
        col = 12;
        return col;
    }
    if (xor_res_arr[1] == "1" && xor_res_arr[2] == "1" && xor_res_arr[3] == "0" && xor_res_arr[4] == "1") {
        col = 13;
        return col;
    }
    if (xor_res_arr[1] == "1" && xor_res_arr[2] == "1" && xor_res_arr[3] == "1" && xor_res_arr[4] == "0") {
        col = 14;
        return col;
    }
    if (xor_res_arr[1] == "1" && xor_res_arr[2] == "1" && xor_res_arr[3] == "1" && xor_res_arr[4] == "1") {
        col = 15;
        return col;
    }
    return 0;
}

int32_t main()
{
    string str;
    cin >> str;

    cout << E_bit_selection(str) << endl;

    string temp = "01011";
    cout << stoi(temp , nullptr ,2) << endl;
    std::string myArray[6] = {"001", "010", "011", "100", "101", "110"};
    cout << giveColumn(myArray) << endl;

    cout << bitset<4>(17) << endl;

    return 0;
}