//Nghi Tran
//This is my own work.

#include <string>
using namespace std;
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <fstream>

#include "Character.h"
#include "Monster.h"
#include "Item.h"


#ifndef GAME_H
#define GAME_H

class Game 
{

private:
//private data member
int choice;
int choiceTwo;
bool playing;
bool cont;
bool hasEnoughCoin;

//emebeded objects 
//class Game has the composition relationship with class Character, Monster, and Item
Character character;
Monster monster;
Item item;


public: 

//public constructor
Game(){
	choice = 0;
  choiceTwo = 0;
	cont = true;
  playing = true;
	hasEnoughCoin = false; 
	}
	
//public destructor
virtual ~Game(){
}

	//function for menu and game logic for each option within the menu
  void mainMenu(){
		cout << "= MENU =" << endl << endl;
  	cout << "0: New Game" << endl;
    cout << "1: Resume Game" << endl;
  	cout << "2: Option" << endl;
    cout << "3: Quit" << endl;
    cout << "Please enter the number of your choice!" << endl;
    cin >> choice;
  	cout << endl;

		//ask for new input if the previous input was invalid.
		while (cin.fail() || this->choice > 3)
		{
			cout << "Incorrect input." << "\n";
			cin.clear();
			cin.ignore(100, '\n');
      cout << "\n" << "Choice (0 - 3): ";
      cin >> this->choice;
		}
		cin.ignore(100, '\n');
		cout << "\n";

		//different input values will lead to different cases
    switch (choice)
		{
			//if user inputs "0" initialize brand new monster, character, weapon(through composition)
			//print out the storyline
			//enter the arena
			case 0:
			monster.initialize();
      character.initialize();
			character.wea.initialize();
			item.initialize();
			cout << "You dare not move, you dare not make a sound."<<endl;
			cout<<"Despite the rain lashing down outside, you feared that any noise or movement would alert the hunters."<< endl; 
			cout<< "The beasts were vicious and highly-skilled predators. If you were caught, you would be torn apart and feasted upon. Their thick coats protected them from the harsh weather."<< endl;
			cout <<"You knew they would still be out there, in the forest, seeking you out. " << endl;
			cout << "The cold of the night was wrapping around your core, making the movements sluggish." << endl;
			cout <<"As time went by, and the starvation started to affect your sanity, you decided to leave the shelter and look for food." << endl;
			cout << "Soon, you came to the edge of the forest and faced the first hunting monster..."<<endl<<endl;
			play();
			break;
			
			//if user inputs "1" load their saved process, and enter arena 
			case 1:
			loadCharacter();
			play();	
			break;
			
			//if user inputs "3" set the playing boolean to false and exit the program 
			case 3:
			playing = false;
			break;
			
			//if user inputs "3" print out the menu for the option tab
			case 2:
                cout << "= OPTION =" << endl << endl;
                cout << "0: Store" << endl;
                cout << "1: Character Sheet" << endl;
                cout << "2: Back to Menu" << endl;
                cout << "Please enter the number of your choice!" << endl;
                cin >> choiceTwo;
                cout << endl;

								//ask for new input if the previous input was invalid.
                while (cin.fail() || this->choiceTwo > 2)
		            {
                  cout << "Incorrect input." << "\n";
			            cin.clear();
			            cin.ignore(100, '\n');
                  cout << "\n" << "Choice (0 - 2): ";
                  cin >> this->choiceTwo;
		            }
		            cin.ignore(100, '\n');
		            cout << "\n";

                switch (choiceTwo)
                {
                  //if user inputs "1" print out the character information and their weapon statistics
									case 1:
                    character.printStats();
										cout << "Weapon in use: "<< character.wea.getName()<<endl;
										cout << "Weapon damage: " << character.wea.getDamage() <<endl;
                    cout << endl;
                    break;
            
									//if user inputs "2" go back to the main menu
                  case 2:
                    break;
									
									//if user inputs "0" go to the store
									case 0:
									//print out the store and ask for input
										cout << "= STORE =" << endl << endl;
										cout<< "0. Silver Spoon: " << endl;
										cout<< "   - Price: 101 coins" << endl;
										cout<< "   - Damage: 4/10" << endl;
										cout<< "1. Golden Egg: " << endl;
										cout<< "   - Price: 110 coins" << endl;
										cout<< "   - Damage: 5/10" << endl;
										cout<< "2. Diamond Paper Stapler:" << endl; 
										cout<< "   - Price: 120 coins" << endl;
										cout<< "   - Damage: 6/10" << endl;
										cout<< "3. Platinum Cucumber: " << endl;
										cout<< "   - Price: 130 coins" << endl;
										cout<< "   - Damage: 7/10" << endl;
										cout<< "4. Antimatter Coffee Cup:" << endl;
										cout<< "   - Price: 150 coins" << endl;
										cout<< "   - Damage: 8/10" << endl;
										cout<< "5. Back to menu" << endl<< endl;
										cout<< "Your pocket only has space for one weapon."<<endl;
										cout<< "Black Friday is over, buy responsibly!"<< endl<< endl;
										cout<< "$$$: " << character.getCoinPossession() << " coins"<<endl;
										cin >> choiceTwo;
										
										//ask for new input if the previous input was invalid.
                		while (cin.fail() || this->choiceTwo > 4)
										{
											cout << "Incorrect input." << "\n";
			            		cin.clear();
			            		cin.ignore(100, '\n');
                  		cout << "\n" << "Choice (0 - 4): ";
                  		cin >> this->choiceTwo;
		            		}
		            		cin.ignore(100, '\n');
		            		cout << "\n";

										//different input values will lead to different cases
                		switch (choiceTwo)
                		{
											//if user inputs "0" update the old weapon variables to that of the Silver Spoon and save it to the progress file
											//if the user does not have enough coins, tell him so
                  		case 0:
											item.setPrice(101);
											checkWallet();
											if (hasEnoughCoin){
												character.wea.setDamage(13);
												character.wea.setName("Silver Spoon");
												character.wea.setPrice(101);
												character.reduceCoin(character.wea.getPrice());
												hasEnoughCoin = false;
												cout << "Your purchase was successful"<<endl<<endl;
												saveCharacter();
											}
											else {
												cout << "You do not have enough coins."<< endl;
											}
											break;

											//if user inputs "1" update the old weapon variables to that of the Golden Egg and save it to the progress file
											//if the user does not have enough coins, tell him so
											case 1:
											item.setPrice(110);
											checkWallet();
											if (hasEnoughCoin){
												character.wea.setDamage(15);
												character.wea.setName("Golden Egg");
												character.wea.setPrice(110);
												character.reduceCoin(character.wea.getPrice());
												hasEnoughCoin = false;
												cout << "Your purchase was successful"<<endl<<endl;
												saveCharacter();
											}
											else {
												cout << "You do not have enough coins."<< endl;
											}
											break;

											//if user inputs "2" update the old weapon variables to that of the Diamond Paper Stapler and save it to the progress file
											//if the user does not have enough coins, tell him so
											case 2:
											item.setPrice(120);
											checkWallet();
											if (hasEnoughCoin){
												character.wea.setDamage(20);
												character.wea.setName("Diamond Paper Stapler");
												character.wea.setPrice(120);
												character.reduceCoin(character.wea.getPrice());
												hasEnoughCoin = false;
												cout << "Your purchase was successful"<<endl<<endl;
												saveCharacter();
											}
											else {
												cout << "You do not have enough coins."<< endl;
											}
											break;

											//if user inputs "3" update the old weapon variables to that of the Platinum Cucumber and save it to the progress file
											//if the user does not have enough coins, tell him so
											case 3:
											item.setPrice(130);
											checkWallet();
											if (hasEnoughCoin){
												character.wea.setDamage(25);
												character.wea.setName("Platinum Cucumber");
												character.wea.setPrice(130);
												character.reduceCoin(character.wea.getPrice());
												hasEnoughCoin = false;
												cout << "Your purchase was successful"<<endl<<endl;
												saveCharacter();
											}
											else {
												cout << "You do not have enough coins."<< endl;
											}
											break;

											//if user inputs "4" update the old weapon variables to that of the Antimatter Coffee Cup and save it to the progress file
											//if the user does not have enough coins, tell him so
											case 4:
											item.setPrice(150);
											checkWallet();
											if (hasEnoughCoin){
												character.wea.setDamage(30);
												character.wea.setName("Antimatter Coffee Cup");
												character.wea.setPrice(150);
												character.reduceCoin(character.wea.getPrice());
												hasEnoughCoin = false;
												cout << "Your purchase was successful"<<endl<<endl;
												saveCharacter();
											}
											else {
												cout << "You do not have enough coins."<< endl;
											}
											break;

                }
            default:
                break;
         }
				 }
				 }

