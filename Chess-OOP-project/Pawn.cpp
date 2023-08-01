#include "Pawn.h"
#include "Piece.h"
#include "Board.h"
#include "Queen.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"

using namespace std;

Pawn::Pawn(int r, int c, Color C, Board* b) :Piece(r, c, C, b) {};

void Pawn::draw() {
	cout << ((color == BLACK) ? 'p' : 'P');
}

void Pawn::promotionChoice(Player* player, Board* b, Position source, Position destination) {
	char choice;
	bool flag = true;
	do {
		cout << "\nWhat do you want to make your pawn\n";
		cout << "\nPress Q for Queen\nPress R for Rook\nPress B for Bishop\nPress K for knight\n\Enter choice:";
		cin >> choice;
		if (destination.rowIndex == 0) {
			if (choice == 'q' || choice == 'Q') {
				b->piece[source.rowIndex][source.columnIndex] = new Queen(source.rowIndex, source.columnIndex, BLACK, b);
				flag = false;
			}
			else if (choice == 'r' || choice == 'R') {
				b->piece[source.rowIndex][source.columnIndex] = new Rook(source.rowIndex, source.columnIndex, BLACK, b);
				flag = false;
			}
			else if (choice == 'b' || choice == 'B') {
				b->piece[source.rowIndex][source.columnIndex] = new Bishop(source.rowIndex, source.columnIndex, BLACK, b);
				flag = false;
			}
			else if (choice == 'k' || choice == 'K') {
				b->piece[source.rowIndex][source.columnIndex] = new Knight(source.rowIndex, source.columnIndex, BLACK, b);
				flag = false;
			}
		}
		else {
			if (choice == 'q' || choice == 'Q') {
				b->piece[source.rowIndex][source.columnIndex] = new Queen(source.rowIndex, source.columnIndex, WHITE, b);
				flag = false;
			}
			else if (choice == 'r' || choice == 'R') {
				b->piece[source.rowIndex][source.columnIndex] = new Rook(source.rowIndex, source.columnIndex, WHITE, b);
				flag = false;
			}
			else if (choice == 'b' || choice == 'B') {
				b->piece[source.rowIndex][source.columnIndex] = new Bishop(source.rowIndex, source.columnIndex, WHITE, b);
				flag = false;
			}
			else if (choice == 'k' || choice == 'K') {
				b->piece[source.rowIndex][source.columnIndex] = new Knight(source.rowIndex, source.columnIndex, WHITE, b);
				flag = false;
			}
		}
	} while (flag);
	return;
}

bool Pawn::legalities(Player* player, Board* b, Position source, Position destination) {
	bool promotion = false;
	if (player->getColor() == 0) {
		if (source.rowIndex == 6) {
			promotion = false;
			if (source.rowIndex - destination.rowIndex > 2) {
				return false;
			}
			else if ((source.rowIndex - 1 == destination.rowIndex) && (source.columnIndex == destination.columnIndex)) {
				return (b->getPieceAt(destination.rowIndex, destination.columnIndex) == nullptr);
			}
			else if (source.rowIndex - 2 == destination.rowIndex && source.columnIndex == destination.columnIndex) {
				if ((b->getPieceAt(source.rowIndex - 1, destination.columnIndex) == nullptr) && (b->getPieceAt(source.rowIndex - 2, destination.columnIndex) == nullptr)) {
					return true;
				}
				else {
					return false;
				}
			}
			else if ((source.rowIndex - 1 == destination.rowIndex) && (abs(source.columnIndex - destination.columnIndex) == 1)) {
				return (b->getPieceAt(destination.rowIndex, destination.columnIndex) != nullptr);
			}
		}
		else if (destination.rowIndex == 0) {
			promotion = true;
			if (source.rowIndex - destination.rowIndex != 1) {
				return false;
			}
			else if ((source.rowIndex - 1 == destination.rowIndex) && (source.columnIndex == destination.columnIndex)) {
				if (b->getPieceAt(destination.rowIndex, destination.columnIndex) == nullptr && promotion) {
					promotionChoice(player, b, source, destination);
					return true;
				}
				else if ((source.rowIndex - 1 == destination.rowIndex) && (abs(source.columnIndex - destination.columnIndex) == 1)) {
					if (b->getPieceAt(destination.rowIndex, destination.columnIndex) != nullptr) {
						promotionChoice(player, b, source, destination);
						return true;
					}
				}
			}
		}
		else {
			promotion = false;
			if (source.rowIndex - destination.rowIndex != 1) {
				return false;
			}
			else if ((source.rowIndex - 1 == destination.rowIndex) && (source.columnIndex == destination.columnIndex)) {
				return (b->getPieceAt(destination.rowIndex, destination.columnIndex) == nullptr);
			}
			else if ((source.rowIndex - 1 == destination.rowIndex) && (abs(source.columnIndex - destination.columnIndex) == 1)) {
				return (b->getPieceAt(destination.rowIndex, destination.columnIndex) != nullptr);
			}
		}
	}
	else {
		if (source.rowIndex == 1) {
			promotion = false;
			if (destination.rowIndex - source.rowIndex > 2) {
				return false;
			}
			else if ((source.rowIndex + 1 == destination.rowIndex) && (source.columnIndex == destination.columnIndex)) {
				return (b->getPieceAt(destination.rowIndex, destination.columnIndex) == nullptr);
			}
			else if (source.rowIndex + 2 == destination.rowIndex && source.columnIndex == destination.columnIndex) {
				if ((b->getPieceAt(source.rowIndex + 1, destination.columnIndex) == nullptr) && (b->getPieceAt(source.rowIndex + 2, destination.columnIndex) == nullptr)) {
					return true;
				}
				else {
					return false;
				}
			}
			else if ((source.rowIndex + 1 == destination.rowIndex) && (abs(source.columnIndex - destination.columnIndex) == 1)) {
				return (b->getPieceAt(destination.rowIndex, destination.columnIndex) != nullptr);
			}
		}
		else if (destination.rowIndex == 7) {
			promotion = true;
			if (destination.rowIndex - source.rowIndex != 1) {
				return false;
			}
			else if ((source.rowIndex + 1 == destination.rowIndex) && (source.columnIndex == destination.columnIndex)) {
				if (b->getPieceAt(destination.rowIndex, destination.columnIndex) == nullptr && promotion) {
					promotionChoice(player, b, source, destination);
					return true;
				}
				else if ((source.rowIndex + 1 == destination.rowIndex) && (abs(source.columnIndex - destination.columnIndex) == 1)) {
					if (b->getPieceAt(destination.rowIndex, destination.columnIndex) != nullptr) {
						promotionChoice(player, b, source, destination);
						return true;
					}
				}
			}
		}
		else {
			promotion = false;
			if (destination.rowIndex - source.rowIndex != 1) {
				return false;
			}
			else if ((source.rowIndex + 1 == destination.rowIndex) && (source.columnIndex == destination.columnIndex)) {
				return (b->getPieceAt(destination.rowIndex, destination.columnIndex) == nullptr);
			}
			else if ((source.rowIndex + 1 == destination.rowIndex) && (abs(source.columnIndex - destination.columnIndex) == 1)) {
				return (b->getPieceAt(destination.rowIndex, destination.columnIndex) != nullptr);
			}
		}
	}
	return false;
}