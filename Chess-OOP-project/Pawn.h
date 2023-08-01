#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"
#include "Player.h"
#include "Position.h"

class Pawn :public Piece {
public:
	Pawn(int r, int c, Color C, Board* b);
	virtual void draw()override;
	bool legalities(Player* player, Board* b, Position source, Position destination);
	void promotionChoice(Player* player, Board* b, Position source, Position destination);
	//void drawInFile(ofstream file);
};

#endif PAWN_H
