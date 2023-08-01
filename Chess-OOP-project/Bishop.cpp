#include "Bishop.h"
#include "Piece.h"

using namespace std;

Bishop::Bishop(int r, int c, Color C, Board* b) :Piece(r, c, C, b) {};

void Bishop::draw() {
	cout << ((color == BLACK) ? 'b' : 'B');
}

bool Bishop::legalities(Player* player, Board* b, Position source, Position destination) {

	return (isDiagonal(source, destination) && (isDiagonalLeftToRightPathClear(this->player[turn], b, source, destination) || isDiagonalRightToLeftPathClear(this->player[turn]	, b, source, destination)));
}