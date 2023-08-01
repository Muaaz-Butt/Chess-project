#include "Chess.h"
#include "Player.h"
#include "Board.h"
#include "Piece.h"
#include "Position.h"

#include <ctime>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

Chess::Chess() {
	player[0] = new Player("Muaaz", BLACK);
	player[1] = new Player("Hammad", WHITE);
	b = new Board();
	srand(time(0));
	turn = rand() % 2;
}

void Chess::displayTurnMessage(Player* player) {
	cout << player->getName() << "'s Turn (" << ((player->getColor() == 0) ? "Black" : "White") << ")\n";
}

void Chess::selectPiece() {
	string choice;
	bool flag = true;
	do {
		cout << "Select Piece: ";
		cin >> choice;
		source.rowIndex = choice[1] - '1';
		if (source.rowIndex > 7 || source.rowIndex < 0) {
			cout << "Invalid Source\n";
		}
		choice[0] = toupper(choice[0]);
		if (choice[0] == 'A') {
			source.columnIndex = 0;
			flag = false;
		}
		else if (choice[0] == 'B') {
			source.columnIndex = 1;
			flag = false;
		}
		else if (choice[0] == 'C') {
			source.columnIndex = 2;
			flag = false;
		}
		else if (choice[0] == 'D') {
			source.columnIndex = 3;
			flag = false;
		}
		else if (choice[0] == 'E') {
			source.columnIndex = 4;
			flag = false;
		}
		else if (choice[0] == 'F') {
			source.columnIndex = 5;
			flag = false;
		}
		else if (choice[0] == 'G') {
			source.columnIndex = 6;
			flag = false;
		}
		else if (choice[0] == 'H') {
			source.columnIndex = 7;
			flag = false;
		}
		else {
			cout << "Invalid source\n";
		}
	} while (flag);
}

void Chess::selectDestination() {
	string choice;
	do {
		cout << "Select Destination: ";
		cin >> choice;
		destination.rowIndex = choice[1] - '1';
		if (source.rowIndex > 7 || source.rowIndex < 0) {
			cout << "Invalid Destination\n";
		}
		choice[0] = toupper(choice[0]);
		if (choice[0] == 'A') {
			destination.columnIndex = 0;
			return;
		}
		else if (choice[0] == 'B') {
			destination.columnIndex = 1;
			return;
		}
		else if (choice[0] == 'C') {
			destination.columnIndex = 2;
			return;
		}
		else if (choice[0] == 'D') {
			destination.columnIndex = 3;
			return;
		}
		else if (choice[0] == 'E') {
			destination.columnIndex = 4;
			return;
		}
		else if (choice[0] == 'F') {
			destination.columnIndex = 5;
			return;
		}
		else if (choice[0] == 'G') {
			destination.columnIndex = 6;
			return;
		}
		else if (choice[0] == 'H') {
			destination.columnIndex = 7;
			return;
		}
		else {
			cout << "Invalid Destination\n";
		}
	} while (true);
}

bool Chess::validSourceSelection(Player* player, int r, int c) {
	if (r < 0 || r >= 8 || c < 0 || c >= 8) {
		return false;
	}
	Piece* p = b->getPieceAt(r, c);
	return (p != nullptr) && (p->getColor() == player->getColor());
}

bool Chess::validDestinationSelection(Player* player, int r, int c) {
	if (r < 0 || r >= 8 || c < 0 || c >= 8) {
		return false;
	}
	Piece* p = b->getPieceAt(r, c);
	return (p == nullptr) || (p->getColor() != player->getColor());
}

void Chess::play() {
	Piece* piece;
	bool check1 = false;
	bool isKingChecked = false;
	bool** map = nullptr;
	map = new bool* [8];
	for (int i = 0; i < 8; i++)
		map[i] = new bool[8];
	while (true) {
		b->displayBoard();
		displayTurnMessage(player[turn]);
		do {
			do {
				do {
					selectPiece();
				} while (!validSourceSelection(player[turn], source.rowIndex, source.columnIndex));
				piece = b->getPieceAt(source.rowIndex, source.columnIndex);
				if (b->getPieceAt(source.rowIndex, source.columnIndex)->findKing()) {
					isKingChecked = true;
				}
				else {
					isKingChecked = false;
				}
				if (selfCheck(piece, source, destination, map, isKingChecked)) {
					cout << "\n\n-----------King is in check-----------\n\n";
					check1 = true;
				}
				else {
					check1 = false;
				}
				do {
					do {
						selectDestination();
					} while (selfCheck(piece, source, destination, map, isKingChecked));
				} while (!validDestinationSelection(player[turn], destination.rowIndex, destination.columnIndex));
			} while (selfCheck(piece, source, destination, map, isKingChecked));
			piece = b->getPieceAt(source.rowIndex, source.columnIndex);
		} while (!(*piece).legalities(player[turn], b, source, destination));
		b->move(source, destination);
		if (check(piece, b, player[turn], source, destination)) {
			cout << "\n\n------------King is in check------------\n\n";
		}
		if (!isCheckMate(piece, b, player[turn], source, destination,map)) {
			system("cls");
			if (player[turn] == 0) {
				cout << "\n\n---------------BLACK WON----------------\n\n";
			}
			else {
				cout << "\n\n---------------WHITE WON----------------\n\n";
			}
			exit(0);
		}
		turnChange();
	}
}

