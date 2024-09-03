#pragma once
#include <string>
#include "Drawmon.h"

class Battle {
public:
	Battle(Drawmon& _drawmon1, Drawmon& _drawmon2);
	bool Fight();
	bool Attack();
	bool AttackBot(Drawmon d1, Drawmon d2);
	void printMoves(Drawmon drawmon);
	bool userDead();
	bool opponentDead();
	std::string weakness(std::string moveType, std::string d2Type);
	void printHealth();

private:
	Drawmon& drawmon1;
	Drawmon& drawmon2;
};