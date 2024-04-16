#include <bits/stdc++.h>
using namespace std;

vector<int> pascal(int n, vector<int> v) {
    vector<int> ans(n, 1);
    for(int i = 1; i < n - 1; i++) {
        ans[i] = v[i] + v[i - 1];
    }
    return ans;
}

int main() {
    int n; cin >> n;
    vector<vector<int>> vvi(n);
    vvi[0].resize(1, 1);
    for(int i = 2; i <= n; i++) {
        vvi[i - 1] = pascal(i, vvi[i - 2]);
    }
    for(auto vt : vvi) {
        for(auto x : vt) {
            cout << x << ' ';
        }
        cout << '\n';
    }
    return 0;
}