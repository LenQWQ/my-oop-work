#include<iostream>
#include<windows.h>
using namespace std;

class Base1{
public:
    Base1(int x){
        cout << "Base1构造函数被调用,参数为: " << x << endl;
    }
    ~Base1(){
        cout << "Base1析构函数被调用" << endl;
    }
};

class Base2{
public:
    Base2(int x){
        cout << "Base2构造函数被调用,参数为: " << x << endl;
    }
        ~Base2(){
            cout << "Base2析构函数被调用" << endl;
        }
};

class Base3{
public:
    Base3(int x){
        cout << "Base3构造函数被调用,参数为: " << x << endl;
    }
    ~Base3(){
        cout << "Base3析构函数被调用" << endl;
    }
};

class Derived:public Base1,public Base2,public Base3{
private:
    Base1 b1;
    Base2 b2;
    Base3 b3;
public:
    Derived(int x1,int x2,int x3,int x4,int x5,int x6,int x7):Base1(x1),Base2(x2),Base3(x3),b1(x4),b2(x5),b3(x6){
        cout << "Derived构造函数被调用,参数为: " << x7 << endl;
    }
    ~Derived(){
        cout << "Derived析构函数被调用" << endl;
    }
};

int main(){
    SetConsoleOutputCP(65001);
    Derived d(1,2,3,4,5,6,7);
    return 0;
}