#include <iostream>

void parry() {
	std::cout << "You parried the incoming attack! \n";
}

void enemyParry() {
	std::cout << "The enemy parried your attack! \n";
}

void dodge() {
	std::cout << "You dodged the incoming attack! \n";
}

void enemyDodge() {
	std::cout << "The enemy dodged your attack! \n";

void miss() {
	std::cout << "You missed your attack! \n";
}

void enemyMiss() {
	std::cout << "The enemy missed their attack! \n";
}

class entity{

    public:
    int currentHealth;
    int maxHealth;
    std::string name1;
    int attack1Damage;
    int attack2Damage;
    bool isAlive = true;
    
    int combat(entity &player, entity &enemy){
        srand(time(NULL));

        char choice;
        int damageDealt;
        int damage = (rand() % 100) + 1; // random number for damage boost
		int parry = (rand() % 100) + 1; // random number for parry chance - your chance to parry enemy attack (10%)
		int enemyParry = (rand() % 100) + 1; // random number for enemy parry chance - enemy chance to parry your attack (10%)
		int miss = (rand() % 100) + 1; // random number for miss chance - your chance to miss attack (5%)
		int enemyMiss = (rand() % 100) + 1; // random number for enemy miss chance - enemy chance to miss attack (8%)
		int dodge = (rand() % 100) + 1; // random number for dodge chance - your chance to dodge enemy attack (10%)
		int enemyDodge = (rand() % 100) + 1; // random number for enemy dodge chance - enemy chance to dodge your attack (8%)

        std::cout << "Which attack would you like to perform? \n";
        std::cout << "Please enter 1 for Quick Attack or 2 for Strong attack! \n";
        std::cin >> choice;
        

        if(choice == 1){

            if(damage > 0 && damage <= 30){ // chance for weaker hit
                attack1Damage = attack1Damage * .80;
				std::cout << "Your Quick Attack hit for " << attack1Damage << " damage! \n";
                std::cout << "You did less damage than normal. \n";
                
            }

            else if(damage >= 85 && damage <= 100){ //critical hit
                attack1Damage = attack1Damage * 1.50;
				std::cout << "Your Quick Attack hit for " << attack1Damage << " damage! \n";
				std::cout << "It was a critical hit! \n";
			}
			else { // damage remains unchanged
				std::cout << "Your Quick Attack hit for " << attack1Damage << " damage! \n";
				std::cout << "You did a normal amount of damage. \n";

            }
           
        }

		return damageDealt;
    }

    entity(int health, std::string name, int attack1, int attack2){
        currentHealth = health;
        maxHealth = health;
        name1 = name;
        attack1Damage = attack1;
        attack2Damage = attack2; 
    }
};





int main(){

    entity player(500, "Player", 100, 150 );
    entity boar(200, "Wild Boar", 25, 50);
    entity lakeBandit(550, "Lake Bandit", 100, 125);
    entity boss(700, "Final Boss", 150, 200);



    return 0;
}

//attack2Damage = attack2Damage * .80;
//attack2Damage = attack2Damage * 1.50;