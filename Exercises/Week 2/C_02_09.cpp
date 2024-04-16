#include <iostream>

int main() {
    int n; std::cin >> n;
    int sum = 0;
    while(n) {
        sum += n % 10;
        n /= 10;
    }
    std::cout << sum;

    return 0;
}
