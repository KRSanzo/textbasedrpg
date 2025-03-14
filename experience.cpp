#include <iostream>
#include <map>


struct playerXP{
    int currentXP = 0;
    int maxXP = 250;
    int level = 1;
};

class quest{
    public:
    int questID;
    std::string questTitle;
    std::string questDescription;
    std::string objective;
    int objectiveCurrent;
    int objectiveRequired;
    int xpReward;
    int currencyReward;
    int reputationReward;
    std::string completionText;
    bool completed = false;

    quest(int questNumber, std::string title, std::string description, std::string objectiveDescription, int currentObjective, int requiredObjective, int xp, int currency, int rep, std::string endText){
        questID = questNumber;
        questTitle = title;
        questDescription = description;
        objective = objectiveDescription;
        objectiveCurrent = currentObjective;
        objectiveRequired = requiredObjective;
        xpReward = xp;
        currencyReward = currency;
        reputationReward = rep;
        completionText = endText;
    }

    void questAccept(quest quest){
        // adds quest to quest log
    }

    void questTrack(quest quest){
        // report objective progress?
    }

    /*
    Quest Log

    Quest: Current/Required || XP Reward: ### / Currency Reward: ###
    Quest: Current/Required || XP Reward: ### / Currency Reward: ###
    Quest: Current/Required || XP Reward: ### / Currency Reward: ###

    questTitle: objectiveCurrent/objectiveRequired || xpReward / currencyReward
    */
    std::map<std::map<std::string, std::string>,std::map<int, int>> questLog; // (Title, Objectives)(XP, Currency)
    std::map<std::string, std::string> questInfo; // (Quest Title, Quest Objectives)
    std::map<int, int> questRewards; // (XP, Currency)
};




void turnInQuest(quest info, playerXP &xp){
    std::cout << "You are turning in the quest: " << info.questTitle << "." << std::endl;
    std::cout << info.completionText << std::endl;
    std::cout << std:: endl;
    std::cin.ignore();
    std::cout << "You gained " << info.xpReward << " experience. \n";
    std::cin.ignore();
    std::cout << info.currencyReward << " coins have been added to your bag. \n";
    std::cin.ignore();
    std::cout << "You have earned " << info.reputationReward << " reputation with your faction. \n";
    std::cin.ignore();
    
    xp.currentXP = xp.currentXP + info.xpReward;

    if(xp.currentXP > xp.maxXP){
        xp.currentXP = xp.currentXP - xp.maxXP;
        xp.maxXP = xp.maxXP * 1.15;
        xp.level++;
    }
}
void printQuestLog(){

};

void printQuest(quest id){
    std::cout << "Quest: " << id.questTitle << std::endl;
    std::cout << "Description: " << std::endl << id.questDescription << std::endl;
    std::cout << std::endl;
    std::cout << id.objective << "  " << id.objectiveCurrent << "/" << id.objectiveRequired << std::endl;
    std::cout << std::endl;
    std::cout << "Experience Reward: " << id.xpReward << std::endl;
    std::cout << "Currency Reward: " << id.currencyReward << " coins \n";
    std::cout << "Reputation Reward: " << id.reputationReward << std::endl;

}

void showLevel(playerXP player){
    std::cout << "Current Level: " << player.level << std::endl;
    std::cout << "Experience Bar: " << player.currentXP << " XP / " << player.maxXP << " XP \n";
}

int main(){

    playerXP player; // Main Player XP
    quest quest1(1, "Slaughterhouse", "These Boars have been running all over the place. The local farmer hasn't been taking care of them. Tend to it, Warrior.", "Kill Boars", 0, 10, 100, 10, 100, "Well done, recruit. This will handle the problem for now. I appreciate you doing that."); // Quest Creation
    printQuest(quest1); // visual check to see quest
    // some combat to kill the boars and stuff
    player.currentXP = 225;
    showLevel(player);
    turnInQuest(quest1, player);
    showLevel(player);

    return 0;
}