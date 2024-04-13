#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    string str = s;
    reverse(str.begin(), str.end());
    if(str == s) cout << "Yes";
    else cout << "No";

    return 0;
}
