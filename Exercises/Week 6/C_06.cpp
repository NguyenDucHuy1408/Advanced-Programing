#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

bool ntcn(int a, int b) {
    return gcd(a, b) == 1;
}

int main() {
    int a, b;
    cin >> a >> b;
    if(ntcn(a, b)) cout << "YES!";
    else cout << "NO!";

    return 0;
}
