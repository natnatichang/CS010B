#include <iostream>
#include <string>

#include "Elf.h"
#include "Character.h"

using namespace std;
// Stores the elf's family name as a string.

// The elf does not attack an elf from its own family.

// The damage done by the elf is the percentage of the elf's health 
// remaining (health / MAX_HEALTH) multiplied by the elf's attack strength.

Elf::Elf(const string &name, double health, double attackStrength, const string &family)
    : Character(ELF, name, health, attackStrength), familyName(family)
{}

void Elf::attack(Character &opponent){
    if(opponent.getType() == ELF){
        Elf &opp = dynamic_cast<Elf&>(opponent);
        if(opp.familyName == this->familyName){
            cout << "Elf " << this->name << " does not attack Elf " << opponent.getName() << "." << endl;
            cout << "They are both members of the " << opp.familyName << " family." << endl;;
            return;
        }
    }

    double damage = (this->health / MAX_HEALTH) * (this->attackStrength);

    opponent.damage(damage);

    cout << "Elf " << this->name << " shoots an arrow at " << opponent.getName() << " --- TWANG!!" << endl;
    cout << opponent.getName() << " takes " << damage << " damage."  << endl;
    
    
}