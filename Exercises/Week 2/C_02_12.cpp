#include <iostream>
#include <math.h>

bool isSquareNum(int n) {
    return (int)sqrt(n) == sqrt(n);
}

int main() {
    int n; std::cin >> n;
    if(isSquareNum(n)) std::cout << "yes";
    else std::cout << "no";

    return 0;
}
