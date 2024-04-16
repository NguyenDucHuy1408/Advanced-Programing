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
        cin >> Min >> Max >> Step;
    }

    void processing()
    {
        while(Min <= Max)
        {
            C = (Min - 32) * 5 / 9;
            K = C + 273.15;
            print();
            Min += Step;
        }

    }

    void print()
    {
        cout << fixed << setprecision(2) << Min << ' ' << C << ' ' << K << '\n';
    }
private:
    float Min, Max, Step;
    float C, K;
};

int main()
{
    convertTemperature* Huy = new convertTemperature;
    Huy -> getInput();
    Huy -> processing();

    return 0;
}