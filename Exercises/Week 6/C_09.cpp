#include <bits/stdc++.h>
using namespace std;

int rand(int n) {
    return rand() % n;
}

int main() {
    srand(time(0));
    int n; cin >> n;
    cout << rand(n);
    return 0;
}