#include <iostream>
#include <map>
#include <vector>
#include <list>
#include <string>
#include <cmath>

class player{
    public:
    std::string name;
    std::string title;
    std::string friendName;
};

class playerStats{
    public:
    int currentHealth = 250;
    int maxHealth = 250;
    std::string playerClass;
    std::map<std::string, std::string> playerAbilities;
    int attack1Damage = 25;
    int attack2boost;
    int attack3Damage = 75;
    bool isAlive;

};

class thief{
    public:
    int currentHealth = 250;
    int maxHealth = 250;
    int damage = 25;
    bool isAlive;
};

std::map<std::string,std::string> inGameItems; // need to edit and have it run first
std::map<std::string,std::string> inventory; // will be able to be viewed throughout the game

void characterDefine(player &main, playerStats &player); // allows us to create our main character
void classAttackAssignment(player &main, playerStats &player); // gives us our attacks for the game based on class choice
void authorsNote();
void intro();

// With these functions, I will display the order of the story for the zone with incrementing numbers, as seen below
void villageStoryText1();
void villageStoryText2();
void villageStoryText3(player &main, std::map<std::string,std::string> &inventory, playerStats &player);
void VillageStoryText4(player &main, std::map<std::string,std::string> &inventory, playerStats &player, thief &robber);
void VillageStoryText5();

// With these functions, I will display the zone, the order which it happens, and the options for that question
void village3ChoiceA(player &main, playerStats &player); 
void village3ChoiceB();
void village4ChoiceA(player &main, std::map<std::string,std::string> &inventory, playerStats &player, thief &robber);
void village4ChoiceB();
void village4A(std::map<std::string,std::string> &inventory);
//void loadInGameItems(); // need to make a function that will load all in game items into the map, needs to run first
void checkInventory(std::map<std::string,std::string> &inventory);
void viewAttacks(player &main, playerStats &player);
void chooseAttack(player &main, playerStats &player);
int thiefAttack(player &main, playerStats &player, thief robber);
void fight1(player &main, playerStats &player, thief &robber);

