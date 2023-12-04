#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int

int PUBLIC_KEY;
int PPRIVATE_KEY;
int n;
void viewInformation(int p, int q, int n, int PHI, int e, int d)
{
    cout << "Prime 1 (p) = " << p << endl;
    cout << "Prime 2 (q) = " << q << endl;
    cout << "n (n) = " << n << endl;
    cout << "PHI (phi) = " << PHI << endl;
    cout << "Public Key (e) = " << e << endl;
    cout << "Private Key (d) = " << d << endl;
}
void init()
{
    int p, q;

    cin >> p >> q;

    n = p * q;
    int PHI = (p - 1) * (q - 1);
    int e = 2;
    while (true) {
        if (__gcd(e, PHI) == 1)
            break;
        e++;
    }
    PUBLIC_KEY = e;
    int d = 2;
    while (true) {
        if ((d * e) % PHI == 1)
            break;
        d++;
    }
    PPRIVATE_KEY = d;

    viewInformation(p, q, n, PHI, e, d);
}

ll modVal(int key, int message, int n)
{
    ll text = 1;
    while (key--) {
        text *= message;
        text %= n;
    }
    return text;
}

vector<int> encrypt(string message)
{
    vector<int> form;
    for (int i = 0; i < message.size(); i++)
        form.push_back(modVal(PUBLIC_KEY, message[i], n));
    return form;
}

string decrypt(vector<int> encoded)
{
    string s;
    for (int i = 0; i < encoded.size(); i++)
        s.push_back(modVal(PPRIVATE_KEY, encoded[i], n));
    return s;
}

int main()
{

    init();
    string message;
    cin.ignore();
    getline(cin, message);
    vector<int> coded = encrypt(message);
    cout << "Initial message:" << endl;
    cout << message;
    cout << endl;
    cout << endl;
    cout << "The encoded message (encrypted by public key)" << endl;
    for (int i = 0; i < coded.size(); i++)
        cout << coded[i];
    cout << endl;
    cout << "The decoded message (decrypted by private key)" << endl;
    cout << decrypt(coded) << endl;
    return 0;
}

/*
Sample Input : 
587 599
Chilling with friends

Sample Output :
Prime 1 (p) = 73
Prime 2 (q) = 151
n (n) = 11023
PHI (phi) = 10800
Public Key (e) = 7
Private Key (d) = 1543
Initial message:
Chilling with friends

The encoded message (encrypted by public key)
1089664838404173417384031431066518361598403205648318345607847840519431437767679
The decoded message (decrypted by private key)
Chilling with friends

*/