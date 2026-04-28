#include<iostream>
#include<windows.h>
using namespace std;

class Shape{
    public:
        Shape(int x){
            cout << "Shape构造函数被调用,参数为: " << x << endl;
        }
        ~Shape(){
            cout << "Shape析构函数被调用" << endl;
        }
};

class Triangle:public Shape{
    public:
        Triangle(int x,int y):Shape(x){
            cout << "Triangle构造函数被调用,参数为: " << y << endl;
        }
        ~Triangle(){
            cout << "Triangle析构函数被调用" << endl;
        }
};

class ColorTriangle:public Triangle{
    public:
        ColorTriangle(int x,int y,int z):Triangle(x,y){
            cout << "ColorTriangle构造函数被调用,参数为: " << z << endl;
        }
        ~ColorTriangle(){
            cout << "ColorTriangle析构函数被调用" << endl;
        }
};

int main(){
    SetConsoleOutputCP(65001);
    ColorTriangle ct(1,2,3);
    return 0;
}