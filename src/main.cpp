#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Knight {
private:
    int xp;
    int stamina;
    bool inTavern;
    bool inTrainingYard;

public:
    Knight() {
        xp = 0;
        stamina = 0;
    }

    int getXp() {
        return xp;
    }

    void setXp(int xp) {
        this->xp = xp;
    }

    void incrementXp(int xp) {
        this->xp += xp;
    }

    int getStamina() {
        return stamina;
    }

    void setStamina(int stamina) {
        this->stamina = stamina;
    }

    void incrementStamina(int stamina) {
        this->stamina += stamina;
    }

    bool isInTavern() {
        return inTavern;
    }

    void setInTavern(bool inTavern) {
        this->inTavern = inTavern;
    }

    bool isInTrainingYard() {
        return inTrainingYard;
    }

    void setInTrainingYard(bool inTrainingYard) {
        this->inTrainingYard = inTrainingYard;
    }
};

class Codalot {
private:
    vector<Knight *> knights;

public:
    Codalot() {}

    void clearKnights() {
        knights.resize(0);
    }

    void addKnightToTrainingYard(Knight& knight) {
        knights.push_back(&knight);
        knight.setInTrainingYard(true);
        knight.setInTavern(false);
    }

    void addKnightToTavern(Knight& knight) {
        knights.push_back(&knight);
        knight.setInTavern(true);
        knight.setInTrainingYard(false);
    }

    void process() {
        for (auto it = knights.begin(); it != knights.end(); ++it) {
            Knight *knight = *it;
            knight->incrementStamina(knight->isInTavern() ? 1 : -1);
            knight->incrementXp(knight->isInTrainingYard() ? 1 : 0);
        }
    }

    void grantBonusXp() {
        int bonusKnights = 0;
        for (auto it = knights.begin(); it != knights.end(); ++it) {
            Knight *knight = *it;
            if (knight->getXp() >= 3) {
                bonusKnights++;
            }
        }
        if (bonusKnights == 3) {
            for (auto it = knights.begin(); it != knights.end(); ++it) {
                Knight *knight = *it;
                if (knight->getXp() >= 3) {
                    knight->setXp(knight->getXp() + 5);
                }
            }
        }
        if (bonusKnights == 5) {
            for (auto it = knights.begin(); it != knights.end(); ++it) {
                Knight *knight = *it;
                if (knight->getXp() >= 3) {
                    knight->setXp(knight->getXp() + 10);
                }
            }
        }
        if (bonusKnights == 6) {
            for (auto it = knights.begin(); it != knights.end(); ++it) {
                Knight *knight = *it;
                if (knight->getXp() >= 3) {
                    knight->setXp(knight->getXp() + 20);
                }
            }
        }
    }
};

int main(int argc, char **argv) {
    Codalot *codalot = (Codalot *)malloc(sizeof(Codalot));
    new(codalot) Codalot;

    vector<Knight> knights;
    for (int i = 0; i < 6; ++i) {
        Knight *knight = (Knight *)malloc(sizeof(Knight));
        new(knight) Knight;

        knights.push_back(*knight);
    }

    for (int i = 0; i < 24; ++i) {
        codalot->clearKnights();
        for (auto it = knights.begin(); it != knights.end(); ++it) {
            Knight& knight = *it;
            int randomVal = rand() % 2;
            if (randomVal == 0) {
                codalot->addKnightToTrainingYard(knight);
            } else if (randomVal == 1) {
                codalot->addKnightToTavern(knight);
            }
        }
        codalot->process();
    }
    codalot->grantBonusXp();

    int totalXp = 0;
    for (auto it = knights.begin(); it != knights.end(); ++it) {
        Knight& knight = *it;
        totalXp += knight.getXp();
    }
    cout << "Total XP earned by all " << knights.size() << " knights: " << totalXp << endl;
}