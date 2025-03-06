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
}

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
    std::string name;
    int attack1Damage;
    int attack2Damage;
    bool isAlive = true;

	void enemyAttack(entity& player, entity& enemy) {
		srand(time(NULL));

		int abilityChoice = (rand() % 2) + 1; // random number for enemy ability choice
		int damage = (rand() % 100) + 1; // random number for enemy damage boost
		int parry = (rand() % 100) + 1; // random number for parry chance - your chance to parry enemy attack (10%)
		int enemyMiss = (rand() % 100) + 1; // random number for enemy miss chance - enemy chance to miss attack (8%)
		int enemyDodge = (rand() % 100) + 1; // random number for enemy dodge chance - enemy chance to dodge your attack (8%)

		if (abilityChoice == 1) {
			if (damage > 0 && damage <= 30) { // chance for weaker hit
				attack1Damage = attack1Damage * .80;
				if (parry >= 90) { // parry chance
					parry();
				}
				else if (enemyMiss >= 92) { // miss chance
					enemyMiss();
				}
				else if (enemyDodge >= 92) { // dodge chance
					enemyDodge();
				}
				else {
					std::cout << "The enemy's Quick Attack hit for " << attack1Damage << " damage! \n";
					std::cout << "The enemy did less damage than normal. \n";
					player.currentHealth = player.currentHealth - attack1Damage;
				}
			}
			else if (damage >= 85 && damage <= 100) { //critical hit
				attack1Damage = attack1Damage * 1.50;
				if (parry >= 90) { // parry chance
					parry();
				}
				else if (enemyMiss >= 92) { // miss chance
					enemyMiss();
				}
				else if (enemyDodge >= 92) { // dodge chance
					enemyDodge();
				}
				else {
					std::cout << "The enemy's Quick Attack hit for " << attack1Damage << " damage! \n";
					std::cout << "It was a critical hit! \n";
					player.currentHealth = player.currentHealth - attack1Damage;
				}
			}
			else { // damage remains unchanged
				if (parry >= 90) { // parry chance
					parry();
				}
				else if (enemyMiss >= 92) { // miss chance
					enemyMiss();
				}
				else if (enemyDodge >= 92) { // dodge chance
					enemyDodge();
				}
				else {
					std::cout << "The enemy's Quick Attack hit for " << attack1Damage << " damage! \n";
					std::cout << "The enemy did a normal amount of damage. \n";
					player.currentHealth = player.currentHealth - attack1Damage;
				}
			}
		}
		if (abilityChoice == 2) {
			if (damage > 0 && damage <= 30) { // chance for weaker hit
				attack2Damage = attack2Damage * .80;
				if (parry >= 90) { // parry chance
					parry();
				}
				else if (enemyMiss >= 92) { // miss chance
					enemyMiss();
				}
				else if (enemyDodge >= 92) { // dodge chance
					enemyDodge();
				}
				else {
					std::cout << "The enemy's Quick Attack hit for " << attack2Damage << " damage! \n";
					std::cout << "The enemy did less damage than normal. \n";
					player.currentHealth = player.currentHealth - attack1Damage;
				}
			}
			else if (damage >= 85 && damage <= 100) { //critical hit
				attack2Damage = attack2Damage * 1.50;
				if (parry >= 90) { // parry chance
					parry();
				}
				else if (enemyMiss >= 92) { // miss chance
					enemyMiss();
				}
				else if (enemyDodge >= 92) { // dodge chance
					enemyDodge();
				}
				else {
					std::cout << "The enemy's Quick Attack hit for " << attack2Damage << " damage! \n";
					std::cout << "It was a critical hit! \n";
					player.currentHealth = player.currentHealth - attack1Damage;
				}
			}
			else { // damage remains unchanged
				if (parry >= 90) { // parry chance
					parry();
				}
				else if (enemyMiss >= 92) { // miss chance
					enemyMiss();
				}
				else if (enemyDodge >= 92) { // dodge chance
					enemyDodge();
				}
				else {
					std::cout << "The enemy's Quick Attack hit for " << attack2Damage << " damage! \n";
					std::cout << "The enemy did a normal amount of damage. \n";
					player.currentHealth = player.currentHealth - attack1Damage;
				}
			}
		}

    
		void combat(entity & player, entity & enemy) {
			srand(time(NULL));

			char choice;
			int damageDealt;
			int damage = (rand() % 100) + 1; // random number for damage boost
			int parry = (rand() % 100) + 1; // random number for parry chance - your chance to parry enemy attack (10%)
			int miss = (rand() % 100) + 1; // random number for miss chance - your chance to miss attack (5%)
			int dodge = (rand() % 100) + 1; // random number for dodge chance - your chance to dodge enemy attack (10%)

			do {
				std::cout << "You are fighting " << enemy.name1 << "! \n";
				std::cout << "The enemy has " << enemy.currentHealth << " health! \n";

				std::cout << "Which attack would you like to perform? \n";
				std::cout << "Please enter 1 for Quick Attack or 2 for Strong attack! \n";
				std::cin >> choice;
			} while (player.currentHealth > 0 && enemy.currentHealth > 0);)


			if (choice == 1) {

				if (damage > 0 && damage <= 30) { // chance for weaker hit
					attack1Damage = attack1Damage * .80;
					if (parry >= 90) { // parry chance
						enemyParry();
						enemyAttack(player, enemy);
					}

					else if (miss >= 95) { // miss chance
						miss();
						enemyAttack(player, enemy);
					}
					else if (dodge >= 90) { // dodge chance
						dodge();
						enemyAttack(player, enemy);
					}
					else {
						std::cout << "Your Quick Attack hit for " << attack1Damage << " damage! \n";
						std::cout << "You did less damage than normal. \n";
						enemy.currentHealth = enemy.currentHealth - attack1Damage;
						enemyAttack(player, enemy);
					}
				}

				else if (damage >= 85 && damage <= 100) { //critical hit
					attack1Damage = attack1Damage * 1.50;
					if (parry >= 90) { // parry chance
						enemyParry();
						enemyAttack(player, enemy);
					}
					else if (miss >= 95) { // miss chance
						miss();
						enemyAttack(player, enemy);
					}
					else if (dodge >= 90) { // dodge chance
						dodge();
						enemyAttack(player, enemy);
					}
					else {
						std::cout << "Your Quick Attack hit for " << attack1Damage << " damage! \n";
						std::cout << "It was a critical hit! \n";
						enemy.currentHealth = enemy.currentHealth - attack1Damage;
						enemyAttack(player, enemy);
					}
				}
				else { // damage remains unchanged
					if (parry >= 90) { // parry chance
						enemyParry();
						enemyAttack(player, enemy);
					}
					else if (miss >= 95) { // miss chance
						miss();
						enemyAttack(player, enemy);
					}
					else if (dodge >= 90) { // dodge chance
						dodge();
						enemyAttack(player, enemy);
					}
					else {
						std::cout << "Your Quick Attack hit for " << attack1Damage << " damage! \n";
						std::cout << "You did a normal amount of damage. \n";
						enemy.currentHealth = enemy.currentHealth - attack1Damage;
						enemyAttack(player, enemy);
					}
				}

			}
			else if (choice == 2) {
				if (damage > 0 && damage <= 30) { // chance for weaker hit
					attack2Damage = attack2Damage * .80;
					if (parry >= 90) { // parry chance
						enemyParry();
						enemyAttack(player, enemy);
					}
					else if (miss >= 95) { // miss chance
						miss();
						enemyAttack(player, enemy);
					}
					else if (dodge >= 90) { // dodge chance
						dodge();
						enemyAttack(player, enemy);
					}
					else {
						std::cout << "Your Strong Attack hit for " << attack2Damage << " damage! \n";
						std::cout << "You did less damage than normal. \n";
						enemy.currenthealth = enemy.currentHealth - attack2Damage;
						enemyAttack(player, enemy);
					}
				}

				else if (damage >= 85 && damage <= 100) { //critical hit
					attack2Damage = attack2Damage * 1.50;
					if (parry >= 90) { // parry chance
						enemyParry();
						enemyAttack(player, enemy);
					}
					else if (miss >= 95) { // miss chance
						miss();
						enemyAttack(player, enemy);
					}
					else if (dodge >= 90) { // dodge chance
						dodge();
						enemyAttack(player, enemy);
					}
					else {
						std::cout << "Your Strong Attack hit for " << attack2Damage << " damage! \n";
						std::cout << "It was a critical hit! \n";
						enmemy.currentHealth = enemy.currentHealth - attack2Damage;
						enemyAttack(player, enemy);
					}
				}

				else { // damage remains unchanged
					if (parry >= 90) { // parry chance
						enemyParry();
						enemyAttack(player, enemy);
					}
					else if (miss >= 95) { // miss chance
						miss();
						enemyAttack(player, enemy);
					}
					else if (dodge >= 90) { // dodge chance
						dodge();
						enemyAttack(player, enemy);
					}
					else {
						std::cout << "Your Strong Attack hit for " << attack2Damage << " damage! \n";
						std::cout << "You did a normal amount of damage. \n";
						enemy.currentHealth = enemy.currentHealth - attack2Damage;
						enemyAttack(player, enemy);
					}

				}

			}

			if (player.currentHealth <= 0) {
				std::cout << "You have been defeated by " << enemy.name << "!\n";
				player.isAlive = false;
			}

			else{
				std::cout << "You have defeated the" << enemy.name << "! \n";
				enemy.isAlive = false;
				player.currentHealth = player.maxHealth;
		};

    entity(int health, std::string name, int attack1, int attack2){
        currentHealth = health;
        maxHealth = health;
        name1 = name;
        attack1Damage = attack1;
        attack2Damage = attack2; 
    }
};





int main(){
	std::string location;

    entity player(500, "Player", 100, 150 );
    entity boar(200, "Wild Boar", 25, 50);
    entity lakeBandit(550, "Lake Bandit", 100, 125);
    entity boss(700, "Final Boss", 150, 200);

	player.combat(player, boar);



    return 0;
}

//attack2Damage = attack2Damage * .80;
//attack2Damage = attack2Damage * 1.50;