		//funtion to check if user has enough coins to buy the weapon
		void checkWallet(){
			if (character.getCoinPossession() >= item.getPrice()){
				hasEnoughCoin = true;
			}
		}

		//function to initialize data when user start the program
    void initGame(){
      string name;
      cout << "HUNTED: IN THE WILD"<<endl<<endl;
      cout << "Character name without space: ";
      getline(cin, name);
      monster.initialize(name);
      character.initialize(name);
			character.wea.initialize();
      cout << endl;
    }

		//functions to access data members
   bool getPlaying() const{
        return this->playing;
    }
	int getChoice() const{
        return this->choice;
    }
	int getChoiceTwo() const{
        return this->choiceTwo;
    }
	bool getCont() const{
        return this->cont;
    }
	bool getHasEnoughCoin() const{
        return this->hasEnoughCoin;
		}

		//functions to modify data members
		void setPlaying(bool playing)
		{
			this->playing = playing;
		}
		void setChoice(int choice)
		{
			this->choice = choice;
		}
		void setChoiceTwo(int choiceTwo)
		{
			this->choiceTwo = choiceTwo;
		}
		void setCont(bool cont)
		{
			this->cont = cont;
		}
		void setHasEnoughCoin(bool hasEnoughCoin)
		{
			this->hasEnoughCoin = hasEnoughCoin;
		}

