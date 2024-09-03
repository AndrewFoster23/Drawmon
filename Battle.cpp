#include <iostream>
#include <cstdlib>
#include <ctime> 
#include "Battle.h"
#include "Move.h"
#include "Drawmon.h"

Battle::Battle(Drawmon& _drawmon1, Drawmon& _drawmon2)
	:drawmon1 (_drawmon1), drawmon2 (_drawmon2){}

bool Battle::Fight() {
	while (true) {
		//Speed
		if (drawmon1.getSpeed() > drawmon2.getSpeed()) {
			Attack();
			if (opponentDead()) {
				std::cout << drawmon2.getName() << " fainted. \n";
				return true;
			}
			AttackBot(drawmon2, drawmon1);
			if (userDead()) {
				std::cout << drawmon1.getName() << " fainted. \n";
				return false;
			}
			printHealth();
		}
		else {
			AttackBot(drawmon2, drawmon1);
			if (userDead()) {
				std::cout << drawmon1.getName() << " fainted. \n";
				return false;
			}
			Attack();
			if (opponentDead()) {
				std::cout << drawmon2.getName() << " fainted. \n";
				return true;
			}
			printHealth();
		}
	}
}

bool Battle::Attack() {
	bool validMoveChosen = false;
	Move currMove = Move::moveList[0];
	while (!validMoveChosen) {
		std::cout << "Choose a move: \n";
		printMoves(drawmon1);
		//drawmon2.setCurrHp(0);	//delete
		int choice;
		std::cin >> choice;

		if (choice == 1 and drawmon1.getMoveIndex1() != -1) {
			currMove = Move::moveList[drawmon1.getMoveIndex1()];
			validMoveChosen = true;
		}else if (choice == 2 and drawmon1.getMoveIndex2() != -1) {
			currMove = Move::moveList[drawmon1.getMoveIndex2()];
			validMoveChosen = true;
		}else if (choice == 3 and drawmon1.getMoveIndex3() != -1) {
			currMove = Move::moveList[drawmon1.getMoveIndex3()];
			validMoveChosen = true;
		}else if (choice == 4 and drawmon1.getMoveIndex4() != -1) {
			currMove = Move::moveList[drawmon1.getMoveIndex4()];
			validMoveChosen = true;
		}else {
			std::cout << "Choose a valid move \n";
		}
	}

	//accuracy test
	srand(time(0));
	int accuracyNum = std::rand() % 10 + 1;
	//std::cout << "accuracy num: " << accuracyNum << "\n";
	int accuracy = currMove.getAccuracy();
	bool missed = false;
	//std::cout << accuracyNum << "\n";
	if (accuracyNum > accuracy) {
		missed = true;
	}

	//weakness
	std::string weaknessEffect = 
		weakness(currMove.getType(), drawmon2.getType());
	//check for damage amount
	int damage = currMove.getDamage();
	std::string effect = "Effective";
	if (weaknessEffect == "ve") {
		damage *= 2;
		effect = "Super Effective";
	}
	else if (weaknessEffect == "nve") {
		damage *= 0.5;
		effect = "not very effective";
	}

	//subtract damage from opposition
	std::cout << drawmon1.getName() << " used "<< currMove.getName() << "! \n\n";

	if (missed) {
		std::cout << "The move missed \n\n";
		return false;
	}
	drawmon2.setCurrHp(drawmon2.getCurrHp() - damage);
	std::cout << "It was " << effect << "\n\n";
	//proably more, idk think abt it

	return true;
}

