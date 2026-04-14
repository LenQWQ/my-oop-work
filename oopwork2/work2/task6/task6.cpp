/*6.实现一个名为SimpleCircle的简单圆类。其数据成员int *itsRadius为一个指向其半径值的指针，存放其半径值。设计对数据成员的各种操作，给出这个类的完整实现，并测试这个类。
*/
#include<iostream>
#include<windows.h>
using namespace std;

class SimpleCircle{
    private:
        double radius;
    public:
    double *itsRadius = (double*)&radius;
    SimpleCircle(double r) {
        radius = r;
    }
    double getArea() {
        return 3.14 * *itsRadius * *itsRadius;
    }
    double getPerimeter() {
        return 2 * 3.14 * *itsRadius;
    }
};

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int n;
    cin >> n;
    SimpleCircle circle(n);
    cout << "半径: " << *circle.itsRadius << endl;
    cout << "面积: " << circle.getArea() << endl;
    cout << "周长: " << circle.getPerimeter() << endl;
    return 0;
}


