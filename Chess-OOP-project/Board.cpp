#include "Board.h"
#include "Header.h"
#include "Piece.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"

#include <iostream>

using namespace std;

Board::Board() {
	piece = new Piece **[8];
	for (int row = 0; row < 8; row++) {
		piece[row] = new Piece * [8];
		for (int column = 0; column < 8; column++) {
			if (row == 1) {
				piece[row][column] = new Pawn(row, column, WHITE, this);
			}
			else if (row == 6) {
				piece[row][column] = new Pawn(row, column, BLACK, this);
			}
			else if ((row == 0 && column == 0) || (row == 0 && column == 7)) {
				piece[row][column] = new Rook(row, column, WHITE, this);
			}
			else if ((row == 7 && column == 0) || (row == 7 && column == 7)) {
				piece[row][column] = new Rook(row, column, BLACK, this);
			}
			else if ((row == 0 && column == 1) || (row == 0 && column == 6)) {
				piece[row][column] = new Knight(row, column, WHITE, this);
			}
			else if ((row == 7 && column == 1) || (row == 7 && column == 6)) {
				piece[row][column] = new Knight(row, column, BLACK, this);
			}
			else if ((row == 0 && column == 2) || (row == 0 && column == 5)) {
				piece[row][column] = new Bishop(row, column, WHITE, this);
			}
			else if ((row == 7 && column == 2) || (row == 7 && column == 5)) {
				piece[row][column] = new Bishop(row, column, BLACK, this);
			}
			else if (row == 0 && column == 3) {
				piece[row][column] = new Queen(row, column, WHITE, this);
			}
			else if (row == 7 && column == 3) {
				piece[row][column] = new Queen(row, column, BLACK, this);
			}
			else if (row == 0 && column == 4) {
				piece[row][column] = new King(row, column, WHITE, this);
			}
			else if (row == 7 && column == 4) {
				piece[row][column] = new King(row, column, BLACK, this);
			}
			else {
				piece[row][column] = nullptr;
			}
		}
	}
}


void Board::displayBoard() {
	system("cls");
	cout << "    A   B   C   D   E   F   G   H\n";
	cout << "    -----------------------------\n\n";
	for (int r = 0; r < 8; r++) {
		cout << r + 1 << "|  ";
		for (int c = 0; c < 8; c++) {
			if (piece[r][c] == nullptr) {
				cout << ".   ";
			}
			else {
				piece[r][c]->draw();
				cout << "   ";
			}
		}
		cout << "\n";
	}
	cout << "\n";
}

Piece* Board::getPieceAt(int r, int c) {
	return piece[r][c];
}

void Board::move(Position source, Position destination) {
	Piece* temp = piece[source.rowIndex][source.columnIndex];
	piece[destination.rowIndex][destination.columnIndex] = temp;
	piece[source.rowIndex][source.columnIndex] = nullptr;
}