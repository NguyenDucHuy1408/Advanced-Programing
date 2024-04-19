#include <iostream>

using namespace std;

struct Point {
    double x;
    double y;
};

struct Rect {
    double x;
    double y;
    double w;
    double h;

    bool contains(const Point& p) const {
        return p.x >= x && p.x <= x + w && p.y >= y && p.y <= y + h;
    }
};

int main() {
    Rect rectangle = {1, 1, 4, 3};
    Point point_inside = {2, 2};
    Point point_outside = {6, 6};

    if (rectangle.contains(point_inside)) {
        cout << "Point is inside the rectangle." << endl;
    } else {
        cout << "Point is outside the rectangle." << endl;
    }

    if (rectangle.contains(point_outside)) {
        cout << "Point is inside the rectangle." << endl;
    } else {
        cout << "Point is outside the rectangle." << endl;
    }

    return 0;
}#include <iostream>

using namespace std;

struct Point {
    double x;
    double y;
};

struct Rect {
    double x;
    double y;
    double w;
    double h;

    bool contains(const Point& p) const {
        return p.x >= x && p.x <= x + w && p.y >= y && p.y <= y + h;
    }
};

int main() {
    Rect rectangle = {1, 1, 4, 3};
    Point point_inside = {2, 2};
    Point point_outside = {6, 6};

    if (rectangle.contains(point_inside)) {
        cout << "Point is inside the rectangle." << endl;
    } else {
        cout << "Point is outside the rectangle." << endl;
    }

    if (rectangle.contains(point_outside)) {
        cout << "Point is inside the rectangle." << endl;
    } else {
        cout << "Point is outside the rectangle." << endl;
    }

    return 0;
}