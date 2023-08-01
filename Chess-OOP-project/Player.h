#ifndef PLAYER_H
#define PLAYER_H

#include "Header.h"

class Player {
private:
	string name;
	Color color;
public:
	Player();
	Player(string name, Color color);
	string getName()const;
	Color getColor()const;
};


#endif PLAYER_H
