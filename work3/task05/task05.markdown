# 5.分析以下代码中存在什么问题？如何修改代码以避免出现的问题？并解释原因。
```
#include <iostream>
using namespace std;

class Base {
  protected:    
    int a;
  public:    
    Base() { a=10; }
};

class D1 : public Base {
  public:
    D1() { cout<<"D1::a:"<<a<<endl; }
};

class D2 : public Base  {
  public:
    D2() { cout<<"D2::a:"<<a<<endl; }
};

class Derived : public D2, public D1 {
  public:
    Derived() { cout <<"Derived::a:"<<a<<endl; }
};

int main() {    
    Derived d;    
    return 0;
}
```

# A:由于菱形继承中未使用虚继承，导致基类成员重复，产生二义性

## 修改后的代码:
```
#include <iostream>
using namespace std;

class Base {
  protected:    
    int a;
  public:    
    Base() { a=10; }
};

class D1 : virtual public Base {
  public:
    D1() { cout<<"D1::a:"<<a<<endl; }
};

class D2 : virtual public Base  {
  public:
    D2() { cout<<"D2::a:"<<a<<endl; }
};

class Derived : public D2, public D1 {
  public:
    Derived() { cout <<"Derived::a:"<<a<<endl; }
};

int main() {    
    Derived d;    
    return 0;
}
```
