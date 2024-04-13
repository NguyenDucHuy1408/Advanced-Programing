#include <bits/stdc++.h>

using namespace std;

int main() {
    map<int, int> mp;
    int n; cin >> n;
    while(n--) {
        int x; cin >> x;
        mp[x]++;
    }
    for(auto it : mp) {
        if(it.second >= 2) {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
    return 0;
}
