#include "Knight.h"
#include "Piece.h"
#include "Board.h"
#include "Chess.h"

using namespace std;

Knight::Knight(int r, int c, Color C, Board* b) : Piece(r, c, C, b) {};

void Knight::draw() {
	cout << ((color == BLACK) ? 'h' : 'H');
}

bool Knight::legalities(Player* player, Board* b, Position source, Position destination) {
	if ((source.rowIndex == destination.rowIndex + 2) && (source.columnIndex == destination.columnIndex + 1 || source.columnIndex == destination.columnIndex - 1)) {
		return true;
	}
	else if ((source.rowIndex == destination.rowIndex - 2) && (source.columnIndex == destination.columnIndex + 1 || source.columnIndex == destination.columnIndex - 1)) {
		return true;
	}
	else if ((source.rowIndex == destination.rowIndex - 1) && (source.columnIndex == destination.columnIndex + 2 || source.columnIndex == destination.columnIndex - 2)) {
		return true;
	}
	else if ((source.rowIndex == destination.rowIndex + 1) && (source.columnIndex == destination.columnIndex + 2 || source.columnIndex == destination.columnIndex - 2)) {
		return true;
	}
	return false;
}
