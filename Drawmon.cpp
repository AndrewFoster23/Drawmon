#include <iostream>
#include "Drawmon.h"
#include "Move.h"


Drawmon::Drawmon(std::string _name, std::string _nickName, int _drawmonDexNum,
    std::string _type, bool _male, int _level, int _xp, 
    int _hp, int _currHp,
    int _speed, std::string _heldItem,
    int _moveIndex1, int _moveIndex2, int _moveIndex3, int _moveIndex4){

    name = _name;
    nickName = _nickName;
    drawmonDexNum = _drawmonDexNum;
    type = _type;
    male = _male;
    level = _level;
    xp = _xp;
    hp = _hp;
    currHp = _currHp;
    speed = _speed;
    heldItem = _heldItem;
    moveIndex1 = _moveIndex1;
    moveIndex2 = _moveIndex2;
    moveIndex3 = _moveIndex3;
    moveIndex4 = _moveIndex4;
}

std::vector<Drawmon> Drawmon::drawmonDex = {
    {"Emberine", "", 1, "fire", true,
        5, 0, 45, 45, 20, "",
        0, 1, -1, -1},  //index 0

    {"Aquaspout", "", 3, "water", true,
        5, 0, 45, 45, 20, "",
        2, 1, -1, -1},  //index 1

    {"Twigtail", "", 5, "grass", true,
        5, 0, 45, 45, 20, "",
        3, 1, -1, -1},  //index 2
};

//xp will be every 3 fights ur pokemon levels up