int main(){
    std::string name;
    player p1;
    playerStats player1;
    thief robber;

    /*authorsNote();
    intro();
    villageStoryText1();
    villageStoryText2();*/
    characterDefine(p1,player1);
    classAttackAssignment(p1,player1);
    villageStoryText3(p1, inventory, player1);
    VillageStoryText4(p1, inventory, player1, robber);

    return 0;
}
void authorsNote(){
    std::cout << std::endl;
    std::cout << "You are playing the text-based RPG 'Dark Heart' by Kade Sanzo. \n";
    std::cout << "Finishing is not guaranteed, you must make choices wisely to reach the end. \n";
    std::cout << "May luck be ever in your favor... \n";
    std::cout << std::endl;
    std::cout << "Please press 'Enter' to continue. \n";
    std::cin.ignore();
}
void intro(){
    std::cout << "Before we begin the game, let's go over some basic mechanics! \n";
    std::cout << "Quest and Story text will flow at your discretion. When you are finished \n";
    std::cout << "reading, please push the 'Enter' key to spawn the next line of text. \n";
    std::cout << "Try it out now to see the next line of text. \n";
    std::cin.ignore();
    std::cout << "When a choice is to be made by you, the player, you will be prompted with \n";
    std::cout << "a question that you will learn to love: 'What would you like to do?' \n";
    std::cin.ignore();
    std::cout << "When asked what to do, you will receive a list of possible options that \n";
    std::cout << "will affect your character and the story that unfolds. \n";
    std::cin.ignore();
    std::cout << "Each choice has a response... some lucky, some not. But just remember: \n";
    std::cin.ignore();
    std::cout << "'Fortune Favours the Bold'- \n";
    std::cout << "                            Matt Damon \n";
    std::cin.ignore();
    std::cout << "To select an option from a list of choices presented to you; please enter the character associated with it. \n";
    std::cin.ignore();
    std::cout << R"(For example:
(A) Option 1
(B) Option 2
(C) Option 3

If you wanted to choose Option 3, you would enter the 'C' character on your keyboard)" << std::endl;
    std::cin.ignore();
    std::cout << "Would you like to begin Dark Heart? If so, press 'Enter' to proceed! \n";
    std::cout << "Good luck and Have fun! - Kade :) \n";
    std::cin.ignore();
}
void characterDefine(player &main, playerStats &player){
   
    while(main.name.empty()){
        std::cout << "Please enter your name adventurer: ";
        std::getline(std::cin,main.name);
    }

    std::cout << "Ah yes, you are indeed " << main.name << ". \n";
    std::cin.ignore();

    while(main.title.empty()){
        std::cout << "What title will you go by? Will you choose to follow Kade the Great? or Elijah the Loud? \n";
        std::cout << "Please enter your title, " << main.name << ": ";
        std::getline(std::cin,main.title);
        std::cout << std::endl;
    }

    std::cout << "What class would you like to play as " << main.name << "? This will be important later. \n";

    while(player.playerClass.empty()){
        std::cout << "Please choose from one of the options below: \n";
        std::cout << "(A) Warrior \n";
        std::cout << "(B) Mage \n";
        std::cout << "(C) Rogue \n";
        std::cout << "(D) Cleric \n";

        char classChoice;
        std::cin >> classChoice;

        if(classChoice == 'A' || classChoice == 'a'){
            player.playerClass = "Warrior";
        }
        else if(classChoice == 'B' || classChoice == 'b'){
            player.playerClass = "Mage";
        }
        else if(classChoice == 'C' || classChoice == 'c'){
            player.playerClass = "Rogue";
        }
        else if(classChoice == 'D' || classChoice == 'd'){
            player.playerClass = "Cleric";
        }
        else{
            std::cout << "Please choose a valid option from the options above. \n";
        }
    }
    std::cout << "Wow! " << main.name << " the " << player.playerClass << "! I can see why they call you " << main.title << "! \n";
    std::cin.ignore();

}
void classAttackAssignment(player &main, playerStats &player){

    if(player.playerClass == "Warrior"){
        player.playerAbilities.insert(std::pair<std::string, std::string> ("(A) Quick Attack - ", "A quick slash with your main hand! Deals Damage!"));
        player.playerAbilities.insert(std::pair<std::string, std::string> ("(B) Tighten Up - ", "Increase your grip, providing extra damage next turn!"));
        player.playerAbilities.insert(std::pair<std::string, std::string> ("(C) Block - ", "You raise up your bulwark, blocking 100% of the enemy attack!"));
        player.playerAbilities.insert(std::pair<std::string, std::string> ("(D) Collosal Swing - ", "Charge up all your might to swing heavy! Has chance to do large damage and increased chance to miss the target!"));   
    }
    else if(player.playerClass == "Mage"){
        player.playerAbilities.insert(std::pair<std::string, std::string> ("(A) Frostbolt - ", "Unleash a string of frost towards your enemy! Deals Damage!"));
        player.playerAbilities.insert(std::pair<std::string, std::string> ("(B) Magi Intellect - ", "Bathe in the arcanic minds once before you, providing extra damage next turn!"));
        player.playerAbilities.insert(std::pair<std::string, std::string> ("(C) Shimmer - ", "You teleport out of the way, blocking 100% of the enemy attack!"));
        player.playerAbilities.insert(std::pair<std::string, std::string> ("(D) Combust - ", "Charge up all your mana to burn bright and send an explosing of fire towards your enemy! Has chance to do large damage and increased chance to damage yourself!"));    
    }
    else if(player.playerClass == "Rogue"){
        player.playerAbilities.insert(std::pair<std::string, std::string> ("(A) Stab and Jab - ", "A flurry of strikes with your daggers! Deals Damage!"));
        player.playerAbilities.insert(std::pair<std::string, std::string> ("(B) Apply Poison - ", "Dip your dagger in poison, providing extra damage next turn!"));
        player.playerAbilities.insert(std::pair<std::string, std::string> ("(C) Vanish - ", "You disappear into the shadows, blocking 100% of the enemy attack! Increased chance to slip out of combat!"));
        player.playerAbilities.insert(std::pair<std::string, std::string> ("(D) Fan of Knives - ", "Discharge all your daggers while circling the target! Has chance to do large damage and increased chance to damage yourself!"));
    }
    else{ // cleric
        player.playerAbilities.insert(std::pair<std::string, std::string> ("(A) Light Shot - ", "Fire a beam of light towards the target! Deals Damage!"));
        player.playerAbilities.insert(std::pair<std::string, std::string> ("(B) Holy Embrace - ", "Call upon the light, providing extra damage next turn!"));
        player.playerAbilities.insert(std::pair<std::string, std::string> ("(C) Word of Light - ", "Chastise your opponent, reducing their attack power for the rest of the fight!"));
        player.playerAbilities.insert(std::pair<std::string, std::string> ("(D) Greater Heal - ", "Bask in light's rejuvenation! Restore health to yourself!"));
    }

}
void villageStoryText1(){
    std::cout << "Wooden houses line the cobbled streets, smoke rising from chimneys and \n"; 
    std::cout << "the faint sound of children's laughter drifting through the air.\n";
    std::cin.ignore();
    std::cout << "Market stalls are set up, offering everything from fresh produce to hand-crafted trinkets. \n";
    std::cin.ignore();
    std::cout << "The earthy scent of bread and herbs fills the air as townsfolk move about their business. \n";
    std::cin.ignore();
    std::cout << "The village of Tranquillo seems peaceful, yet there's an undercurrent of mystery in the air... \n";
    std::cin.ignore();
    std::cout << "as if everyone knows more than they let on... \n";
    std::cin.ignore();
}
void villageStoryText2(){
    std::cout << R"(The sun is just beginning to rise, casting a warm golden glow across the village. 
The air smells of fresh bread and earth, a soft breeze rustling the leaves of nearby trees.)" << std::endl;
    std::cin.ignore(); 
    std::cout << R"(Birds chirp from the rooftops, and the peaceful sounds of daily life fill the air.
