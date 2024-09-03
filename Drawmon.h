#pragma once
#include <string>
#include "Move.h"

class Drawmon {
public:
    Drawmon(std::string _name, std::string _nickName, int _drawmonDexNum,
        std::string _type, bool _male, int _level, int _xp, 
        int _hp, int _currHp,
        int _speed, std::string _heldItem,
        int _moveIndex1, int _moveIndex2, int _moveIndex3, int _moveIndex4);

    static std::vector<Drawmon> drawmonDex;

    std::string getName() {
        return name;
    }

    void setName(std::string _name) {
        name = _name;
    }

    std::string getNickName() {
        return nickName;
    }

    void setNickName(std::string _nickName) {
        nickName = _nickName;
    }

    int getDrawmonDexNum() {
        return drawmonDexNum;
    }

    std::string getType() {
        return type;
    }

    bool getMale() {
        return male;
    }

    int getLevel() {
        return level;
    }

    void setLevel(int _level) {
        level = _level;
    }

    int getXp() {
        return xp;
    }

    void setXp(int _xp) {
        xp = _xp;
    }

    int getHp() {
        return hp;
    }

    void setHp(int _hp) {
        hp = _hp;
    }

    int getCurrHp() {
        return currHp;
    }

    void setCurrHp(int _currHp) {
        currHp = _currHp;
    }

    int getSpeed() {
        return speed;
    }

    void setSpeed(int _speed) {
        speed = _speed;
    }

    int getMoveIndex1() {
        return moveIndex1;
    }

    void setMoveIndex1(int _moveIndex1) {
        moveIndex1 = _moveIndex1;
    }

    int getMoveIndex2() {
        return moveIndex2;
    }

    void setMoveIndex2(int _moveIndex2) {
        moveIndex2 = _moveIndex2;
    }

    int getMoveIndex3() {
        return moveIndex3;
    }

    void setMoveIndex3(int _moveIndex3) {
        moveIndex3 = _moveIndex3;
    }

    int getMoveIndex4() {
        return moveIndex4;
    }

    void setMoveIndex4(int _moveIndex4) {
        moveIndex4 = _moveIndex4;
    }

private:
    std::string name;
    std::string nickName;
    int drawmonDexNum;
    std::string type;
    bool male;
    int level;
    int xp;
    int hp;
    int currHp;
    int speed;
    std::string heldItem;
    int moveIndex1;
    int moveIndex2;
    int moveIndex3;
    int moveIndex4;
};
