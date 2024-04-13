#define forx(i, a, b) for(int i=a; i<=b; i++)
#define forn(i, b, a) for(int i=b; i>=a; i--)
#define fora(x, a) for(auto x : a)
#define fi first
#define se second
#define pb push_back

#include <iostream>
#include <iomanip>

using namespace std;

class convertTemperature
{
public:
    void getInput()
    {
        cin >> F;
    }

    void processing()
    {
        C = (F - 32) * 5 / 9;
        K = C + 273.15;
        print();
    }

    void print()
    {
        cout << F << fixed << setprecision(2) << ' ' << C << ' ' << K << '\n';
    }
private:
    float F, C, K;
};

int main()
{
    convertTemperature* Huy = new convertTemperature;
    Huy -> getInput();
    Huy -> processing();

    return 0;
}