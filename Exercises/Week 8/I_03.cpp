
#include <iostream>
using namespace std;

struct Point {
    double x;
    double y;
};

// Hàm tính trung điểm của hai điểm
Point mid_point(const Point& p1, const Point& p2) {
    Point mid;
    mid.x = (p1.x + p2.x) / 2;
    mid.y = (p1.y + p2.y) / 2;
    return mid;
}

int main() {

    Point p1 = {5, 5};
    Point p2 = {15, 15};

    Point mid = mid_point(p1, p2);

    cout << "Mid point between p1 and p2: " << mid.x << ", " << mid.y << endl;

    return 0;
}
