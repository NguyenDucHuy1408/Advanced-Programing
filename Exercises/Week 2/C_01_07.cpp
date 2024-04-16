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

class distinctNum
{
public:
    void getInput()
    {
        cin >> num;
        tmp = num;
        while(num >= 0)
        {
            cin >> num;
            if(tmp != num) cout << tmp << ' ';
            tmp = num;
        }
        cout << num;
    }
private:
    int num, tmp;
};

int main()
{
    distinctNum* Huydzbatboi = new distinctNum;
    Huydzbatboi -> getInput();

    return 0;
}
