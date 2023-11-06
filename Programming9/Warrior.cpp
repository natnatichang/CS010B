#include <iostream>
#include <string>

#include "Warrior.h"
#include "Character.h"

using namespace std;


// Stores the warrior's allegiance as a string.

// The warrior does not attack warriors that have the same allegiance.

// The damage done by the warrior is the percentage of the warrior's 
// health remaining (health / MAX_HEALTH) multiplied by the warrior's attack strength.



Warrior::Warrior(const string &name, double health, double attackStrength, const string &group)
    : Character(WARRIOR, name, health, attackStrength), allegiance(group)
{}

void Warrior::attack(Character &opponent){
    if(opponent.getType() == WARRIOR){
        Warrior &opp = dynamic_cast<Warrior&>(opponent);
        if(opp.allegiance == this->allegiance){
            cout << "Warrior " << this->name << " does not attack Warrior " << opponent.getName() << "." << endl;
            cout << "They share an allegiance with " << opp.allegiance << "." <<endl;
            return;
        }
    }

    double damage = (this->health / MAX_HEALTH) * (this->attackStrength);
    opponent.damage(damage);
    cout << "Warrior " << this->name << " attacks " << opponent.getName() << " --- SLASH!!" << endl;
    cout << opponent.getName() << " takes " << damage << " damage."  << endl;
  

    
}