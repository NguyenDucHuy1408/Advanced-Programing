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

void display(const Ship& ship) {
    cout << "Ship ID: " << ship.id << ", Position: (" << ship.rect.x << ", " << ship.rect.y << ")" << endl;
}

int main() {
    Ship ship1 = {{0, 0, 5, 3}, "Ship1", 1, 1};
    Ship ship2 = {{-2, -2, 4, 2}, "Ship2", -0.5, 0.5};

    display(ship1);
    display(ship2);

    return 0;
}