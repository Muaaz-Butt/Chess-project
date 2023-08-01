#ifndef PIECE_H
#define PIECE_H

#include "Header.h"
#include "Position.h"

class Player;
class Board;

class Piece {
protected:
	int ri;
	int ci;
	Color color;
	Board* board;
	int turn;
	Player* player[2];
	bool isHorizontalPathClear(Player* player,Board* b,Position source,Position destination);
	bool isVerticalPathClear(Player* player, Board* b, Position source, Position destination);
	bool isDiagonal(Position source,Position destination);
	bool isDiagonalLeftToRightPathClear(Player* player, Board* b, Position source, Position destination);
	bool isDiagonalRightToLeftPathClear(Player* player, Board* b, Position source, Position destination);
public:
	Piece(int r, int c, Color C,Board* b);
	void move(int r, int c);
	virtual void draw() = 0;
	virtual bool legalities(Player* player, Board* b, Position source, Position destinantion);
	Color getColor();
	virtual bool findKing();
};

#endif PIECE_H
