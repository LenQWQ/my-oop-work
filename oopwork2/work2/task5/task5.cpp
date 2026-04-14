#include<iostream>
#include<windows.h>
using namespace std;

class sell{
    private:
        static double sum;
        int quantity;
        double price;
    public:
    sell(int q, double p) {
        quantity = q;
        price = p;
    }
    void discount(){
        if(quantity >= 10){
            price = price * 0.9;
        }
    }
    double singleSum(){
        return quantity * price;
    }
    static void add(double singlesum){
        sum += singlesum;
    }
    static double getsum(){
        return sum;
    }
};

double sell::sum = 0;

int main(){
    SetConsoleOutputCP(CP_UTF8);
    sell s[3] ={
        sell(5, 23.5),
        sell(12, 24.56),
        sell(100, 21.5)
    };
    for(int i = 0; i < 3; i++){
        s[i].discount();
        double singlesum = s[i].singleSum();
        sell::add(singlesum);
        cout << sell::getsum() << endl;
    }
    cout << sell::getsum()/162 << endl;
    return 0;
}