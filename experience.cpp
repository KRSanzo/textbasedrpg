#include <iostream>


struct playerXP{
    int currentXP;
    int maxXP;
    int level;
};

struct questLog{};

class quest{
    int questID;
    std::string questTitle;
    std::string questDescription;
    std::string objective;
    int objectiveCurrent;
    int objectiveRequired;
    int xpReward;
    int currencyReward;
    int reputationReward;

    quest(int questID, std::string title, std::string description, std::string objective, int currentObjective, int requiredObjective, int xp, int currency, int rep){
        this->questID = questID;
        title = questTitle;
        description = questDescription;
        this->objective = objective;
        currentObjective = objectiveCurrent;
        requiredObjective = objectiveRequired;
        xp = xpReward;
        currency = currencyReward;
        rep = reputationReward;
    }

    void questAccept(quest quest){
        // adds quest to quest log
    }

    void questTrack(quest quest){
        // report objective progress?
    }

    void questTurnIn(quest quest, playerXP xp){
        // turn in quest to get experience
    }
};

void turnInQuest(){

}

int main(){

    playerXP player;


    return 0;
}