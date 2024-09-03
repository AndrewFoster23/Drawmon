#pragma once
#include <string>

class Catch {
public:
	Catch(Drawmon& _drawmon1, Drawmon& _drawmon2);
	bool Encounter();
	bool throwBall();

private:
	Drawmon& drawmon1;
	Drawmon& drawmon2;
};