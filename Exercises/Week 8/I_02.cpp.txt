#include <iostream>
using namespace std;

struct Point {
    double x;
    double y;
};

// Hàm thử nghiệm truyền tham trị
void test(Point p) {
    cout << "Test by value - Before modification: " << p.x << ", " << p.y << "\n";
    p.x = 10;
    p.y = 10;
    cout << "Test by value - After modification: " << p.x << ", " << p.y << "\n";
}

// Hàm thử nghiệm truyền tham biến
void testRef(Point& p) {
    cout << "Test by reference - Before modification: " << p.x << ", " << p.y << "\n";
    p.x = 10;
    p.y = 10;
    cout << "Test by reference - After modification: " << p.x << ", " << p.y << "\n";
}

int main() {

    Point p1 = {5, 5};

    // Hiển thị thông tin điểm trước khi thử nghiệm
    cout << "Point before testing: " << p1.x << ", " << p1.y << "\n";

    // Thử nghiệm truyền tham trị
    cout << "\nTesting pass by value:" << "\n";
    test(p1);

    // Hiển thị thông tin điểm sau khi thử nghiệm truyền tham trị
    cout << "\nPoint after testing pass by value: " << p1.x << ", " << p1.y << "\n";

    // Thử nghiệm truyền tham biến
    cout << "\nTesting pass by reference:" << "\n";
    testRef(p1);

    // Hiển thị thông tin điểm sau khi thử nghiệm truyền tham biến
    cout << "\nPoint after testing pass by reference: " << p1.x << ", " << p1.y << "\n";

    return 0;
}