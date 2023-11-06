#include <iostream>
#include <string>

#include "Wizard.h"
#include "Character.h"

using namespace std;

// Stores the wizard's rank as an int.

// When a wizard attacks another wizard, the damage done 
// is the wizard's attack strength multiplied by the ratio 
// of the attacking wizard's rank over the defending wizard's rank.

// The damage done to non-wizards is just the attack strength. 
// The wizard's health is not taken into consideration.



Wizard::Wizard(const string &name, double health, double attackStrength, int rank)
    : Character(WIZARD, name, health, attackStrength), rank(rank)
{}

void Wizard::attack(Character &opponent){
    if(opponent.getType() == WIZARD){
        Wizard &opp = dynamic_cast<Wizard&>(opponent);
        if(opp.rank == this->rank){
            cout << "Something something wizard" << endl;
            return;
        }
        double damage = this->attackStrength * (this->rank) / opp.rank;
        opp.damage(damage);
        cout << "Wizard " << this->name << " attacks " << opponent.getName() << " --- POOF!!" << endl;
        cout << opponent.getName() << " takes " << damage << " damage."  << endl;
    }
    else{
        
    double damage = attackStrength;
    opponent.damage(damage);
    cout << "Wizard " << this->name << " attacks " << opponent.getName() << " --- POOF!!" << endl;
    cout << opponent.getName() << " takes " << damage << " damage."  << endl;
    }

}