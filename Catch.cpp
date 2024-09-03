#include <iostream>
#include <cstdlib>
#include <ctime>  
#include "Battle.h"
#include "Move.h"
#include "Drawmon.h"
#include "Catch.h"

Catch::Catch(Drawmon& _drawmon1, Drawmon& _drawmon2)
	:drawmon1(_drawmon1), drawmon2(_drawmon2) {}

bool Catch::Encounter() {
	std::cout << drawmon2.getName() << " appeared!\n";
	Battle battle = Battle(drawmon1, drawmon2);
	while (true) {
		//Speed
		std::cout << "Will you use a Draw Ball? (y/n)\n";
		std::string choice;
		std::cin >> choice;

		if (choice == "y") {
			bool caught = throwBall();
			if (caught) {
				//put some way for trainer to obtain the drawmon
				return true;
			}
			else {
				std::cout << drawmon2.getName() << " escaped! \n";
				battle.AttackBot(drawmon2, drawmon1);
				if (battle.userDead()) {
					std::cout << drawmon1.getName() << " fainted. \n";
					return false;
				}
				
				if (battle.opponentDead()) {
					std::cout << drawmon2.getName() << " fainted. \n";
					return true;
				}
				battle.printHealth();
			}
		}
		else {
			if (drawmon1.getSpeed() > drawmon2.getSpeed()) {
				battle.Attack();
				if (battle.opponentDead()) {
					std::cout << drawmon2.getName() << " fainted. \n";
					return false;
				}
				battle.AttackBot(drawmon2, drawmon1);
				if (battle.userDead()) {
					std::cout << drawmon1.getName() << " fainted. \n";
					return false;
				}
				battle.printHealth();
			}
			else {
				battle.AttackBot(drawmon2, drawmon1);
				if (battle.userDead()) {
					return false;
				}
				battle.Attack();
				if (battle.opponentDead()) {
					return false;
				}
				battle.printHealth();
			}
		}
	}
}

bool Catch::throwBall() {
	//chance of catching a pokemon based on health and level possibly
	srand(time(0));
	int chance = 100 - (((double) drawmon2.getCurrHp() / drawmon2.getHp()) * 100);
	int randNum = std::rand() % 100 + 1;
	//std::cout << "possible: " << chance << "\n";
	//std::cout << "catch num: " << randNum << "\n";
	if (randNum <= chance) {
		return true;
	}
	else {
		return false;
	}
}