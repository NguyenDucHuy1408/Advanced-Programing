#include <iostream>

#define forx(i, a, b) for(int i = a; i <= b; i++)
#define forn(i, a, b) for(int i = a; i >= b; i--)
#define fora(x, a) for(auto x : a)
#define pb push_back
#define fi first
#define se second
using ll = long long;

using namespace std;

class isoscelesTriangle
{
public:
    void getInput()
    {
        cin >> n;
        tmp = n;
    }

    void print()
    {
        forn(i, n, 1)
        {
            forx(j, 1, tmp - i)
                cout << ' ';
            forx(j, 1, 2 * i - 1)
                cout << '*';
            forx(j, 1, tmp - i)
                cout << ' ';
            cout << '\n';
        }
    }
private:
    int n, tmp;
};

int main()
{
    isoscelesTriangle* Huy = new isoscelesTriangle;
    Huy -> getInput();
    Huy -> print();

    return 0;
}
