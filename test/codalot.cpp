#include "knight_position.cpp"

class Codalot {
public:
    virtual void setKnight(int id, KnightPosition position) = 0;
    virtual void process() = 0;
    virtual int calculateEarnedXp() = 0;
};
