#include <iostream>
#include <math.h>

#include "Board.h"
#include "Piece.h"

using  namespace std;

bool Piece::isHorizontalPathClear(Player* player, Board* b, Position source, Position destination) {
	if (source.rowIndex != destination.rowIndex) {
		return false;
	}
	int start = min(source.columnIndex, destination.columnIndex);
	int end = max(source.columnIndex, destination.columnIndex);
	for (int i = start + 1; i < end; i++) {
		if (b->getPieceAt(source.rowIndex, i) != nullptr) {
			return false;
		}
	}
	return true;
}

bool Piece::isVerticalPathClear(Player* player, Board* b, Position source, Position destination) {
	if (source.columnIndex != destination.columnIndex) {
		return false;
	}
	int start = min(source.rowIndex, destination.rowIndex);
	int end = max(source.rowIndex, destination.rowIndex);
	for (int i = start + 1; i < end; i++) {
		if (b->getPieceAt(i,source.columnIndex) != nullptr) {
			return false;
		}
	}
	return true;
}

bool Piece::isDiagonal(Position source, Position destination) {
	return (abs(source.rowIndex - destination.rowIndex) == abs(source.columnIndex - destination.columnIndex));
}

bool Piece::isDiagonalLeftToRightPathClear(Player* player, Board* b, Position source, Position destination) {
	int n = abs(source.rowIndex - destination.rowIndex);
	int startingRow = min(source.rowIndex, destination.rowIndex);
	int startingColumn = min(source.columnIndex, destination.columnIndex);
	if ((startingRow == source.rowIndex && startingColumn == source.columnIndex) || (startingRow == destination.rowIndex && startingColumn == destination.columnIndex)) {
		for (int i = 1; i < n; i++) {
			if (b->getPieceAt(startingRow + i, startingColumn + i) != nullptr) {
				return false;
			}
		}
		return true;
	}
	return false;
}

bool Piece::isDiagonalRightToLeftPathClear(Player* player, Board* b, Position source, Position destination) {
	int n = abs(source.rowIndex - destination.rowIndex);
	int startingRow = max(source.rowIndex, destination.rowIndex);
	int startingColumn = min(source.columnIndex, destination.columnIndex);
	if ((startingRow == source.rowIndex && startingColumn == source.columnIndex) || (startingRow == destination.rowIndex && startingColumn == destination.columnIndex)) {
		for (int i = 1; i < n; i++) {
			if (b->getPieceAt(startingColumn + i, startingRow - i) != nullptr) {
				return false;
			}
		}
		return true;
	}
	return false;
}

Piece::Piece(int r, int c, Color C,Board* b) {
	this->ri = r;
	this->ci = c;
	this->color = C;
	this->board = b;
}

void Piece::move(int r, int c) {
	this->ri = r;
	this->ci = c;
}

Color Piece::getColor() {
	return color;
}

bool Piece::legalities(Player* player, Board* b, Position source, Position destinantion) {
	return true;
}

bool Piece::findKing() {
	return false;
}