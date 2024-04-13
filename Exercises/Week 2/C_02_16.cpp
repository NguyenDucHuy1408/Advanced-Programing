#include <iostream>

int main() {
    int num;
    do {
        std::cout << "Nhap vao mot so trong khoang tu 0 den 9: ";
        std::cin >> num;
        if(num >= 0 && num <= 9) std::cout << "Ban vua nhap so: ";
        switch(num) {
            case 0: std::cout << "khong"; break;
            case 1: std::cout << "mot"; break;
            case 2: std::cout << "hai"; break;
            case 3: std::cout << "ba"; break;
            case 4: std::cout << "bon"; break;
            case 5: std::cout << "nam"; break;
            case 6: std::cout << "sau"; break;
            case 7: std::cout << "bay"; break;
            case 8: std::cout << "tam"; break;
            case 9: std::cout << "chin"; break;
        }
        std::cout << std::endl;
    } while(num >= 0 && num <= 9);

    return 0;
}
