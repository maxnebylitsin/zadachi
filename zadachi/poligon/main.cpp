#include <iostream>
#include "point&poligon.h"

using namespace std;

int main() {
    // тестирование класса point
    point p1(0, 0);
    point p2(3, 4);
    cout << "Point p1: " << p1;
    cout << "Point p2: " << p2;
    cout << "Distance between p1 and p2: " << p1.dist(p2) << endl;

    // тестирование класса poligon
    poligon pg(4);
    pg.setTop(0, point(0, 0));
    pg.setTop(1, point(0, 4));
    pg.setTop(2, point(3, 4));
    pg.setTop(3, point(3, 0));
    cout << "Perimeter of poligon pg: " << pg.length() << endl;
    cout << "Area of poligon pg: " << pg.area() << endl;
    cout << "Is pg convex? " << pg.isConvex() << endl;
    point testPoint(1, 1);
    cout << "Is point " << testPoint << " inside pg? " << pg.isPointIn(testPoint) << endl;

    // тестирование класса triangle
    triangle tr(point(0, 0), point(0, 3), point(4, 0));
    cout << "Perimeter of triangle tr: " << tr.length() << endl;
    cout << "Area of triangle tr: " << tr.area() << endl;
    cout << "Is tr convex? " << tr.isConvex() << endl;
    point testPoint2(1, 1);
    cout << "Is point " << testPoint2 << " inside tr? " << tr.isPointIn(testPoint2) << endl;

    // тестирование класса square
    square sq(point(0, 0), point(0, 4), point(4, 4), point(4, 0));
    cout << "Perimeter of square sq: " << sq.length() << endl;
    cout << "Area of square sq: " << sq.area() << endl;
    cout << "Is sq convex? " << sq.isConvex() << endl;
    point testPoint3(2, 2);
    cout << "Is point " << testPoint3 << " inside sq? " << sq.isPointIn(testPoint3) << endl;

    return 0;
}