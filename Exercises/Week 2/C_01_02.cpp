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

void printRow(int m, int n)
{
    forx(i, 1, m) cout << ' ';
    forx(i, 1, n) cout << '*';
    cout << '\n';
}

int main()
{
    int n; cin >> n;
    forx(i, 1, n) printRow(i - 1, n - i + 1);

    return 0;
}
