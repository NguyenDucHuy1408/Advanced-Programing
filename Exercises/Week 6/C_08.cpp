#include <bits/stdc++.h>
using namespace std;

int rnd(double x) {
    if(x - int(x) >= 0.5) return ceil(x);
    return floor(x);
}

int rnd2(double x) {
    return round(x);
}

int main() {
    double x; cin >> x;
    cout << rnd(x);
    cout << endl;
    cout << rnd2(x);
    return 0;
}
