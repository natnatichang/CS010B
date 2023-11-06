#ifndef __WARRIOR_H__
#define __WARRIOR_H__

#include <iostream>
#include <string>

#include "Character.h"

using namespace std;



class Warrior : public Character {
    private: 
    string allegiance;

    public: 

    Warrior(const string &name, double health, double attackStrength, const string &group);
    void attack(Character &opponent);


};





#endif