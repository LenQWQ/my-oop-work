#include <iostream>
#include <string>
#include<windows.h>
using namespace std;

class Teacher {
protected:
    string name;
    int age;
    string sex;
    string address;
    string phone;
    string title;
public:
    Teacher(string n, int a, string s, string addr, string ph, string t);
    void display();
};
Teacher::Teacher(string n, int a, string s, string addr, string ph, string t)
    : name(n), age(a), sex(s), address(addr), phone(ph), title(t) {}

void Teacher::display() {
    cout << "姓名: " << name << endl;
    cout << "年龄: " << age << endl;
    cout << "性别: " << sex << endl;
    cout << "职称: " << title << endl;
    cout << "地址: " << address << endl;
    cout << "电话: " << phone << endl;
}

class Cadre {
protected:
    string name;
    int age;
    string sex;
    string address;
    string phone;
    string post;
public:
    Cadre(string n, int a, string s, string addr, string ph, string p);
};
Cadre::Cadre(string n, int a, string s, string addr, string ph, string p)
    : name(n), age(a), sex(s), address(addr), phone(ph), post(p) {}
class Teacher_Cadre : public Teacher, public Cadre {
private:
    double wages;
public:
    Teacher_Cadre(string n, int a, string s, string addr, string ph,
                  string t, string p, double w);
    void show();
};
Teacher_Cadre::Teacher_Cadre(string n, int a, string s, string addr, string ph,
                             string t, string p, double w)
    : Teacher(n, a, s, addr, ph, t),
      Cadre(n, a, s, addr, ph, p),
      wages(w) {}
void Teacher_Cadre::show() {
    Teacher::display();

    cout << "职务: " << Cadre::post << endl;

    cout << "工资: " << wages << endl;
}

int main() {
    SetConsoleOutputCP(65001);
    string name, sex, address, phone, title, post;
    int age;
    double wages;
    cout << "请输入姓名: ";
    cin >> name;
    cout << "请输入年龄: ";
    cin >> age;
    cout << "请输入性别: ";
    cin >> sex;
    cout << "请输入地址: ";
    cin >> address;
    cout << "请输入电话: ";
    cin >> phone;
    cout << "请输入职称: ";
    cin >> title;
    cout << "请输入职务: ";
    cin >> post;
    cout << "请输入工资: ";
    cin >> wages;
    Teacher_Cadre tc(name, age, sex, address, phone, title, post, wages);
    tc.show();
    return 0;
}