### 8.分析以下代码中存在什么问题？预期输出是什么？如何修改代码以避免出现的问题？并解释原因。
```
#include <iostream>
using namespace std;

class ShallowCopy {
private:
  int* data;
public:
  ShallowCopy(int value) {
    data = new int(value);
  }
  
  ShallowCopy(const ShallowCopy& other) : data(other.data) {}
  ~ShallowCopy() { delete data; }
    
  void print() { cout << "Data: " << *data << endl; }
    
  void modify(int value) { *data = value; }
};

int main() {
  ShallowCopy obj1(10);
  ShallowCopy obj2 = obj1;
  obj1.print();
  obj2.print();
    
  obj1.modify(20);
  obj1.print();
  obj2.print();
  
  return 0;
}
```
### 在执行modify函数后，预期输出应为：
obj1 = 20 obj2 = 10
### 但是obj1和obj2共用同一个内存地址，因此最终输出结果：
obj1 = 20 obj2 = 20

修改后的代码:
```
#include <iostream>
using namespace std;

class DeepCopy {
private:
    int* data;
public:
    DeepCopy(int value) {
        data = new int(value);
    }

    DeepCopy(const DeepCopy& other) {
        data = new int(*other.data); 
    }

    ~DeepCopy() { delete data; }

    void print() { cout << "Data: " << *data << endl; }

    void modify(int value) { *data = value; }
};

int main() {
    DeepCopy obj1(10);
    DeepCopy obj2 = obj1;

    obj1.print(); // 10
    obj2.print(); // 10

    obj1.modify(20);

    obj1.print(); // 20
    obj2.print(); // 10
}
```

