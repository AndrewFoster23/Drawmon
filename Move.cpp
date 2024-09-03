#include <iostream>
#include "Move.h"

Move::Move(std::string _name, std::string _type, std::string _description,
    int _damage, int _accuracy) {
    name = _name;
    type = _type;
    damage = _damage;
    accuracy = _accuracy;
}

std::vector<Move> Move::moveList = {
    {"Fire Ball", "fire", "A small flame ball", 30, 10},
    {"Slice", "normal", "scratch", 30, 10},
    {"Water Squirt", "water", "A small splash of water", 30, 10},
    {"Stick Bind", "grass", "Sharp sticks are shot", 30, 10},
};
