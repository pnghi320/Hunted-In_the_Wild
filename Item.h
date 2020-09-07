//Nghi Tran
//This is my own work.
#ifndef ITEM_H
#define ITEM_H

#include <string>
using namespace std;

class Item {

//private data member
private:
	string name;
	int damage;
	int price;


public:
//constructor
	Item() {
		name = "Bamboo Toothbrush";
		damage = 10;
		price = 0;
	}
	Item(string name, int damage, int price){
		this->name = name;
		this->damage = damage;
		this->price = price;
	}

//destructor
	virtual ~Item(){
    }

//print the name of item in the store
	void printItem(){
		cout << name << endl;
	}

  //initialize function for the item in the store
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