#include <iostream>

class entity{

    public:
    int currentHealth;
    int maxHealth;
    std::string name1;
    int attack1Damage;
    int attack2Damage;
    bool isAlive = true;
    
    int attack(){
        srand(time(NULL));

        char choice;

        std::cout << "Which attack would you like to perform? \n";
        std::cout << "Please enter 1 for small attack or 2 for large attack \n";
        std::cin >> choice;

        if(choice = 1){
            int damage = (rand() % 10) + 1;

            if(damage > 0 && damage <= 3){
                attack1Damage = attack1Damage * .80;
            }

            else if(damage >= 7 && damage <= 10){
                attack1Damage = attack1Damage * 1.50;
                

            }
            else{
                // damage remains unchanged
            }
        }
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