		//function for user to enter the "arena" and fight monsters
		void play(){
								cont = true;
								//for loop to make the monster stronger in the next round 
								for(int i=2; i <= 20; i++){
								//while the user chooses to continue the battle
                while (cont) {
								//get the random damage from a certain range that will be increased in the next round. 
								monster.setStrength(rand() % monster.getStrengthMax() + 1);
								cout << "++++++++++++++++++++++++++++++++++++++++" << endl << endl;
                cout << "The monster attacks you and deals "<< monster.getStrength()<<" damage." << endl;
                character.takeDamage(monster.getStrength());
                cout << "You are down to "<< character.getHp() << " health."<<endl;

								//if character is not dead ask the user what they want to do next
                if (character.getHp() > 0){
                cout << "You have the " << character.wea.getName() << " as the main weapon." << endl;
                cout <<endl;
                cout <<"What would you do?" << endl;
                cout <<"0: Attack"<<endl;
                cout <<"1: Hide and rest"<<endl;
                cout <<"2: Save game and go to menu"<<endl<< endl; 
								cout << "++++++++++++++++++++++++++++++++++++++++" << endl;
                cin >> choice;
								cout << endl;

								//different input values will lead to different cases
                switch(choice){

									//if user chooses to attack, generate random damage and reduce such health from the monster 
                  case 0:
									character.setStrength(rand() % character.wea.getDamage() + 1);
                  cout <<"You attack the monster and deal " << character.getStrength()<<" damage." << endl;
                  monster.takeDamage(character.getStrength());
                  cout << "The monster is down to "<< monster.getHp() << " health."<<endl<< endl;

									//if monster is dead, character gain coins from the monster coin possession
									//higher round of game, more coins can be obtained. 
									if (monster.getHp() <= 0){
										cout << "++++++++++++++++++++++++++++++++++++++++" << endl << endl;
										cout <<"The hunting monster has died and you obtained " << monster.getCoinPossession() << " coins from the monster’s treasure" <<endl;
										cout << endl;
										character.gainCoin(monster.getCoinPossession());
										//choose to continue the game or save and go to menu
										cout << "0. Continue the journey and fight the next monster" <<endl;
										cout << "1. Save game and go to menu" << endl;
										cin >> choice;
										cout <<endl;

										switch (choice){
											//if user chooses to continue, increase monster health and coin possession
											case 0: 
											cont = true;
											monster.initialize();
											monster.setStrengthMax(i*10);
											monster.setCoinPossession(i*10);
											break;

											//if user chooses to go to menu, save the information of character and revive the monster also
											case 1:
											monster.initialize();
											monster.setStrengthMax(i*10);
											monster.setCoinPossession(i*10);
											saveCharacter();
											break;
											}
									}
                  else 
									{
										break;
									}
									break;

									//if user chooses to hide and rest, add hp and update their new health
									case 1:
									cout <<"You hide and rest" << endl;
									character.setStrength(rand() % character.wea.getDamage() + 1);
									character.heal(character.getStrength());
									cout <<"You are up to " << character.getHp() << " health"<< endl;
									break;

									//if the user choose to go to menu, save their process, and go to menu
									case 2:
									saveCharacter();
                }
                }

								//if character runs out of hp, end battle, go back to menu
                else {
                  cout << "You have died. " << endl;
                  cout <<"Game Over" << endl;
                  cout <<endl;
                  break;}
								}}}

