#include "Queen.h"

using namespace std;

Queen::Queen(int r, int c, Color C, Board* b) :Piece(r, c, C, b) {};

void Queen::draw() {
	cout << ((color == BLACK) ? 'q' : 'Q');
}

bool Queen::legalities(Player* player, Board* b, Position source, Position destination) {
	if (source.rowIndex == destination.rowIndex) {
		return (isHorizontalPathClear(player, b, source, destination));
	}
	else if (source.columnIndex == destination.columnIndex) {
		return (isVerticalPathClear(player, b, source, destination));
	}
	return (isDiagonal(source, destination) && (isDiagonalLeftToRightPathClear(player, b, source, destination) || isDiagonalRightToLeftPathClear(player, b, source, destination)));
}
