/*1.应用友元函数计算点到直线的距离。*/
#include <iostream>
#include <cmath>
#include <windows.h>
using namespace std;

class Point{
    private:
    int x,y;
    public:
    Point(int a,int b):x(a),y(b){}
    friend double distance(Point p1,Point p2){
        return sqrt(pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2));
    }
};

int main(){
    SetConsoleOutputCP(CP_UTF8);
    int x1,y1,x2,y2;
    cout<<"请输入第一个点的坐标：";
    cin>>x1>>y1;
    cout<<"请输入第二个点的坐标：";
    cin>>x2>>y2;
    Point p1(x1,y1),p2(x2,y2);
    cout<<"两点之间的距离为："<<distance(p1,p2)<<endl;
    return 0;
}