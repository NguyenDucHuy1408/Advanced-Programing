#include <bits/stdc++.h>
using namespace std;

bool prime(int num) {
    for(int i = 2; i <= sqrt(num); i++)
        if(num % i == 0) return false;
    return num >= 2;
}

void print(int n) {
    for(int i = 2; i <= n; i++)
        if(prime(i)) cout << i << ' ';
}

int main() {
    int n; cin >> n;
    print(n);

    return 0;
}
