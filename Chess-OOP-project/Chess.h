#ifndef CHESS_H
#define CHESS_H

#include "Player.h";
#include "Piece.h"
#include"Position.h"

class Board;

class Chess {
private:
	Position source;
	Position destination;
	int turn;
	Player* player[2];
	Board* b;
public:
	Chess();
	void play();
	void displayTurnMessage(Player* player);
	void selectPiece();
	void selectDestination();
	bool validSourceSelection(Player* player, int r, int c);
	bool validDestinationSelection(Player* player, int r, int c);
	void turnChange();
	void deepCopyBoard(Board*& board);
	Position kingPosition(Board* board, Player* player);
	bool check(Piece* piece, Board* board, Player* player, Position source, Position destination);
	void moveForSelfCheck(Board*& boardCopy, Position source, Position destination);
	bool selfCheck(Piece* piece, Position source, Position destination,bool** arr, bool isKingChecked);
	bool isCheckMate(Piece* piece, Board* b, Player* player, Position sourrce, Position destination, bool** arr);
};

#endif CHESS_h
