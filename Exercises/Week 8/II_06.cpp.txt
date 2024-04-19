#include <iostream>
#include <string>

using namespace std;

struct Rect {
    double x;
    double y;
    double w;
    double h;
};

struct Ship {
    Rect rect;
    string id;
    double dx;
    double dy;

    void move() {
        rect.x += dx;
        rect.y += dy;
    }
};

int main() {
    Ship ship = {{0, 0, 5, 3}, "Ship1", 1, 1};

    cout << "Initial position: (" << ship.rect.x << ", " << ship.rect.y << ")" << endl;

    ship.move();

    cout << "Position after moving: (" << ship.rect.x << ", " << ship.rect.y << ")" << endl;

    return 0;
}