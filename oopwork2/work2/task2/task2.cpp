/*2.统计银行存款问题：
设计一个程序，其中有3个类，CBank、BBank和GBank，
分别为中国银行类、工商银行类和农业银行类。
每个类都包含一个私有数据balance，用于存放储户在该行的存款数，
另有一个友元函数total用于计算储户在这3家银行中的总存款数。
*/
#include <iostream>
#include <windows.h>
using namespace std;

class CBbank; 
class BBank;   
class GBank;

class CBank{
    private:
    double balance;
    public:
    CBank(double b):balance(b){}
    friend double total(CBank &cb,BBank &bb,GBank &gb);
};

class BBank{
    private:
    double balance;
    public:
    BBank(double b):balance(b){}
    friend double total(CBank &cb,BBank &bb,GBank &gb);
};

class GBank{
    private:
    double balance;
    public:
    GBank(double b):balance(b){}
    friend double total(CBank &cb,BBank &bb,GBank &gb);
};

double total(CBank &cb,BBank &bb,GBank &gb){
    return cb.balance + bb.balance + gb.balance;
}

int main(){
    SetConsoleOutputCP(CP_UTF8);
    double cbalance,bbalance,gbalance;
    cout<<"请输入中国银行的存款数：";
    cin>>cbalance;
    cout<<"请输入工商银行的存款数：";
    cin>>bbalance;
    cout<<"请输入农业银行的存款数：";
    cin>>gbalance;
    CBank cb(cbalance);
    BBank bb(bbalance);
    GBank gb(gbalance);
    cout<<"储户在这3家银行中的总存款数为:"<<total(cb,bb,gb)<<endl;
    return 0;
}
