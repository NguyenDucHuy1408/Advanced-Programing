#include <bits/stdc++.h>

using namespace std;

bool sdg(int num) {
    string s = to_string(num);
    reverse(s.begin(), s.end());
    return s == to_string(num);
}

int main() {
    int t; cin >> t;
    while(t--) {
        int a, b; cin >> a >> b;
        int cnt = 0;
        for(int i = a; i <= b; i++) {
            if(sdg(i)) cnt++;
        }
        cout << cnt << endl;
    }

    return 0;
}
