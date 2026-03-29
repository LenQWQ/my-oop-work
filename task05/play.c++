#include <iostream>
#include <windows.h>
#include <cstdlib> 
#include <ctime>   
#include "pokemon.h"
using namespace std;
class Play {
public:
    Pokemon* player;
    Pokemon* computer;
    Play() : player(nullptr), computer(nullptr) {}  
    ~Play() {
        delete player;
        delete computer;
    }
    void player_choose_pokemon() {
        cout << "请选择你的宝可梦:" << endl;
        cout << "1. 皮卡丘 2. 妙蛙种子 3. 小火龙 4. 杰尼龟" << endl;
        int choice;
        cin >> choice;
        switch(choice) {
            case 1: player = new Pikachu(); break;
            case 2: player = new Bulbasaur(); break;
            case 3: player = new Charmander(); break;
            case 4: player = new Squirtle(); break;
        }
        cout << "你选择了: " << player->name << endl;
    }
    void computer_choose_pokemon() {
        int choice = rand() % 4 + 1; 
        switch(choice) {
            case 1: computer = new Pikachu(); break;
            case 2: computer = new Bulbasaur(); break;
            case 3: computer = new Charmander(); break;
            case 4: computer = new Squirtle(); break;
        }
        cout << "对手选择了: " << computer->name << endl;
    }
    void check_winner() {
        if (player->hp <= 0) {
            cout << "你输了!" << endl;
            exit(0);  
        } else if (computer->hp <= 0) {
            cout << "你赢了!" << endl;
            exit(0); 
        }
    }
    void player_turn() {
        cout << "\n你的 " << player->name << " HP: " << player->hp << endl;
        cout << "对手 " << computer->name << " HP: " << computer->hp << endl;
        cout << "请选择技能:" << endl;
        cout << "1. " << player->skills[0]->name;
        cout << " 2. " << player->skills[1]->name << endl;
        int choice;
        cin >> choice;
        if (choice == 1) {
            player->useSkill(0, *computer);
        } else if (choice == 2) {
            player->useSkill(1, *computer);
        }
    }
    void computer_turn() {
        cout << "\n对手的回合:" << endl;
        int choice = rand() % 2;  
        computer->useSkill(choice, *player);
    }
};
int main() {
    SetConsoleOutputCP(65001);
    srand(time(NULL));
    Play game;
    game.player_choose_pokemon();
    game.computer_choose_pokemon();
    int round = 1;
    while (game.player->hp > 0 && game.computer->hp > 0) {
        cout << "\n第 " << round << " 回合" << endl;
        game.player_turn();
        game.check_winner();
        if (game.player->hp > 0 && game.computer->hp > 0) {
            game.computer_turn();
            game.check_winner();
        }
        round++;
        Sleep(1000);  
    }
    return 0;
}