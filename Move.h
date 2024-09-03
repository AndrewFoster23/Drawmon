#pragma once
#include <string>
#include <vector>

class Move {
public:
	Move(std::string _name, std::string _type, std::string _description, 
		int _damage, int _accuracy);
	std::vector<Move> move;
	static std::vector<Move> moveList;

	std::string getName() {
		return name;
	}

	std::string getType() {
		return type;
	}

	int getDamage() {
		return damage;
	}

	int getAccuracy() {
		return accuracy;
	}

private:
	std::string name;
	std::string type;
	std::string description;
	int damage;
	int accuracy;
};
