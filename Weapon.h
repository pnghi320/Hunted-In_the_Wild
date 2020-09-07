//Nghi Tran
//This is my own work.
#ifndef WEAPON_H
#define WEAPON_H

#include <string>
using namespace std;

class Weapon {

private:
//private data members
	string name;
	int damage;
	int price;


public:
//constructor
	Weapon() {
		name = "Bamboo Toothbrush";
		damage = 10;
		price = 0;
	}
	Weapon(string name, int damage, int price){
		this->name = name;
		this->damage = damage;
		this->price = price;
	}

//destructor
	virtual ~Weapon(){
    }
	//funtion to print name of weapon
	void printWeapon(){
		cout << name << endl;
	}

  //initialize functions
	void initialize() {
		this-> name = "Bamboo Toothbrush";
    this->damage = 10;
		this->price = 0;
		}

	//accessors
  const string& getName() const {
		return this-> name;
    }
	const int& getDamage() const {
		return this-> damage;
    }
	const int& getPrice() const {
		return this-> price;
    }

	//modifiers 
	void setName(string name){
		this->name = name;
	}
	void setDamage(int damage){
		this->damage = damage;
		}
	void setPrice(int price){
		this->price = price;
		}

};
#endif