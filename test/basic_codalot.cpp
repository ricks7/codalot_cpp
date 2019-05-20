#include <vector>
#include <cstdlib>
#include "codalot.cpp"

using namespace std;

class Knight {
private:
    int xp;
    int stamina;
    bool inTavern;
    bool inTrainingYard;
public:
    Knight();

    int getXp();
    void setXp(int xp);
    void incrementXp(int xp);
    int getStamina();
    void setStamina(int stamina);
    void incrementStamina(int stamina);
    bool isInTavern();
    void setInTavern(bool inTavern);
    bool isInTrainingYard();
    void setInTrainingYard(bool inTrainingYard);
};

Knight::Knight() {
    xp = 0;
    stamina = 0;
}

int Knight::getXp() {
    return xp;
}

void Knight::setXp(int xp) {
    this->xp = xp;
}

void Knight::incrementXp(int xp) {
    this->xp += xp;
}

int Knight::getStamina() {
    return stamina;
}

void Knight::setStamina(int stamina) {
    this->stamina = stamina;
}

void Knight::incrementStamina(int stamina) {
    this->stamina += stamina;
}

bool Knight::isInTavern() {
    return inTavern;
}

void Knight::setInTavern(bool inTavern) {
    this->inTavern = inTavern;
}

bool Knight::isInTrainingYard() {
    return inTrainingYard;
}

void Knight::setInTrainingYard(bool inTrainingYard) {
    this->inTrainingYard = inTrainingYard;
}

class BasicCodalot : public Codalot {
private:
    vector<Knight *> knights;

public:
    BasicCodalot();

    void setKnight(int id, KnightPosition position);
    void process();
    int calculateEarnedXp();

    void clearKnights();
    void addKnightToTrainingYard(Knight *knight);
    void addKnightToTavern(Knight *knight);
    void grantBonusXp();
};

BasicCodalot::BasicCodalot() {
    for (int i = 0; i < 6; ++i) {
        Knight *knight = (Knight *)malloc(sizeof(Knight));
        new(knight) Knight;

        knights.push_back(knight);
    }
}

void BasicCodalot::setKnight(int id, KnightPosition position) {
    Knight *knight = knights[id];
    knight->setInTavern(false);
    knight->setInTrainingYard(false);
    switch (position) {
        case TAVERN: {
            knight->setInTavern(true);
            break;
        }
        case TRAINING_YARD: {
            knight->setInTrainingYard(true);
            break;
        }
    }
}

void BasicCodalot::process() {
    for (auto it = knights.begin(); it != knights.end(); ++it) {
        Knight *knight = *it;
        knight->incrementStamina(knight->isInTavern() ? 1 : -1);
        knight->incrementXp(knight->isInTrainingYard() ? 1 : 0);
    }
}

int BasicCodalot::calculateEarnedXp() {
    int total = 0;
    for (auto it = knights.begin(); it != knights.end(); ++it) {
        Knight *knight = *it;
        total += knight->getXp();
    }
    return total;
}

void BasicCodalot::clearKnights() {
    knights.resize(0);
}

void BasicCodalot::addKnightToTrainingYard(Knight *knight) {
    knights.push_back(knight);
    knight->setInTrainingYard(true);
    knight->setInTavern(false);
}

void BasicCodalot::addKnightToTavern(Knight *knight) {
    knights.push_back(knight);
    knight->setInTavern(true);
    knight->setInTrainingYard(false);
}

void BasicCodalot::grantBonusXp() {
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