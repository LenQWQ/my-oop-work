#include <iostream>
#include <windows.h>
using namespace std;

class Base1 {
public:
    Base1(int x) {
        cout << "Base1构造: " << x << endl;
    }
    ~Base1() {
        cout << "Base1析构" << endl;
    }
};

class Base2 {
public:
    Base2(int x) {
        cout << "Base2构造: " << x << endl;
    }
    ~Base2() {
        cout << "Base2析构" << endl;
    }
};

class ExtBase1 : virtual public Base1, public Base2 {
public:
    ExtBase1(int a, int b) : Base1(a), Base2(b) {
        cout << "ExtBase1构造" << endl;
    }
    ~ExtBase1() {
        cout << "ExtBase1析构" << endl;
    }
};

class ExtBase2 : virtual public Base2, public Base1 {
public:
    ExtBase2(int a, int b) : Base2(a), Base1(b) {
        cout << "ExtBase2构造" << endl;
    }
    ~ExtBase2() {
        cout << "ExtBase2析构" << endl;
    }
};

class Derived : public ExtBase1, public ExtBase2 {
public:
    Derived(int a1, int a2,  
            int b1, int b2,   
            int c1, int c2)  
        : Base1(a1), Base2(a2),  
          ExtBase1(b1, b2),
          ExtBase2(c1, c2)
    {
        cout << "Derived构造" << endl;
    }

    ~Derived() {
        cout << "Derived析构" << endl;
    }
};

int main() {
    SetConsoleOutputCP(65001);
    Derived d(1, 2, 3, 4, 5, 6);
    return 0;
}