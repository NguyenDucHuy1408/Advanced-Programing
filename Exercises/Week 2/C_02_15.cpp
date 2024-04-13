#define forx(i, a, b) for(int i=a; i<=b; i++)
#define forn(i, b, a) for(int i=b; i>=a; i--)
#define fora(x, a) for(auto x : a)
#define fi first
#define se second
#define pb push_back

#include <iostream>
#include <vector>

using namespace std;

const int size = 1000;

class fibonacci
{
public:
    void getInput()
    {
        cin >> n;
        arr.resize(size);
        arr[1] = 1;
        arr[2] = 1;
        i = 2;
        check = false;
    }

    void processing()
    {
        if(n == 1) check = true;
        while(n > arr[i])
        {
            arr[i + 1] = arr[i] + arr[i - 1];
            if(arr[i + 1] == n) check = true;
            i++;
        }
        if(arr[i] > n) i--;
    }

    void print()
    {
        if(check) cout << "Thuoc day Fibonacci\n";
        else cout << "Khong thuoc day Fibonacci\n";
        forx(j, 1, i)
            cout << arr[j] << ' ';
    }
private:
    int n, i;
    vector<int> arr;
    bool check;
};

int main()
{
    fibonacci* Huy = new fibonacci;
    Huy -> getInput();
    Huy -> processing();
    Huy -> print();

    return 0;
}
