/*函数h(X*)，满足：类X有私有成员i，Y的成员函数g(X*)是X的友元函数，实现对X的成员i加1，类Z是类X的友元类，
其成员函数f(X*)实现对X的成员i加5，函数h(X*)是X的友元函数，实现对X的成员i加10。在一个文件中定义和实现类，在另一个文件中实现main()函数。*/
#include "task3.h"
#include <iostream>
#include<windows.h>
using namespace std;

void Y::g(X* p) {
    p->i += 1;
}

void Z::f(X* p) {
    p->i += 5;
}

void h(X* p) {
    p->i += 10;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    X x(0);
    Y y;
    Z z;

    cout << "初始值: i = " << x.getI() << endl;

    y.g(&x);
    cout << "调用 Y::g后: i = " << x.getI() << endl;

    z.f(&x);
    cout << "调用 Z::f后: i = " << x.getI() << endl;

    h(&x);
    cout << "调用 h后: i = " << x.getI() << endl;

    return 0;
}