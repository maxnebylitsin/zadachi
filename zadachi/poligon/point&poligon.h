#include <iostream>
#include <cmath>

using namespace std;
class point{

    private:
    double x, y;

    public:
    point(){
        x = 0;
        y = 0;
    }

    point(double nx, double ny){
        x = nx;
        y = ny;
    }

    point(const point &p){
        x = p.x;
        y = p.y;
    }

    double getX(){
        return x;
    }

    double getY(){
        return y;
    }

    double dist(point a){
        return sqrt(pow((x - a.x), 2) + pow((y - a.y), 2));
    }
    
    friend ostream& operator <<(ostream &out, const point &p){
        out << "(" << p.x << ", " << p.y << ")" << endl;
        return out;
    }

    friend istream& operator >>(istream &in, point &p){
        in >> p.x;
        in >> p.y;
        return in;
    }
};

class poligon{

    protected:
    int n;
    point *tops;

    public:
    poligon(int nn){
        //выделить динамическую память под нужное количество точек полигона
        n = nn;
        tops = new point[n];
    }

    ~poligon(){
        delete [] tops;
    }
    
    void setTop(int i, point a){
        //установка i-ой вершины полигона
        tops[i] = a;
    }

    point getTop(int i){
        //получение i-ой вершины полигона
        return tops[i];
    }

    double length(){
        //вычисление периметра полигона
        double len = 0;
        for (int i = 0; i < n; i++){
            if (i == n - 1){
                len += tops[i].dist(tops[0]);
            }
            else{
            len += tops[i].dist(tops[i + 1]);
            }
        }
        return len;

    }

    double area(){
        //вычисление площади
        double area = 0;
        for (int i = 0; i < n; i++){
            area += (tops[i].getX() + tops[(i + 1) % n].getX()) * (tops[i].getY() - tops[(i + 1) % n].getY());
        }
        return abs(area) / 2;
    }
    
    bool isConvex(){
        //проверка полигона на выпуклость
        bool positive = false;
        bool negative = false;
        for (int i = 0; i < n; i++){
            int j = (i + 1) % n;
            int k = (i + 2) % n;
            double convex = (tops[j].getX() - tops[i].getX()) * (tops[k].getY() - tops[j].getY()) - 
                                (tops[j].getY() - tops[i].getY()) * (tops[k].getX() - tops[j].getX());
            if(convex > 0){
                positive = true;
            }
            else if(convex < 0){
                negative = true;
            }
            if(positive && negative){
                return false;
            }
        }
        return true;
    }

    bool isPointIn(point a){
        //проверка что точка внутри полигона
        bool result = false;
        int j = n - 1;
        for (int i = 0; i < n; i++) {
            if ((tops[i].getY() < a.getY() && tops[j].getY() >= a.getY() || tops[j].getY() < a.getY() && tops[i].getY() >= a.getY()) &&
                (tops[i].getX() + (a.getY() - tops[i].getY()) / (tops[j].getY() - tops[i].getY()) * (tops[j].getX() - tops[i].getX()) < a.getX()))
                result = !result;
            j = i;
        }
        return result;
    }
};

class triangle: public poligon{
    public:

    triangle(point a,  point b,  point c) : poligon(3){
        setTop(0, a);
        setTop(1, b);
        setTop(2, c);
    }

    double area(){
        // вычисление площади треугольника по формуле Герона
        double a = tops[0].dist(tops[1]);
        double b = tops[1].dist(tops[2]);
        double c = tops[2].dist(tops[0]);
        double p = (a + b + c) / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }

    double length(){
        // вычисление периметра треугольника
        return tops[0].dist(tops[1]) + tops[1].dist(tops[2]) + tops[2].dist(tops[0]);
    }
};

class square: public poligon{
    public:

    square(point a, point b, point c, point d) : poligon(4){
        // проверка, что координаты точек образуют квадрат
        double ab = a.dist(b);
        double bc = b.dist(c);
        double cd = c.dist(d);
        double da = d.dist(a);
        double ac = a.dist(c);
        double bd = b.dist(d);
        if (ab != bc || bc != cd || cd != da || da != ab || ac != bd){
            throw "Invalid coordinates for square";
        }
        setTop(0, a);
        setTop(1, b);
        setTop(2, c);
        setTop(3, d);
    }

    double area(){
        // вычисление площади квадрата
        double a = tops[0].dist(tops[1]);
        return a * a;
    }

    double length(){
        // вычисление периметра квадрата
        double a = tops[0].dist(tops[1]);
        return a * 4;
    }
};