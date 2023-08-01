#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"
#include "Player.h"
#include "Position.h"

using namespace std;

class Bishop :public Piece {
public:
	Bishop(int r, int c, Color C, Board* b);
	virtual void draw()override;
	bool legalities(Player* player, Board* b, Position source, Position destination);
};

#endif BISHOP_H
