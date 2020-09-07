//Nghi Tran
//This is my own work.
#include <string>
using namespace std;
#include <iostream>
#include <iomanip>
#include <ctime>
#include <math.h>


#ifndef CREATURE_H
#define CREATURE_H


class Creature
{
//base class for monster and character
//protect data members
protected:
    string name;
    int hp;
    int hpMax;
    int strength;
		int strengthMax;
		int coinPossession;

//public data member 
public: 
		//constructor 
    Creature(){
      this->name = "";
      this->hp = 0;
      this->hpMax = 0;
      this->strength = 0;
			this->strengthMax = 0;
			this-> coinPossession = 0;
    }
		Creature(string name){
      this->name = name;
      this->hp = 0;
      this->hpMax = 0;
      this->strength = 0;
			this->strengthMax = 0;
			this-> coinPossession = 0;
    }
		
		//destructor
    virtual ~Creature(){
    }

		//pure virtual functions making this class an abstract class
		virtual void initialize(string name) = 0; 
		virtual void initialize() = 0;

		//funtion to take the hit from the monster
    void takeDamage(int damage){
				this->hp -= damage; 
				if (this->hp <= 0){
					this->hp = 0;
					}}
		//function to heal if users chooses to hide and rest
     void heal(int damage){
			 this->hp += damage;
		 }
		 
    //accessors
    const string& getName() const {
      return this-> name;
    }
    const int& getHp() const {
      return this-> hp;
    }
    const int& getHpMax() const {
      return this-> hpMax;
    }
    const int& getStrength() const {
      return this-> strength;
    }
		const int& getCoinPossession() const {
      return this-> coinPossession;
    }
		const int& getStrengthMax() const {
      return this-> strengthMax;
    }

    //modifiers 
		void setName(string name){
			this->name = name;
		}
		void setHp(int hp){
			this->hp = hp;
		}
		void setHpMax(int hpMax){
			this->hpMax = hpMax;
		}
		void setStrength(int strength){
			this->strength = strength;
		}
		void setCoinPossession(int coinPossession){
			this->coinPossession = coinPossession;
		}
		void setStrengthMax(int strengthMax){
			this->strengthMax = strengthMax;
		}

};
#endif




