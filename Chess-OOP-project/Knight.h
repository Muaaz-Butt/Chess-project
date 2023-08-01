#ifndef KNIGHT_H
#define KNIGHT_H

#include <fstream>

#include "Piece.h"
#include "Player.h"
#include "Position.h"

class Board;

class Knight :public Piece {
public:
	Knight(int r, int c, Color C, Board* b);
	virtual void draw()override;
	bool legalities(Player* player, Board* b, Position source, Position destination);
	//void drawInFile(ofstream file);
};

#endif KNIGHT_H
