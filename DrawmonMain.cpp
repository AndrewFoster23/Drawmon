#include <iostream>
#include <string>
#include <vector>  
#include "Drawmon.h"
#include "Battle.h"
#include "Catch.h"

// bool displayField = true;
// bool displayText = false;

// bool displayBattle = false;
// bool displayBattleText = false;



int main(){
    std::vector<Drawmon>& dex = Drawmon::drawmonDex;
    // simulate battle
    Drawmon emberine = dex[0];
    Drawmon twigtail = dex[2];

    //Catch catchD = Catch(emberine, twigtail);

    /*bool caught = catchD.Encounter();
    if (caught) {
        std::cout << "You caught " << twigtail.getName() 
            << "!\n";
    }
    else {
        std::cout << "You didn't catch " << twigtail.getName()
            << "!\n";
    }*/

    Battle battle = Battle(emberine, twigtail);

    bool win = battle.Fight();
    if (win) {
        std::cout << "You won! \n";
    }
    else {
        std::cout << "You lost \n";
    }

    //std::cout << emberine.getLevel();
    
    return 0;
}