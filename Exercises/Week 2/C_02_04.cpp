#define forx(i, a, b) for(int i=a; i<=b; i++)
#define forn(i, b, a) for(int i=b; i>=a; i--)
#define fora(x, a) for(auto x : a)
#define fi first
#define se second
#define pb push_back
#define ull unsigned long long
#define ll long long

#include <iostream>

using namespace std;

class least_common_multiple {
public:
    void getInput() {
        cin >> a >> b;
    }

    int gcd(int a, int b) {
        if(b == 0) return a;
        return gcd(b, a % b);
    }

    int processing() {
        if(!gcd(a, b)) return a * b;
        return abs((a * b) / gcd(a, b));
    }

private:
    int a, b;
};

int main() {
    least_common_multiple* Huydzbatboi = new least_common_multiple;
    Huydzbatboi -> getInput();
    cout << Huydzbatboi -> processing();
    return 0;
}
