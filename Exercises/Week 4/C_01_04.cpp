#include <iostream>
#include <vector>

void bomb(std::vector<std::vector<char>> &vvc, int m, int n, int row, int col) {
    if(vvc[row][col] == '.') {
        int cnt = 0;
        for(int i = row - 1; i <= row + 1; i++) {
            if(i < 0 || i >= m) continue;
            for(int j = col - 1; j <= col + 1; j++) {
                if(j < 0 || j >= n) continue;
                if(vvc[i][j] == '*') cnt++;
            }
        }
        vvc[row][col] = char(cnt + '0');
    }
}

int main() {
    int m, n;
    std::cin >> m >> n;
    std::vector<std::vector<char>> vvc(m, std::vector<char>(n));
    for(std::vector<char> &vc : vvc)
        for(char &c : vc)
            std::cin >> c;
     for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            bomb(vvc, m, n, i, j);
    for(std::vector<char> &vc : vvc) {
        for(char &c : vc)
            std::cout << c << ' ';
        std::cout << '\n';
    }
}