void Chess::turnChange() {
	if (turn == 0) {
		turn = 1;
	}
	else {
		turn = 0;
	}
}

void Chess::deepCopyBoard(Board*& boardCopy) {
	boardCopy = new Board[8];
	for (int rows = 0; rows < 8; rows++) {
		for (int columns = 0; columns < 8; columns++) {
			boardCopy->piece[rows][columns] = b->getPieceAt(rows, columns);
		}
	}
}

Position Chess::kingPosition(Board* board, Player* player) {
	Position positionOfKing;
	for (int row = 0; row < 8; row++) {
		for (int column = 0; column < 8; column++) {
			positionOfKing.rowIndex = row;
			positionOfKing.columnIndex = column;
			if (board->getPieceAt(row, column) != nullptr) {
				if (b->getPieceAt(row, column)->findKing() == true) {
					if (validSourceSelection(this->player[turn], row, column)) {
						return positionOfKing;
					}
				}
			}
		}
	}
}

bool Chess::check(Piece* piece, Board* board, Player* player, Position source, Position destination) {
	Position currentPosition;
	turnChange();
	Position destinationPosition = kingPosition(b, this->player[turn]);
	turnChange();
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			currentPosition.rowIndex = i;
			currentPosition.columnIndex = j;
			if (validSourceSelection(this->player[turn], i, j)) {
				if (board->getPieceAt(i, j)->legalities(this->player[turn], board, currentPosition, destinationPosition)) {
					return true;
				}
			}
		}
	}
	return false;
}

void Chess::moveForSelfCheck(Board*& boardCopy, Position source, Position destination) {
	boardCopy->piece[destination.rowIndex][destination.columnIndex] = boardCopy->piece[source.rowIndex][source.columnIndex];
	boardCopy->piece[source.rowIndex][source.columnIndex] = nullptr;
}

bool Chess::selfCheck(Piece* piece, Position source, Position destination, bool** arr, bool isKingChecked) {
	Board* boardCopy;
	Position sourceCopy;
	deepCopyBoard(boardCopy);
	moveForSelfCheck(boardCopy, source, destination);
	turnChange();
	bool ch = check(piece, boardCopy, this->player[turn], source, destination);
	if (isKingChecked)
	{
		for (int r = 0; r < 8; r++)
		{
			for (int c = 0; c < 8; c++)
			{
				if (arr[r][c] == true) {
					destination.rowIndex = r;
					destination.columnIndex = c;
					for (int i = 0; i < 8; i++)
					{
						for (int j = 0; j < 8; j++)
						{
							sourceCopy.columnIndex = j;
							sourceCopy.rowIndex = i;
							if (validSourceSelection(this->player[turn], i, j))
							{
								if ((boardCopy->getPieceAt(i, j)->legalities(this->player[turn], boardCopy, sourceCopy, destination)))
								{
									turnChange();
									return true;
								}
							}
						}
					}
				}
			}
		}
		turnChange();
		return false;
	}
	turnChange();
	return ch;
}

bool Chess::isCheckMate(Piece* piece, Board* b, Player* player, Position sourrce, Position destination, bool** arr) {
	Position sourceCopy;
	Position destinationCopy;
	bool isKingChecked;
	for (int r = 0; r < 8; r++) {
		for (int c = 0; c < 8; c++) {
			sourceCopy.rowIndex = r;
			sourceCopy.columnIndex = c;
			if (validSourceSelection(this->player[turn],sourceCopy.rowIndex,sourceCopy.columnIndex)) {
				for (int i = 0; i < 8; i++) {
					for (int j = 0; j < 8; j++) {
						destinationCopy.rowIndex = i;
						destinationCopy.columnIndex = j;
						if ((validDestinationSelection(this->player[turn], destinationCopy.rowIndex, destinationCopy.columnIndex)) && (this->b->getPieceAt(sourceCopy.rowIndex, sourceCopy.columnIndex)->legalities(this->player[turn], this->b, sourceCopy, destinationCopy))) {
							if (this->b->getPieceAt(sourceCopy.rowIndex, sourceCopy.columnIndex)->findKing()) {
								isKingChecked = true;
							}
							else {
								isKingChecked = false;
							}
							if (!selfCheck(piece, sourceCopy, destinationCopy, arr, isKingChecked)) {
								return true;
							}
						}
					}
				}
			}
		}
	}
	return false;
}
