#include <bits/stdc++.h>
using namespace std;

void magicMatrix(vector<vector<int>> &vvi, int n) {
    int row = 0, col = n / 2;
    int x = 1;
    while(x <= n * n) {
        vvi[row][col] = x++;
        if(vvi[(row - 1 + n) % n][(col + 1) % n] != 0) {
            row = (row + 1) % n;
            continue;
        }
        row = (row - 1 + n) % n;
        col = (col + 1) % n;
    }
}

void print(vector<vector<int>> &vvi, int n) {
    for(vector<int> vi : vvi) {
        for(int i : vi)
            cout << i << ' ';
        cout << '\n';
    }
}

int main() {
    int n; cin >> n;
    vector<vector<int>> vvi(n, vector<int>(n, 0));
    magicMatrix(vvi, n);
    print(vvi, n);

    return 0;
}