		//function to save user progress						
		void saveCharacter(){
			cont = false;
			ofstream outf("Sample.txt");
			if (!outf){
			// Print an error and exit												
			cerr << "Uh oh, Sample.txt could not be opened for writing!" << endl;
			exit(1);
			}
			//write user information into this file
			outf << character.getName() << endl;
			outf << character.getHp() << endl;
			outf << character.getHpMax() << endl;
			outf << character.getStrength() << endl;
			outf << character.getCoinPossession() << endl;
			outf << character.wea.getDamage() << endl;
			outf << monster.getName() << endl;
			outf << monster.getHp() << endl;
			outf << monster.getHpMax() << endl;
			outf << monster.getStrength() << endl;
			outf << monster.getStrengthMax() << endl;
			outf << monster.getCoinPossession() << endl;
		}

		//function to load user progress
		void loadCharacter(){
			//create variables
			fstream file;
			string characterName;
			int characterHp;
			int characterHpMax;
			int characterStrength;
			int characterCoinPossession;
			int weaponDamage;
			string monsterName;
			int monsterHp;
			int monsterHpMax;
			int monsterStrength;
			int monsterStrengthMax;
			int monsterCoinPossession;
			//open the file, check for error
			file.open("Sample.txt",ios::in);
			if(!file){
				cout<<"Error in opening file.";
				}
			//input the information in the file into variables
			file>>characterName;
			file>>characterHp;
			file>>characterHpMax;
			file>>characterStrength;
			file>>characterCoinPossession;
			file>>weaponDamage;
			file>>monsterName;
			file>>monsterHp;
			file>>monsterHpMax;
			file>>monsterStrength;
			file>>monsterStrengthMax;
			file>>monsterCoinPossession;
			//set the data members to the according to the variables
			character.setName(characterName);
			character.setHp(characterHp);
			character.setHpMax(characterHpMax);
			character.setStrength(characterStrength);
			character.setCoinPossession(characterCoinPossession);
			character.wea.setDamage(weaponDamage);
			monster.setName(monsterName);
			monster.setHp(monsterHp);
			monster.setHpMax(monsterHpMax);
			monster.setStrength(monsterStrength);
			monster.setStrengthMax(monsterStrengthMax);
			monster.setCoinPossession(monsterCoinPossession);		
			}
			
};

#endif