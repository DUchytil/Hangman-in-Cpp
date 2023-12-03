//
// Created by david on 12/2/2023.
//

#ifndef HELLOWORLD_PLAYERSTATS_H
#define HELLOWORLD_PLAYERSTATS_H

#include <iostream>
#include <string> // Include the string header

class PlayerStats {
public:
    PlayerStats();//Constructor

    std::string playerName = "None";
    int playerScore = 0;
    std::string playerWord = "None";
    int wordCharacterCount = 0;
    bool didWin = false;
    
};


#endif //HELLOWORLD_PLAYERSTATS_H
