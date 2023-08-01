#include "King.h"
#include "Board.h"
#include "Header.h"

#include <iostream>
	
using namespace std;

King::King(int r, int c, Color C, Board* b) :Piece(r, c, C, b) {};

void King::draw() {
	cout << ((color == BLACK) ? 'k' : 'K');
}

//void King::drawInFile(ofstream& file) {
//	file << ((color == BLACK) ? 'k' : 'K');
//}

bool King::legalities(Player* player, Board* b, Position source, Position destination) {
	if ((source.rowIndex == destination.rowIndex + 1 || source.rowIndex == destination.rowIndex - 1) && (source.columnIndex == destination.columnIndex)) {
		return true;   //straight upper and lower
	}
	else if ((source.columnIndex == destination.columnIndex + 1 || source.columnIndex == destination.columnIndex - 1) && (source.rowIndex == destination.rowIndex)) {
		return true;   //straight right and left
	}
	else if (source.rowIndex - destination.rowIndex == 1 && source.columnIndex - destination.columnIndex == 1) {
		return true;    //upper left
	}
	else if (source.rowIndex - destination.rowIndex == 1 && source.columnIndex - destination.columnIndex == -1) {
		return true;    //upper right
	}
	else if (source.rowIndex - destination.rowIndex == -1 && source.columnIndex - destination.columnIndex == -1) {
		return true;    //lower right
	}
	else if (source.rowIndex - destination.rowIndex == -1 && source.columnIndex - destination.columnIndex == 1) {
		return true;    //lower left
	}
	return false;
}

bool King::findKing() {
	return true;
}