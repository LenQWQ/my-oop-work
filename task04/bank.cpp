/*4.编写一个模拟银行账户的类Account，实现存款、取款、结算利息的功能，活期年利率1.5%，按月结算利息，初始存款余额1W。
*/
#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

class account{
    private:
    string account_number = "LenQWQ";
    string password = "050914";
    double balance = 10000.0;
    double yearly_interest_rate = 0.015;
    public:
    account(string acc_n, string pw, double cash){
        account_number = acc_n;
        password = pw;
        balance = cash;
    }
    string verify(string acc_n,string pw){
        if(acc_n == account_number && pw == password){
            return "欢迎";
        }else{
            return "您的账号或密码错误，请重新输入";
        }
    }
    void deposit(double amount){
        balance += amount;
        cout << "存款成功，当前余额: " << balance << endl;
    }
    void withdraw(double amount){
        if(amount > balance){
            cout << "余额不足。当前余额: " << balance << endl;
        }else{
            balance -= amount;
            cout << "取款成功，当前余额: " << balance << endl;
        }
    }
};
int main(){
    SetConsoleOutputCP(65001);
    string acc_n,pw;
    cout << "请输入账号: ";
    cin >> acc_n;
    cout << "请输入密码: ";
    cin >> pw;
    account acc(acc_n,pw,10000.0);
    string verification_result = acc.verify(acc_n, pw);
    cout << verification_result << endl;
    if(verification_result == "欢迎"){
        int choice;
        cout << "请选择操作: 1. 存款 2. 取款" << endl;
        cin >> choice;
        if(choice == 1){
            double amount;
            cout << "请输入存款金额: ";
            cin >> amount;
            acc.deposit(amount);
        }else if(choice == 2){
            double amount;
            cout << "请输入取款金额: ";
            cin >> amount;
            acc.withdraw(amount);
        }
    }
    return 0;
}