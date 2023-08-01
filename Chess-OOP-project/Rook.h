#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"
#include "Player.h"
#include "Position.h"

class Rook :public Piece {
public:
	Rook(int r, int c, Color C, Board* b);
	virtual void draw()override;
	bool legalities(Player* player, Board* b, Position source, Position destination);
};

#endif ROOK_H
