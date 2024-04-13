#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    int a[n];
    int MAX = INT_MIN, MIN = INT_MAX;
    int sum = 0, cnt = 0;
    for(int &x : a) {
        cin >> x;
        MAX = max(x, MAX);
        MIN = min(MIN, x);
        if(x % 2) cnt++;
        else sum += x;
    }
    cout << MAX << endl << MIN << endl << sum << endl << cnt;
    return 0;
}