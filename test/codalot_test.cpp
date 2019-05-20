#include <iostream>
#include <cassert>
#include "basic_codalot.cpp"

int main(int argc, char **argv) {
    Codalot *codalot = (Codalot *)malloc(sizeof(BasicCodalot));
    new(codalot) BasicCodalot;

    codalot->setKnight(0, TAVERN);
    codalot->setKnight(1, TAVERN);
    codalot->setKnight(2, TRAINING_YARD);
    codalot->setKnight(3, TRAINING_YARD);
    codalot->setKnight(4, TRAINING_YARD);
    codalot->setKnight(5, TRAINING_YARD);
    codalot->process();

    assert(codalot->calculateEarnedXp() == 4);
}
