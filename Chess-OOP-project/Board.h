#ifndef BOARD_H
#define BOARD_H

#include "Position.h"

class Piece;

class Board {
public:
	Piece*** piece;
	Board();
	void displayBoard();
	Piece* getPieceAt(int r, int c);
	void move(Position source, Position destination);
};

#endif BOARD_H