bool Battle::AttackBot(Drawmon d1, Drawmon d2) {
	bool validMoveChosen = false;
	Move currMove = Move::moveList[0];

	while (!validMoveChosen) {
		//std::cout << "Bot a move: \n";
		//printMoves(drawmon1);
		//drawmon2.setCurrHp(0);	//delete
		srand(time(0));
		int choice = std::rand() % 4 + 1;
		//std::cout << "bot choice num: " << choice << "\n";

		if (choice == 1 and drawmon2.getMoveIndex1() != -1) {
			currMove = Move::moveList[drawmon2.getMoveIndex1()];
			validMoveChosen = true;
		}
		else if (choice == 2 and drawmon2.getMoveIndex2() != -1) {
			currMove = Move::moveList[drawmon2.getMoveIndex2()];
			validMoveChosen = true;
		}
		else if (choice == 3 and drawmon2.getMoveIndex3() != -1) {
			currMove = Move::moveList[drawmon2.getMoveIndex3()];
			validMoveChosen = true;
		}
		else if (choice == 4 and drawmon2.getMoveIndex4() != -1) {
			currMove = Move::moveList[drawmon2.getMoveIndex4()];
			validMoveChosen = true;
		}
	}

	srand(time(0));
	int accuracyNum = std::rand() % 10 + 1;
	std::cout << "accuracy num: " << accuracyNum << "\n";
	int accuracy = currMove.getAccuracy();
	bool missed = false;
	//std::cout << accuracyNum << "\n";
	if (accuracyNum > accuracy) {
		missed = true;
	}

	//weakness
	std::string weaknessEffect =
		weakness(currMove.getType(), drawmon2.getType());
	//check for damage amount
	int damage = currMove.getDamage();
	std::string effect = "Effective";
	if (weaknessEffect == "ve") {
		damage *= 2;
		effect = "Super Effective!";
	}
	else if (weaknessEffect == "nve") {
		damage *= 0.5;
		effect = "not very effective";
	}

	//subtract damage from opposition
	std::cout << drawmon2.getName() << " used " << currMove.getName() << "! \n\n";
	if (missed) {
		std::cout << "The move missed \n\n";
		return false;
	}
	drawmon1.setCurrHp(drawmon1.getCurrHp() - damage);
	std::cout << "It was " << effect << "\n\n";
	//proably more, idk think abt it

	return true;
}

void Battle::printMoves(Drawmon drawmon) {
	int moveNum = 1;

	if (drawmon.getMoveIndex1() != -1) {
		std::cout << moveNum << ". " << Move::moveList[drawmon.getMoveIndex1()].getName() << "\n";
		moveNum++;
	}
	if (drawmon.getMoveIndex2() != -1) {
		std::cout << moveNum << ". " << Move::moveList[drawmon.getMoveIndex2()].getName() << "\n";
		moveNum++;
	}
	if (drawmon.getMoveIndex3() != -1) {
		std::cout << moveNum << ". " << Move::moveList[drawmon.getMoveIndex3()].getName() << "\n";
		moveNum++;
	}
	if (drawmon.getMoveIndex4() != -1) {
		std::cout << moveNum << ". " << Move::moveList[drawmon.getMoveIndex4()].getName() << "\n";
	}
}

bool Battle::userDead() {
	if (drawmon1.getCurrHp() <= 0) {
		drawmon1.setCurrHp(drawmon1.getHp());
		return true;
	}
	return false;
}

bool Battle::opponentDead() {
	if (drawmon2.getCurrHp() <= 0) {
		drawmon2.setCurrHp(drawmon2.getHp());

		drawmon1.setXp(drawmon1.getXp() + 1);
		if (drawmon1.getXp() == 3) {
			drawmon1.setXp(0);
			drawmon1.setLevel(drawmon1.getLevel() + 1);
			std::cout << drawmon1.getName() <<
				" leveled up to level " <<
				drawmon1.getLevel() << "! \n\n";
		}
		return true;
	}
	return false;
}

std::string Battle::weakness(std::string moveType, std::string d2Type) {
	if (moveType == "water" and d2Type == "fire") {
		return "ve";	//not very effective
	}
	else if (moveType == "fire" and d2Type == "water") {
		return "nve";	//very effective
	}
	else if (moveType == "fire" and d2Type == "grass") {
		return "ve";
	}
	else if (moveType == "grass" and d2Type == "fire") {
		return "nve";
	}
	else if (moveType == "grass" and d2Type == "water") {
		return "ve";
	}
	else if (moveType == "water" and d2Type == "grass") {
		return "nve";
	}
	else {
		return "e"; //effective
	}
	//CHECK IF: fire vs fire for example would be nve or e (currently e)

	//2d array, left is default, and right side is the weakness, for super effective
}

void Battle::printHealth() {
	std::cout << "\n" << drawmon1.getName() << " has " << drawmon1.getCurrHp()
		<< " HP \n";

	std::cout << drawmon2.getName() << " has " << drawmon2.getCurrHp()
		<< " HP \n\n";
}

//Ctrl + K + C : Comment out the selected code.Ctrl + K + U : Uncomment the selected code