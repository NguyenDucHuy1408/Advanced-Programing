#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> vi(n);
    for(int &num : vi) cin >> num;
    float average = 1.0 * accumulate(vi.begin(), vi.end(), 0) / n;
    float varience = 0;
    for(int i = 0; i < n; i++)
        varience += (average - vi[i]) * (average - vi[i]);
    cout << average << ' ' << varience / n;
    return 0;
}