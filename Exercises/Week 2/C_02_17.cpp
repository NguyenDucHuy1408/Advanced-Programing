#include <iostream>
#include <numeric>

int main() {
    int mark[5];
    for(int &point : mark) std::cin >> point;
    std::cout << std::accumulate(mark, mark + 5, 0) / 5.0;

    return 0;
}
