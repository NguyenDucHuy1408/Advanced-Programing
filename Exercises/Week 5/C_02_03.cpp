#include <bits/stdc++.h>

using namespace std;

int main() {
    map<int, int> mp = {{0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}, {7, 0}, {8, 0}, {9, 0}};
    int n; cin >> n;
    while(n--) {
        int x; cin >> x;
        mp[x]++;
    }
    for(auto it : mp) cout << it.first << " : " << it.second << endl;

    return 0;
}