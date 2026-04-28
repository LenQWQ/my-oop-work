#include<iostream>
#include<windows.h>
using namespace std;

class Base{
    public:
        virtual void disp(int x){
            cout << "Base类的disp函数被调用,参数为: " << x << endl;
        }
};

class ExtBase:public Base{
    public:
        void disp(int x) override{
            cout << "ExtBase类的disp函数被调用,参数为: " << x << endl;
        }
};

class Derived:public ExtBase{
    public:
        void disp(int x) override{
            cout << "Derived类的disp函数被调用,参数为: " << x << endl;
        }
};

int main() {
    SetConsoleOutputCP(65001);
    Derived d; 
    Base* bPtr = &d;
    bPtr->disp(1); 
    Base& bRef = d;
    bRef.disp(2);  
    Derived* dPtr = &d;
    dPtr->disp(3);  
    Derived& dRef = d;
    dRef.disp(4);  
    return 0;
}