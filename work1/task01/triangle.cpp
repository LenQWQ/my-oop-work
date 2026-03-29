/*1.用一个Triangle类来描述三角形，用点Point类的对象来表示端点。要求Triangle类具有计算三角形周长和面积的功能，在构造函数中实现。
*/
#include<iostream>
#include<cmath>
#include<windows.h>

using namespace std;

//点类
class Point{
public:
    double x,y;
    Point(double x=0, double y=0):x(x),y(y){}
};
//三角形类
class Triangle{
    private:
    Point p1,p2,p3;
    double a,b,c;
    private:
    double distance(Point p1, Point p2){
        return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
    }
    public:
    double area;
    double perimeter;
    Triangle(Point p1,Point p2,Point p3):p1(p1),p2(p2),p3(p3){
        a=distance(p1,p2);
        b=distance(p2,p3);
        c=distance(p3,p1);
        perimeter = a+b+c; //计算周长
        double s = perimeter/2; 
        area = sqrt(s*(s-a)*(s-b)*(s-c)); //计算面积
    }
};
int main(){
    SetConsoleOutputCP(CP_UTF8);
    double x1,x2,x3,y1,y2,y3;
    cout<<"请输入三角形的三个顶点坐标："<<endl;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    Point p1(x1,y1),p2(x2,y2),p3(x3,y3);
    Triangle t(p1,p2,p3);
    cout<<"请选择操作:1.计算面积 2.计算周长"<<endl;
    int op;
    cin >> op;
    if(op==1){
        cout<<"三角形的面积为："<<t.area<<endl;
    }else if(op==2){
        cout<<"三角形的周长为："<<t.perimeter<<endl;
    }
    return 0;
}
