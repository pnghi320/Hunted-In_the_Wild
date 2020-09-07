//Nghi Tran
//This is my own work.
#include <string>
using namespace std;
#include <iostream>
#include <iomanip>
#include <ctime>
#include <math.h>

#include "Weapon.h"
#include "Creature.h" 

#ifndef CHARACTER_H
#define CHARACTER_H

//class Character has the inherent relationship with class Creature
class Character : public Creature
{
	public:
	//embedded object 
	//class Character has the composition relationship with class Weapon
	Weapon wea;

	//function to initialize a character
	//polymorphism is used
	void initialize(string name) {
      this->name = name;
      this->hp = 100;
      this->hpMax = 100;
      this->strength = 5;
			this-> coinPossession = 100;
			}

    //function to initialize a character that already has a name
		//polymorphism is used
		void initialize() {
      this->hp = 100;
      this->hpMax = 100;
      this->strength = 5;
			this-> coinPossession = 100;
			}

		//print out character information
		void printStats() const{
      cout << "= CHARCTER SHEET =" << endl <<endl;
      cout << "Name: " << this-> name << endl;
      cout <<"Health: " << this-> hp << " / " << this-> hpMax << endl;
      cout << "Money: " << this-> coinPossession << " coins"<<endl;
			}

		//add coins to coin coinPossession when user defeats monster
		void gainCoin(int coin)
		{
			this->coinPossession += coin;
			if (this->coinPossession <= 0)
			{
				this->coinPossession = 0;
			}
		}

		//reduce coins from coinPossession when user buys weapons
		void reduceCoin(int coin)
		{
			this->coinPossession -= coin;
			if (this->coinPossession <= 0)
			{
				this->coinPossession = 0;
			}
		}

};
#endif