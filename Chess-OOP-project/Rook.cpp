#include "Rook.h"

using namespace std;

Rook::Rook(int r, int c, Color C, Board* b) : Piece(r, c, C, b) {};

void Rook::draw() {
	 cout << ((color == BLACK) ? 'r' : 'R');
}

bool Rook::legalities(Player* player, Board* b, Position source, Position destination) {
	if (source.rowIndex == destination.rowIndex) {
		return (isHorizontalPathClear(player, b, source, destination));
	}
	else if (source.columnIndex == destination.columnIndex) {
		return (isVerticalPathClear(player, b, source, destination));
	}
	else {
		return false;
	}
}
