#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"
#include "Player.h"
#include "Position.h"

using namespace std;

class Queen :public Piece {
public:
	Queen(int r, int c, Color C, Board* b);
	virtual void draw()override;
	bool legalities(Player* player, Board* b, Position source, Position destination);
};

#endif QUEEN_H
