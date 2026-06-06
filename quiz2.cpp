#include <iostream>
using namespace std;

//================ HERO =================
class Hero
{
private:
    string name;
    int health;
    int attackPower;
    int level;

public:
    Hero(string n, int h, int a, int l)
    {
        name = n;
        health = h;
        attackPower = a;
        level = l;
    }

    string getName() { return name; }
    int getHealth() { return health; }
    int getAttackPower() { return attackPower; }
    int getLevel() { return level; }

    virtual void displayHero()
    {
        cout << "Name: " << name << endl;
        cout << "Health: " << health << endl;
        cout << "Attack Power: " << attackPower << endl;
        cout << "Level: " << level << endl;
    }

    // Function Overloading
    void attack()
    {
        cout << name << " performs a normal attack.\n";
    }

    void attack(int bonusDamage)
    {
        cout << name << " attacks with +"
             << bonusDamage << " bonus damage.\n";
    }

    void attack(string specialSkill)
    {
        cout << name << " uses "
             << specialSkill << ".\n";
    }

    void attack(int bonusDamage, string specialSkill)
    {
        cout << name << " uses "
             << specialSkill
             << " with +" << bonusDamage
             << " bonus damage.\n";
    }
};

//================ WARRIOR =================
class Warrior : public Hero
{
private:
    int shieldStrength;

public:
    Warrior(string n, int h, int a, int l, int s)
        : Hero(n, h, a, l)
    {
        shieldStrength = s;
    }

    void displayHero()
    {
        Hero::displayHero();
        cout << "Shield Strength: "
             << shieldStrength << endl;
    }
};

//================ ARCHER =================
class Archer : public Hero
{
private:
    int arrowCount;

public:
    Archer(string n, int h, int a, int l, int arrows)
        : Hero(n, h, a, l)
    {
        arrowCount = arrows;
    }

    void displayHero()
    {
        Hero::displayHero();
        cout << "Arrow Count: "
             << arrowCount << endl;
    }
};

//================ MAGE =================
class Mage : public Hero
{
private:
    int mana;

public:
    Mage(string n, int h, int a, int l, int m)
        : Hero(n, h, a, l)
    {
        mana = m;
    }

    void displayHero()
    {
        Hero::displayHero();
        cout << "Mana: "
             << mana << endl;
    }
};

//================ MAIN =================
int main()
{
    Warrior w1("Arthur",100,50,10,80);
    Warrior w2("Leon",120,60,12,90);

    Archer a1("Robin",90,45,8,100);
    Archer a2("Hawk",95,55,9,120);

    Mage m1("Merlin",80,70,15,200);
    Mage m2("Gandalf",85,75,16,250);

    // Array of Hero pointers
    Hero* heroes[6] =
    {
        &w1,
        &w2,
        &a1,
        &a2,
        &m1,
        &m2
    };

    cout << "\n===== ALL HEROES =====\n";

    for(int i = 0; i < 6; i++)
    {
        heroes[i]->displayHero();
        cout << endl;
    }

    cout << "\n===== ATTACK DEMONSTRATION =====\n";

    w1.attack();
    w1.attack(20);
    w1.attack("Fire Slash");
    w1.attack(20, "Fire Slash");

    Hero* strongest = heroes[0];

    for(int i = 1; i < 6; i++)
    {
        if(heroes[i]->getAttackPower() >
           strongest->getAttackPower())
        {
            strongest = heroes[i];
        }
    }

    cout << "\n===== STRONGEST HERO =====\n";
    cout << strongest->getName()
         << " (Attack Power = "
         << strongest->getAttackPower()
         << ")\n";

    cout << "\n===== BATTLE SUMMARY =====\n";

    for(int i = 0; i < 6; i++)
    {
        cout << "\nHero Name: "
             << heroes[i]->getName();

        cout << "\nHealth: "
             << heroes[i]->getHealth();

        cout << "\nAttack Power: "
             << heroes[i]->getAttackPower();

        cout << "\nLevel: "
             << heroes[i]->getLevel();

        cout << "\n---------------------\n";
    }

    return 0;
}
