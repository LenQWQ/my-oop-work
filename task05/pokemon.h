#include <iostream>
#include <windows.h>
#include <vector>
#include <algorithm>
using namespace std;
class Pokemon;
class Skill;
//技能效果类
class Effect {
private:
    int duration;
public:
    Effect(int d) : duration(d) {}
    virtual void apply(Pokemon& p) = 0;
    bool isOver() { return duration <= 0; }
    void decrease() { duration--; }
    int getDuration() { return duration; }
    virtual ~Effect() {}
};

// 燃烧效果
class heat_effect : public Effect {
public:
    heat_effect() : Effect(2) {}
    void apply(Pokemon& p) override;
};

// 中毒效果
class poison_effect : public Effect {
public:
    poison_effect() : Effect(2) {}
    void apply(Pokemon& p) override;
};

// 眩晕效果
class stun_effect : public Effect {
private:
    int original_atk;
    bool applied;
public:
    stun_effect() : Effect(2), original_atk(0), applied(false) {}
    void apply(Pokemon& p) override;
};
//技能类
class Skill {
public:
    string name;
    Skill(string n) : name(n) {}
    virtual void use(Pokemon& user, Pokemon& target) = 0;
    virtual ~Skill() {}
};

class heal_drug : public Skill {
public:
    heal_drug() : Skill("治疗药") {}
    void use(Pokemon& user, Pokemon& target) override;
};
class seed_bomb : public Skill {
public:
    seed_bomb() : Skill("种子炸弹") {}
    void use(Pokemon& user, Pokemon& target) override;
};

class poison_powder : public Skill {
public:
    poison_powder() : Skill("毒粉") {}
    void use(Pokemon& user, Pokemon& target) override;
};

class fire_blast : public Skill {
public:
    fire_blast() : Skill("火焰放射") {}
    void use(Pokemon& user, Pokemon& target) override;
};

class heat_wave : public Skill {
public:
    heat_wave() : Skill("热风") {}
    void use(Pokemon& user, Pokemon& target) override;
};

class water_gun : public Skill {
public:
    water_gun() : Skill("水枪") {}
    void use(Pokemon& user, Pokemon& target) override;
};

class water_heal : public Skill {
public:
    water_heal() : Skill("水疗") {}
    void use(Pokemon& user, Pokemon& target) override;
};

class thunder_shock : public Skill {
public:
    thunder_shock() : Skill("电击") {}
    void use(Pokemon& user, Pokemon& target) override;
};
class thunder_wave : public Skill {
public:
    thunder_wave() : Skill("电波") {}
    void use(Pokemon& user, Pokemon& target) override;
};
//宝可梦类
class Pokemon {
public:
    string name;
    int hp;
    int atk;
    int defence;
    vector<Effect*> effects;
    vector<Skill*> skills;
    Pokemon(string n, int h, int a, int d) : name(n), hp(h), atk(a), defence(d) {}
    void useSkill(int index, Pokemon& target) {
    if (index >= 0 && index < skills.size()) {
        skills[index]->use(*this, target);
        }
    }
    void receiveDamage(int damage) {
        int actualDamage = max(0, damage - defence);
        hp -= actualDamage;
        if (hp < 0) hp = 0;
        cout << name << "受到" << actualDamage << "点伤害,剩余HP:" << hp << endl;
    }
    void heal(int amount) {
        hp += amount;
        cout << name << "恢复了" << amount << "点HP,当前HP:" << hp << endl;
    }
    void defence_decrease(int amount) {
        defence -= amount;
        if (defence < 0) defence = 0;
        cout << name << "的防御降低了" << amount << "点,当前防御:" << defence << endl;
    }
    
    void addEffect(Effect* e) {
        effects.push_back(e);
    }
    void applyEffects() {
        for (auto it = effects.begin(); it != effects.end();) {
            Effect* e = *it;
            e->apply(*this);
            if (e->isOver()) {
                delete e;
                it = effects.erase(it);
            } else {
                ++it;
            }
        }
    }
    virtual ~Pokemon() {
        for (auto skill : skills) delete skill;
        for (auto effect : effects) delete effect;
    }
};
class Pikachu : public Pokemon {
public:
    Pikachu() : Pokemon("皮卡丘", 100, 20, 10) {
        skills.push_back(new thunder_shock());
        skills.push_back(new thunder_wave());
    }
};
class Bulbasaur : public Pokemon {
public:
    Bulbasaur() : Pokemon("妙蛙种子", 120, 15, 15) {
        skills.push_back(new seed_bomb());
        skills.push_back(new poison_powder());
    }
};
class Charmander : public Pokemon {
public:
    Charmander() : Pokemon("小火龙", 90, 25, 5) {
        skills.push_back(new fire_blast());
        skills.push_back(new heat_wave());
    }
};
class Squirtle : public Pokemon {
public:
    Squirtle() : Pokemon("杰尼龟", 110, 10, 20) {
        skills.push_back(new water_gun());
        skills.push_back(new water_heal());
    }
};
void heat_effect::apply(Pokemon& p) {
    cout << "燃烧造成10点伤害" << endl;
    p.receiveDamage(10);
    decrease();
}
void poison_effect::apply(Pokemon& p) {
    cout << "中毒造成10点伤害" << endl;
    p.receiveDamage(10);
    p.defence_decrease(5);
    decrease();
}
void stun_effect::apply(Pokemon& p) {
    if (!applied) {
        original_atk = p.atk;
        p.atk = 0;
        cout << p.name << "陷入眩晕，无法行动！" << endl;
        applied = true;
    }
    if (getDuration() == 1) {
        p.atk = original_atk;
        cout << p.name << "从眩晕中恢复" << endl;
    }
    decrease();
}
void heal_drug::use(Pokemon& user, Pokemon& target) {
    cout << user.name << "使用了" << name << "!" << endl;
    user.heal(30);
}
void seed_bomb::use(Pokemon& user, Pokemon& target) {
    cout << user.name << "使用了" << name << "!" << endl;
    int damage = 20 + user.atk;
    target.receiveDamage(damage);
}
void poison_powder::use(Pokemon& user, Pokemon& target) {
    cout << user.name << "使用了" << name << "!" << endl;
    int damage = 10 + user.atk;
    target.receiveDamage(damage);
    target.addEffect(new poison_effect());
}
void fire_blast::use(Pokemon& user, Pokemon& target) {
    cout << user.name << "使用了" << name << "!" << endl;
    int damage = 30 + user.atk;
    target.receiveDamage(damage);
    target.addEffect(new heat_effect());
}
void heat_wave::use(Pokemon& user, Pokemon& target) {
    cout << user.name << "使用了" << name << "!" << endl;
    int damage = 10 + user.atk;
    target.receiveDamage(damage);
    target.addEffect(new heat_effect());
}
void water_gun::use(Pokemon& user, Pokemon& target) {
    cout << user.name << "使用了" << name << "!" << endl;
    int damage = 20 + user.atk;
    target.receiveDamage(damage);
}
void water_heal::use(Pokemon& user, Pokemon& target) {
    cout << user.name << "使用了" << name << "!" << endl;
    user.heal(20);
}
void thunder_shock::use(Pokemon& user, Pokemon& target) {
    cout << user.name << "使用了" << name << "!" << endl;
    int damage = 15 + user.atk;
    target.receiveDamage(damage);
}
void thunder_wave::use(Pokemon& user, Pokemon& target) {
    cout << user.name << "使用了" << name << "!" << endl;
    int damage = 10 + user.atk;
    target.receiveDamage(damage);
    target.addEffect(new stun_effect());
}