#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
void solve(string s) {


    
   

    // right shift each cahracter by 5
    for (int i = 0 ; i  <s.size()  ; i++)
    {
       
        int x = s[i] - 'a';
        x = (x + 5) % 26;
        s[i] = x + 'a';

    }

    cout << s << " ";
 }
int32_t main()
{

    ios_base::sync_with_stdio(false);

    string s;

    while (cin >> s)
    {
        solve(s);
    }
    
    return 0;
}