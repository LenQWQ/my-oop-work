/*3.设计一个用于人事管理的“人员”类。由于考虑到通用性，这里只抽象出所有类型人员都具有的属性：编号、性别、出生日期、身份证等。其中“出生日期”声明为一个“日期”内嵌子对象。用成员函数实现对人员信息的录入和显示。要求包括：构造函数、析构函数、拷贝构造对象、内联成员函数、带默认形参值的成员函数、类的组合。
*/
#include<iostream>
#include<windows.h>
using namespace std;

class Date {
private:
    int year, month, day;

public:
    Date(int y=2000, int m=1, int d=1):year(y),month(m),day(d){}
    Date(const Date &d){
        year = d.year;
        month = d.month;
        day = d.day;
    }
    void setDate(int y, int m, int d){
        year = y;
        month = m;
        day = d;
    }
    void showDate() const{
        cout << year << "/" << month << "/" << day;
    }
    ~Date(){};
};
class member {
    private:
    string number;
    string id;
    string sex;
    string birthday;
    public:
    member(string number, string id, string sex, string birthday):number(number),id(id),sex(sex),birthday(birthday){}
    member (const member &m){
        number = m.number;
        id = m.id;
        sex = m.sex;
        birthday = m.birthday;
    }
    void setMember(string n, string i, string s, string b){
        if(n != ""){
            number = n;
        }
        if(i != ""){
            id = i;
        }
        if(s != ""){
            sex = s;
        }
        if(b != ""){
            birthday = b;
        }
    }
    void showMember() const{
        cout << "编号: " << number << endl;
        cout << "身份证: " << id << endl;
        cout << "性别: " << sex << endl;
        cout << "生日: " << birthday << endl;
}
    ~member(){};
};
int main(){
    SetConsoleOutputCP(65001);
    string number,id,sex,birthday;
    cout << "请输入人员编号: ";
    cin >> number;
    cout << "请输入身份证号码: "; 
    cin >> id;
    cout << "请输入性别: ";
    cin >> sex;
    cout << "请输入生日: ";
    cin >> birthday;
    member m1(number, id, sex, birthday);
    cout << "人员信息如下: " << endl;
    m1.showMember();
    return 0;
}