It's a quiet morning in the village, and everything seems calm, yet there's an odd sense of anticipation hanging in the air.)" << std::endl;
    std::cin.ignore();
    std::cout << R"(You stand at the edge of the village, looking out over the simple stone cottages, the narrow streets, and the bustling marketplace.)" << std::endl;
    std::cin.ignore();
    std::cout << R"(You've been here before, but today feels different. Today, something is stirring within you. 
There's a feeling that your journey is about to begin.)" << std::endl;
    std::cin.ignore();
    std::cout << R"(As you take in the sights and sounds around you, you pause for a moment to reflect.)" << std::endl;
    std::cin.ignore();
    std::cout << "Who are you? ";
    std::cin.ignore();
    std::cout << "What brought you to this village? ";
    std::cin.ignore();
    std::cout << "What awaits you in the days to come? \n";
    std::cin.ignore();
    std::cout << R"(With a deep breath, you step forward into the heart of the village, 
and as the sunlight falls gently across your face, you finally realize: 
It's time to choose your name. This is where your story begins.)" << std::endl;
    std::cin.ignore();
    std::cout << "What name will you create for yourself? \n";
}
void villageStoryText3(player &main, std::map<std::string,std::string> &inventory, playerStats &player){

    std::cin.ignore();
    char choice1;
    std::cout << "*Back in Tranquillo* \n";
    std::cout << "You scramble around inside your pocket for a crumpled up piece of paper. \n";
    std::cin.ignore();
    std::cout << "You finally pull it out, only to see 3 words written hastily: \n";
    std::cin.ignore();
    std::cout << "Necklace\n";
    std::cin.ignore();
    main.friendName = "Alina";
    std::cout << main.friendName << "'s house\n";
    std::cin.ignore();
    std::cout << "You think to yourself 'Wow. I haven't seen " << main.friendName << " and her family in forever.\n";
    std::cout << "I wonder why my father asked me to go there yesterday.\n";
    std::cin.ignore();
    std::cout << "On the last line stood a single word: Market. \n";
    std::cout << std::endl;
    std::cin.ignore();
    std::cout << "The necklace is ready at my aunt's house. It's the first stop. \n";
    std::cin.ignore();
    std::cout << "My aunt Lorna is arguably famous, her jewelcrafting skills are renown across Tranquillo. \n";
    std::cin.ignore();
    std::cout << "Story goes that she got lucky with finding a gem washed up by the lake, and her fascination continued from there. \n";
    std::cin.ignore();
    std::cout << "Over time, she accumulated, created, and sold enough jewelry to have the most prominent house in town. \n";
    std::cin.ignore();
    std::cout << "I slipped going up the doorstep. Just like I do every time. I can never get used to these outdoor granite stairs. \n";
    std::cin.ignore();
    std::cout << "I didn't even have a chance to knock when the large marble front door slowly creaked open. \n";
    std::cin.ignore();
    std::cout << "'What is with all these heavy stones?' I thought to myself. \n";
    std::cout << std::endl;
    std::cin.ignore();
    
    std::cout << "'Ah my child, I could sense you were coming!' exclaimed Lorna. \n";
    std::cin.ignore();
    std::cout << "'I'm not surprised, these stairs make me take three steps forward and two steps back' I replied. \n";
    std::cin.ignore();
    std::cout << "I continued 'Do you have mom's necklace?' \n";
    std::cin.ignore();
    std::cout << "'But of course child' she replied. 'You know, this was once my necklace given to me by a suitor long ago.' \n";
    std::cin.ignore();
    std::cout << "'He thought he could impress ME with a stone so common!' she continued. 'But over time, I fell in love with the chain. \n";
    std::cin.ignore();
    std::cout << "Add a few enhancing gems, and a precious red garnet to complete the center of the piece. \n";
    std::cout << "Now it almost looks connecting, like some sort of lifeline between the piece' she giggled as she finally finished speaking. \n";
    std::cin.ignore();
    std::cout << "'Neat. Thanks for cleaning it up, it will look great for the memorial this weekend' I added. \n";
    std::cin.ignore();
    std::cout << R"('Oh...' Lorna looked off into the distance after I said that. 'I almost forgot the reason why I was polishing these stones.
I still feel like your mother is around. I'm sorry... I just -')" << std::endl;
    std::cin.ignore();
    std::cout << "She sighed. 'Please child. Take the necklace and leave me be. You know I love you, it's still just too fresh for me'. \n";
    std::cin.ignore();

    std::cout << "The necklace was added to your inventory. \n";
    inventory.insert(std::pair<std::string, std::string> ("Mom's Necklace", "Item Description: This necklace belonged to your mother. Look how clean!"));
    std::cin.ignore();

    while(choice1 != 'B' && choice1 != 'b'){
        std::cout << "What would you like to do? \n";
        std::cout << R"((A) Ask if she wants to talk about it.
(B) Say a heartfelt goodbye and leave the house.
(C) Check your inventory)" << std::endl;
        std::cin >> choice1;

        if(choice1 == 'A' || choice1 == 'a'){
            std::cout << "You have selected Option A.\n";
            std::cin.ignore();
            village3ChoiceA(main,player);
        }
        else if(choice1 == 'B' || choice1 == 'b'){
            std::cout << "You have selected Option B.\n";
            std::cin.ignore();
            village3ChoiceB();
        }
        else if(choice1 == 'C' || choice1 =='c'){
            std::cout << "You have selected Option C.\n";
            checkInventory(inventory);
            std::cin.ignore();
        }
        else{
            std::cout << "Please enter a valid option from the choices above! \n";
        }
    }

}
void checkInventory(std::map<std::string,std::string> &inventory){
    std::cout << std::endl;
    std::cout<< "Current Inventory" << std::endl;
    std::cout<< "-----------------" << std::endl;
    for(auto pair : inventory){
        std::cout << pair.first << " - " << pair.second;
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
void viewAttacks(player &main, playerStats &player){
    std::cout << std::endl;
    std::cout << "Attack List \n";
    std::cout << "----------- \n";

    for(auto pair : player.playerAbilities){
        std::cout << pair.first << pair.second;
        std::cout << std::endl;
    }
}
void chooseAttack(); //need to make
//int attackCalculator(); //need to make
//int enemyAttack();
void village3ChoiceA(player &main, playerStats &player){
    std::cout << "'Aunt Lorna, do you want to talk about it?' I asked \n";
    std::cin.ignore();
    std::cout << "'Child...' she started, 'I have days where it feels like she is still here. Looking at photos of us \n";
    std::cout << "makes it harder to remember what she was like before she disappeared.' \n";
    std::cin.ignore();
    std::cout << "'This was one necklace she was always trying to get me to perfect' she continued while rubbing the gem with her thumb. \n";
    std::cin.ignore();
    std::cout << "'What was stopping you?' I sounded almost confused when I asked. This was my aunt after all. \n";
    std::cin.ignore();
    std::cout << "'Your mother and I only recently reconnected when she reached out to me. I thought it would be... nice...' she paused \n";
    std::cin.ignore();
    std::cout << "'No, I thought it would be fair! Fair to finally give her something which she... ' she paused again. \n";
    std::cin.ignore();
    std::cout << "'Deserves.' An expression appeared on her face, but I wasn't sure how to make it out. \n";
    std::cin.ignore();
    std::cout << "'After all " << main.name << ", you are a " << player.playerClass << ".' she said in an ushered tone. \n";
    std::cin.ignore();


}
void village3ChoiceB(){
    std::cout << "'Well, the necklace looks great Aunt Lorna. I'm sure it will get lots of compliments at the memorial today' I said. \n";
    std::cin.ignore();
    std::cout << "'Thank you child, I wanted this piece to represent that heart that your mother had' Lorna grinned slyly as I turned towards the door \n";
    std::cin.ignore();
    std::cout << "A grin which turned into a smile as I pushed the door behind me on my way to brave the slippery steps \n";
    std::cin.ignore();
    std::cout << "As I made my way down, the necklace felt heavier than it just was. I don't think it's too big of a deal \n";
    std::cin.ignore();
}
void VillageStoryText4(player &main, std::map<std::string,std::string> &inventory, playerStats &player, thief &robber){
    std::cout << "What did she mean that I am a " << player.playerClass << "? Yes, people started gaining new ways to fight long ago. But does she think badly about " << player.playerClass << "s? \n";
    std::cin.ignore();
    std::cout << "The thought weighed on me, I have been practicing my abilities and physically training in secret. Could she notice a difference? \n";
    std::cin.ignore();
    std::cout << "I finally made it down those stupid stairs. I looked at my list once more: \n";
    std::cout << std::endl;
    std::cout << main.friendName << "'s" << " House \n";
    std::cin.ignore();
    std::cout << "'HELP! SOMEONE HELP!' a cry interrupted my thoughts from just around the corner. \n";
    std::cin.ignore();

    char choice1;
    while(choice1 != 'A' && choice1 != 'a'){
        std::cout << "What would you like to do? \n";
        std::cout << "(A) Go around the corner and investigate the scream. \n";
        std::cout << "(B) Carry on towards " << main.friendName << "'s house. \n";
        std::cout << "(C) Check your inventory. \n";
        std::cout << "(D) View your abilities. \n";

        std::cin >> choice1;

        if(choice1 == 'A' || choice1 == 'a'){
            std::cout << "You have selected Option A.\n";
            std::cin.ignore();
            village4ChoiceA(main, inventory, player, robber);
        }
        else if(choice1 == 'B' || choice1 == 'b'){
            std::cout << "You have selected Option B.\n";
            std::cin.ignore();
            village4ChoiceB();
        }
        else if(choice1 == 'C' || choice1 =='c'){
            std::cout << "You have selected Option C.\n";
            checkInventory(inventory);
            std::cout << std::endl;
            std::cin.ignore();
        }
        else if(choice1 == 'D' || choice1 == 'd'){
            std::cout << "You have selected Option D.\n";
            viewAttacks(main, player);
            std::cout << std::endl;
            std::cin.ignore();
        }
        else{
            std::cout << "Please enter a valid option from the choices above! \n";
        }
    }
}
void village4ChoiceA(player &main, std::map<std::string,std::string> &inventory, playerStats &player, thief &robber){
    std::cout << "You run over to the sound of the noise and turn the corner. \n";
    std::cin.ignore();
    std::cout << "You see a thief repeatedly yanking on a woman's purse! Despite her floundering, she is able to hold on with one hand! \n";
    std::cin.ignore();
    std::cout << "You engage, the thief notices you, and your first test of combat begins... \n";
    std::cin.ignore();
    fight1(main,player,robber);
}
void village4A(std::map<std::string,std::string> &inventory){
    std::cout << "That was a tough fight, but I think he will be out for a while. \n";
    std::cin.ignore();
    std::cout<< "'OH THANK YOU!' I turned towards the sound of the distressed lady, now sitting on the floor appearing to rest. \n";
    std::cin.ignore();
    std::cout << "'My husband is an alchemist', she started saying. 'Have a potion he gave to me just in case, you deserve it after that fight!\n";
    inventory.insert(std::pair<std::string, std::string> ("Health Potion", "Use this to restore 20% of your health."));
    std::cin.ignore();
    std::cout << "I thanked her and continued on my way. \n";
}
void village4ChoiceB(){
    std::cout << std::endl;
    std::cout << "You turn around and decide to take the long way. \n";
    std::cin.ignore();
    std::cout << "The cries for help grow stronger and harder to ignore... \n";
    std::cin.ignore();
    std::cout << "You grip your hands into a fist and look down. \n";
    std::cin.ignore();
    std::cout << "You turn back around and run towards the screams. \n";
    std::cin.ignore();
}
void fight1(player &main, playerStats &player, thief &robber){
   
    while(player.isAlive && robber.isAlive){
        char choice;

        if(player.playerClass == "Mage" || player.playerClass == "Warrior" || player.playerClass == "Rogue"){
            std::cout << "Your Health: " << player.currentHealth << std::endl;
            std::cout << "Enemy Health: " << robber.currentHealth << std::endl;
            std::cout << "What would you like to do? \n";
            viewAttacks(main, player);
            std::cin >> choice;

            if(choice == 'A' || choice == 'a'){
                robber.currentHealth = robber.currentHealth - player.attack1Damage;
                std::cout << "You strike the thief for " << player.attack1Damage << " damage! \n";
                thiefAttack(main, player, robber);
            }
            else if(choice == 'B' || choice == 'b'){
                player.attack1Damage = player.attack1Damage * 1.25;
                player.attack3Damage = player.attack3Damage * 1.25;
                std::cout << "Damage Abilities Increased! \n";
                thiefAttack(main, player, robber);
            }
            else if(choice == 'D' || choice == 'd'){
                robber.currentHealth = robber.currentHealth - player.attack3Damage;
                srand(time(NULL));
                int hit = (rand() % 4) + 1;

                if(hit == 1 || hit == 2){
                    std::cout << "Your special attack missed! \n";
                    thiefAttack(main, player, robber);
                }
                else{
                    std::cout << "You strike the thief for " << player.attack3Damage << " damage! \n";
                    thiefAttack(main, player, robber);
                }    
            }
            else if(choice == 'C' || choice == 'c'){
                std::cout << "You do not feel any attack damage from the thief! \n";

            }

            if(player.currentHealth <=0){
                player.isAlive = false;
                std::cout << "You have died an admirable death... Sorry to see you go so soon!\n";
                std::cin.ignore();
                std::cout << "But not to worry, " << main.name << ", you can try again at any time. \n";
                std::cout << "Thank you for playing!";
            }
            else if(robber.currentHealth <= 0){
                robber.isAlive = false;
                village4A(inventory);
            
            }
        }
        else if(player.playerClass == "Cleric"){
            std::cout << "Your Health: " << player.currentHealth << std::endl;
            std::cout << "Enemy Health: " << robber.currentHealth << std::endl;
            std::cout << "What would you like to do? \n";
            viewAttacks(main, player);
            std::cin >> choice;

            if(choice == 'A' || choice == 'a'){
                robber.currentHealth = robber.currentHealth - player.attack1Damage;
                std::cout << "You strike the thief for " << player.attack1Damage << " damage! \n";
                thiefAttack(main, player, robber);
            }
            else if(choice == 'B' || choice == 'b'){
                player.attack1Damage = player.attack1Damage * 1.25;
                player.attack3Damage = player.attack3Damage * 1.25;
                std::cout << "Damage Abilities Increased! \n";
                thiefAttack(main, player, robber);
            }
            else if(choice == 'D' || choice == 'd'){
                player.currentHealth = player.currentHealth + (player.currentHealth * 0.2);
                std::cout << "You have healed yourself! \n";  
            }
            else if(choice == 'C' || choice == 'c'){
                robber.damage = robber.damage * 0.80;
                std::cout << "The thief's attack power has been reduced! \n";
                thiefAttack(main, player, robber);
            }

            if(player.currentHealth <=0){
                player.isAlive = false;
                std::cout << "You have died an admirable death... Sorry to see you go so soon!\n";
                std::cin.ignore();
                std::cout << "But not to worry, " << main.name << ", you can try again at any time. \n";
                std::cout << "Thank you for playing!";
            }
            else if(robber.currentHealth <= 0){
                robber.isAlive = false;
                village4A(inventory);
            
            }    
        }

    }
}
int thiefAttack(player &main, playerStats &player, thief robber){

    srand(time(NULL));
    int booster = (rand() % 10) +1 ; // damage booster;

    if(booster >= 0 && booster <=3){
        robber.damage = robber.damage * .75;
        player.currentHealth = player.currentHealth - robber.damage;
    }
    else if(booster > 3 && booster <= 7){
        robber.damage = robber.damage;
        player.currentHealth = player.currentHealth - robber.damage;
    }
    else{
        robber.damage = robber.damage * 1.3;
        player.currentHealth = player.currentHealth - robber.damage;
    }

    std::cout << "The thief attacked you for " << robber.damage << " damage!\n";
    
    if(booster >= 0 && booster <=3){
        std::cout << "It did less damage than normal. \n";
    }
    else if(booster > 3 && booster <= 7){
        std::cout << "It did a normal amount of damage. \n";
    }
    else{
        std::cout << "It was a critical hit! \n";
    }
    std::cout << std::endl;
    return 0;
}
void VillageStoryText5(){
    std::cin.ignore();
    std::cout << "I finally made my way towards Alina and her family's house. I can't stop staring at this potion in my bag. \n";
    std::cin.ignore();
    std::cout << "There are a lot of people gathered outside the front. I wonder what this is all about. \n";
    std::cin.ignore();
    std::cout << "As I get closer, I see the ground littered in lit candles, paintings thrown aside, and hear the faint whispers of deep praying. \n";
    std::cin.ignore();
}