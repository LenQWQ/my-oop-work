#ifndef TASK3_H
#define TASK3_H

class X;

class Y {
public:
    void g(X* p);
};

class Z;

class X {
    friend class Z;
    friend void Y::g(X*);
    friend void h(X*);
private:
    int i;
public:
    X(int val = 0) : i(val) {}
    int getI() const { return i; }
};

class Z {
public:
    void f(X* p);
};

void h(X* p);

#endif