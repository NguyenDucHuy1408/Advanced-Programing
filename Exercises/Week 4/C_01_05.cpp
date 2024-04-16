#include <iostream>
#include <vector>

void spiral(int m, int n) {
    int x = 1;
    std::vector<std::vector<int>> ans(m, std::vector<int>(n, 0));
    int l = 0, t = 0, b = m - 1, r = n - 1;
    while(x <= m * n) {
        for(int i = l; i <= r && x <= m * n; i++)
            if(ans[t][i] == 0) ans[t][i] = x++;
        t++;
        for(int i = t; i <= b && x <= m * n; i++)
            if(ans[i][r] == 0) ans[i][r] = x++;
        r--;
        for(int i = r; i >= l && x <= m * n; i--)
            if(ans[b][i] == 0) ans[b][i] = x++;
        b--;
        for(int i = b; i >= t && x <= m * n; i--)
            if(ans[i][l] == 0) ans[i][l] = x++;
        l++;
    }

    for(int i = 0 ; i < m ; i++) {
        for(int j = 0; j < n; j++)
            std::cout << ans[i][j] << ' ';
        std::cout << '\n';
    }
}

int main() {
    int m, n;
    std::cin >> m >> n;
    spiral(m, n);

    return 0;
}
