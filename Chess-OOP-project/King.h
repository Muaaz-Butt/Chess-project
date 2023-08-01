#ifndef KING_H
#define KING_H

#include "Piece.h"
#include "Player.h"
#include "Position.h"

using namespace std;

class King:public Piece{
public:
	King(int r, int c, Color C, Board* b);
	virtual void draw()override;
	bool legalities(Player* player, Board* b, Position source, Position destination);
	//virtual void drawInFile(ofstream& file);
	bool findKing();
};

#endif KING_H
