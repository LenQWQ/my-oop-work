/*4.创建一个封装矩形宽度和高度的类Rectangle。在主函数中动态创建一个对象，程序终止时，将该对象销毁释放内存。
*/

#include <iostream>
#include <windows.h>
using namespace std;

class Rectangle {
private:
    double width;
    double height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    ~Rectangle() {}
    double getArea() const {
        return width * height;
    }
};

int main() {
    Rectangle* rect = new Rectangle(5.0, 3.0);
    cout << "面积: " << rect->getArea() << endl;
    delete rect;
    return 0;
}