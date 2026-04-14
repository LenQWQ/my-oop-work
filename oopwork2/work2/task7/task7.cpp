/*7.利用动态内存分配技术解决王婆卖瓜问题：每卖一个瓜要记录该瓜的重量，还要记录所卖出的总重量和总个数。同时还允许退瓜。用面向对象的方法设计王婆卖瓜的程序，首先要设计类，一个自然的设想就是以西瓜为对象，对西瓜类定义各种属性和操作。
*/
#include<iostream>
#include<windows.h>
using namespace std;
class Watermelon {
    public:
    int weight;
    Watermelon(int w = 0){
        weight = w;
    }
};

class Wangpo{
    private:
    Watermelon* watermelons;
    int count;
    double totalWeight;
    public:
    Wangpo(){
        watermelons = nullptr;
        count = 0;
        totalWeight = 0.0;
    }
    ~Wangpo(){
        delete[] watermelons;
    }
    void sellWatermelon(double weight){
        Watermelon* newWatermelons = new Watermelon[count + 1];
        for(int i = 0; i < count; i++){
            newWatermelons[i] = watermelons[i];
        }
        newWatermelons[count] = Watermelon(weight);
        delete[] watermelons;
        watermelons = newWatermelons;
        count++;
        totalWeight += weight;
    }
    void returnWatermelon(double weight){
        if(count == 0){
            cout << "No watermelons to return!" << endl;
            return;
        }
        totalWeight -= weight;
        Watermelon* newWatermelons = new Watermelon[count - 1];
        for(int i = 0; i < count - 1; i++){
            newWatermelons[i] = watermelons[i];
        }
        delete[] watermelons;
        watermelons = newWatermelons;
        count--;
    }
    double getTotalWeight(){
        return totalWeight;
    }
};

int main(){
    Wangpo wp;
    wp.sellWatermelon(5.0);
    wp.sellWatermelon(3.0);
    cout << "Total weight: " << wp.getTotalWeight() << endl;
    wp.returnWatermelon(5.0);
    cout << "Total weight after return: " << wp.getTotalWeight() << endl;
    return 0;
}