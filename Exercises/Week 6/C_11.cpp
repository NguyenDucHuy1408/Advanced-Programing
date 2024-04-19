#include <bits/stdc++.h>
using namespace std;

string intToBin(int num) {
    string s;
    while(num) {
        s = to_string(num & 1) + s;
        num >>= 1;
    }
    return s;
}

int binToInt(string s) {
    int pow = 1;
    int num = 0;
    for(int i = (int)s.size() - 1; i >= 0; i--) {
        if(s[i] == '1') num += pow;
        pow *= 2;
    }
    return num;
}

int main() {
    int n; cin >> n;
    cout << intToBin(n);
    cout << endl;
    string s; cin >> s;
    cout << binToInt(s);
    return 0;
}