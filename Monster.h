//Nghi Tran
//This is my own work.
#include <string>
using namespace std;
#include <iostream>
#include <iomanip>
#include <ctime>
#include <math.h>

#include "Creature.h" 

#ifndef MONSTER_H
#define MONSTER_H

//class Monster has the inherent relationship with class Creature
class Monster : public Creature
{
	public:
	
	//function to initialize a monster with name
	//polymorphism is used
	void initialize(string name) {
      this->name = name;
      this->hp = 20;
      this->hpMax = 20;
      this->strength = 0;
			this->strengthMax = 10; 
			this-> coinPossession = 10;
			}
    //function to initialize a monster that already has a name
		//polymorphism is used
		void initialize() {
      this->hp = 20;
      this->hpMax = 20;
      this->strength = 0;
			this->strengthMax = 10;
			this-> coinPossession = 10;
			}

};
#endif