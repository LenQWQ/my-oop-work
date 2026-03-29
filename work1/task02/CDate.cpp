/*2.编写一个程序，设计一个电子日历类CDate。满足如下要求：（1）用日／月／年格式输出日期；（2）可运行日期加一天的操作；（3）设置日期。
*/
#include<iostream>
#include<windows.h>
using namespace std;

class CDate{
private:
    int year, month, day;
    bool isleap(int year){
        if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)){
            return true;
        }
        return false;
    }
    int getdays(int year,int month){
        switch(month){
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                return 31;
            case 4: case 6: case 9: case 11:
                return 30;
            case 2:
            if(isleap(year)){
                return 29;
            }else{
                return 28;
            }
            default:
                return 0;
        
    }
}
    public:
    CDate(int year=2000, int month=1, int day=1):year(year),month(month),day(day){}
    void setDate(int y, int m, int d){
        year = y;
        month = m; 
        day = d;
    }
    void showDate(){
        cout << year << "/" << month << "/" << day << "/" << endl;
    }
    void DayPlus(){
        day++;
        if(day > getdays(year, month)){
            day = 1;
            month++;
            if(month > 12){
                month = 1;
                year++;
            }
        }
    }
};

int main(){
    SetConsoleOutputCP(CP_UTF8);
    int year, month, day;
    cout << "请输入日期" << endl;
    cin >> year >> month >> day;
    CDate date(year, month, day);
    date.showDate();
    date.DayPlus();
    cout << "加一天后的日期为：" << endl;
    date.showDate();
    return 0;
}
