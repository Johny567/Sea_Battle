// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <windows.h>

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
COORD position;
#define CW SetConsoleCursorPosition(hConsole, position);

struct Ship {
	int Y; // 1-10
	int X; // 
	int deckNumber; //
	char position; // 
};
void BattleFieldTable();
void Position1DECK(Ship*, char(*)[12]);
void Position2DECK(Ship*, char(*)[12]);
void Position3DECK(Ship*, char(*)[12]);
void Position4DECK(Ship*, char(*)[12]);
void AutoPosition4DECK(Ship*, char(*)[12]);
void AutoPosition3DECK(Ship*, char(*)[12]);
void AutoPosition2DECK(Ship*, char(*)[12]);
void AutoPosition1DECK(Ship*, char(*)[12]);
void Position1DECKBOT(Ship*, char(*)[12]);
void Position2DECKBOT(Ship*, char(*)[12]);
void Position3DECKBOT(Ship*, char(*)[12]);
void Position4DECKBOT(Ship*, char(*)[12]);
void MovePlayer(int*, int*, char(*)[12]);
void MoveBOT(int*, int*, char(*)[12]);
void TEST(char(*)[12]);


int main() {
	srand(time(0));
	char placementOnField;
	bool GameOver = false;
	int X, Y;
	int*ptrX = &X;
	int*ptrY = &Y;
	BattleFieldTable();

	Ship singleDeck[4];
	Ship doubleDeck[3];
	Ship threeDeck[2];
	Ship fourDeck[1];
	for (int i = 0; i < 4; i++)
		singleDeck[i].deckNumber = 1;
	for (int i = 0; i < 3; i++)
		doubleDeck[i].deckNumber = 2;
	for (int i = 0; i < 2; i++)
		threeDeck[i].deckNumber = 3;
	for (int i = 0; i < 1; i++)
		fourDeck[i].deckNumber = 4;
	Ship*single = singleDeck;
	Ship*doub = doubleDeck;
	Ship*three = threeDeck;
	Ship*four = fourDeck;

	Ship singleDeckBOT[4];
	Ship doubleDeckBOT[3];
	Ship threeDeckBOT[2];
	Ship fourDeckBOT[1];
	for (int i = 0; i < 4; i++)
		singleDeckBOT[i].deckNumber = 1;
	for (int i = 0; i < 3; i++)
		doubleDeckBOT[i].deckNumber = 2;
	for (int i = 0; i < 2; i++)
		threeDeckBOT[i].deckNumber = 3;
	for (int i = 0; i < 1; i++)
		fourDeckBOT[i].deckNumber = 4;
	Ship*singleBOT = singleDeckBOT;
	Ship*doubBOT = doubleDeckBOT;
	Ship*threeBOT = threeDeckBOT;
	Ship*fourBOT = fourDeckBOT;

	char Battlefield[12][12];
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++) {
			Battlefield[i][j] = '0';
		}
	}
	char(*ptrField)[12];
	ptrField = Battlefield;
	char BattlefieldBOT[12][12];
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++) {
			BattlefieldBOT[i][j] = '0';
		}
	}
	char(*ptrFieldBOT)[12];
	ptrFieldBOT = BattlefieldBOT;
	position.X = 31;
	position.Y = 3;
	CW;
	cout << "'A' - AUTO";
	position.X = 31;
	position.Y = 4;
	CW;
	cout << "'M' - MANUAL";
	do {
		position.X = 31;
		position.Y = 5;
		CW;
		cin >> placementOnField;
	} while (!(placementOnField == 'a') && !(placementOnField == 'm') && !(placementOnField == 'A') && !(placementOnField == 'M'));

	position.X = 31;
	position.Y = 3;
	CW;
	cout << "\t\t\t";
	position.X = 31;
	position.Y = 4;
	CW;
	cout << "\t\t\t";
	if (placementOnField == 'm') {
		Position4DECK(four, ptrField);
		Position3DECK(three, ptrField);
		Position2DECK(doub, ptrField);
		Position1DECK(single, ptrField);
	}
	else {
		AutoPosition4DECK(four, ptrField);
		AutoPosition3DECK(three, ptrField);
		AutoPosition2DECK(doub, ptrField);
		AutoPosition1DECK(single, ptrField);
		TEST(ptrField);
	}

	Position4DECKBOT(fourBOT, ptrFieldBOT);
	Position3DECKBOT(threeBOT, ptrFieldBOT);
	Position2DECKBOT(doubBOT, ptrFieldBOT);
	Position1DECKBOT(singleBOT, ptrFieldBOT);
	do {
		MovePlayer(ptrY, ptrX, ptrFieldBOT);
		for (int i = 1; i < 12; i++) {
			for (int j = 1; j < 12; j++) {
				if (ptrField[i][j] == '1' || ptrFieldBOT[i][j] == '1') {
					break;
				}
				else {
					GameOver = true;
				}
			}
		}
		MoveBOT(ptrY, ptrX, ptrField);
		TEST(ptrField);
	} while (GameOver);
	return 0;
}

void BattleFieldTable() {
	system("color 3");
	cout << "\n\n\n";
	cout << "\t 1 2 3 4 5 6 7 8 9 10 \t\t\t 1 2 3 4 5 6 7 8 9 10";
	for (int j = 0; j < 10; j++) {
		cout << "\n\t---------------------\t\t\t---------------------\t\n\t";
		for (int i = 0; i <= 10; i++) {
			cout << "|";
			cout << " ";
		}
		cout << "\t\t\t";
		for (int i = 0; i <= 10; i++) {
			cout << "|";
			cout << " ";
		}
	}
	cout << "\n\t---------------------\t\t\t---------------------\t\n\t";
}
void Position1DECK(Ship*single, char(*ptrField)[12]) {
	position.X = 31;   // ENTER SINGLE-DECK SHIPS
	position.Y = 2;
	CW;
	cout << "SINGLE-deck:";
	for (int i = 0; i < 4; i++) {
		position.X = 31;
		position.Y = 3;
		CW;
		cout << "'V'-vertical";
		position.X = 31;
		position.Y = 4;
		CW;
		cout << "'H'-horizontal";
		position.X = 31;
		position.Y = 5;
		CW;
		cout << "   ";
		position.X = 31;
		position.Y = 6;
		CW;
		cout << "[Y]  [X] coords";
		do {
			position.X = 34;
			position.Y = 7;
			CW;
			cin >> single[i].Y;
			position.X = 34;
			position.Y = 8;
			CW;
			cin >> single[i].X;
		} while (!(single[i].Y <= 11 && single[i].X <= 11) || ptrField[single[i].Y][single[i].X] != '0');
		ptrField[single[i].Y][single[i].X] = '1';
		ptrField[single[i].Y][single[i].X - 1] = '2'; //left aura
		ptrField[single[i].Y][single[i].X + 1] = '2'; //right aura
		for (int k = -1; k < 2; k++) {
			ptrField[single[i].Y - 1][single[i].X + k] = '2';  // up aura
		}
		for (int k = -1; k < 2; k++) {
			ptrField[single[i].Y + single->deckNumber][single[i].X + k] = '2';  // down aura
		}
		position.Y = single[i].Y * 2 + 3;
		position.X = single[i].X * 2 + 7;
		CW;
		cout << 'X';
		position.X = 34;
		position.Y = 7;
		CW;
		cout << "   ";
		position.X = 34;
		position.Y = 8;
		CW;
		cout << "   ";

	}
}
void Position2DECK(Ship*doub, char(*ptrField)[12]) {
	position.X = 31;   // ENTER DOUBLE-DECK SHIPS
	position.Y = 2;
	CW;
	cout << "DOUBLE-deck:";
	for (int i = 0; i < 3; i++) {
		position.X = 31;
		position.Y = 3;
		CW;
		cout << "'V'-vertical";
		position.X = 31;
		position.Y = 4;
		CW;
		cout << "'H'-horizontal";
		position.X = 31;
		position.Y = 5;
		CW;
		cout << "   ";
		do {
			position.X = 31;
			position.Y = 5;
			CW;
			cin >> doub[i].position;
		} while (!(doub[i].position == 'v') && !(doub[i].position == 'V') && !(doub[i].position == 'H') && !(doub[i].position == 'h'));
		position.X = 31;
		position.Y = 6;
		CW;
		cout << "[Y]  [X] coords";
		if (doub[i].position == 'V' || doub[i].position == 'v') {
			do {
				position.X = 34;
				position.Y = 7;
				CW;
				cin >> doub[i].Y;
				position.X = 34;
				position.Y = 8;
				CW;
				cin >> doub[i].X;
			} while (!(doub[i].Y + 2 <= 11) || ptrField[doub[i].Y][doub[i].X - 1] != '0' || ptrField[doub[i].Y + 1][doub[i].X] != '0');
		}
		else if (doub[i].position == 'H' || doub[i].position == 'h') {
			do {
				position.X = 34;
				position.Y = 7;
				CW;
				cin >> doub[i].Y;
				position.X = 34;
				position.Y = 8;
				CW;
				cin >> doub[i].X;
			} while (!(doub[i].X + 2 <= 11) || ptrField[doub[i].Y][doub[i].X - 1] != '0' || ptrField[doub[i].Y][doub[i].X + 1] != '0');
		}
		if (doub[i].position == 'V' || doub[i].position == 'v') {
			for (int j = 0; j < doub->deckNumber; j++) {
				ptrField[doub[i].Y + j][doub[i].X] = '1';
				ptrField[doub[i].Y + j][doub[i].X - 1] = '2'; //left aura
				ptrField[doub[i].Y + j][doub[i].X + 1] = '2'; //right aura
				if (j == 0) {
					for (int k = -1; k < 2; k++) {
						ptrField[doub[i].Y - 1][doub[i].X + k] = '2';  // up aura
					}
				}
				if (j == 1) {
					for (int k = -1; k < 2; k++) {
						ptrField[doub[i].Y + doub->deckNumber][doub[i].X + k] = '2';  // down aura

					}
				}
				position.Y = (doub[i].Y + j) * 2 + 3;
				position.X = doub[i].X * 2 + 7;
				CW;
				cout << 'X';
			}
		}
		else if (doub[i].position == 'H' || doub[i].position == 'h') {
			for (int j = 0; j < doub->deckNumber; j++) {
				ptrField[doub[i].Y][doub[i].X + j] = '1';
				ptrField[doub[i].Y - 1][doub[i].X + j] = '2';
				ptrField[doub[i].Y + 1][doub[i].X + j] = '2';
				if (j == 0) {
					for (int k = -1; k < 2; k++) {
						ptrField[doub[i].Y + k][doub[i].X - 1] = '2';
					}
				}
				if (j == 1) {
					for (int k = -1; k < 2; k++) {
						ptrField[doub[i].Y + k][doub[i].X + doub[i].deckNumber] = '2';
					}
				}
				position.Y = doub[i].Y * 2 + 3;
				position.X = (doub[i].X + j) * 2 + 7;
				CW;
				cout << 'X';
			}
		}
		position.X = 34;
		position.Y = 7;
		CW;
		cout << "   ";
		position.X = 34;
		position.Y = 8;
		CW;
		cout << "   ";

	}
}
void Position3DECK(Ship*three, char(*ptrField)[12]) {
	position.X = 31;   // ENTER THREE-DECK SHIPS
	position.Y = 2;
	CW;
	cout << "THREE-deck:";
	for (int i = 0; i < 2; i++) {
		position.X = 31;
		position.Y = 3;
		CW;
		cout << "'V'-vertical";
		position.X = 31;
		position.Y = 4;
		CW;
		cout << "'H'-horizontal";
		position.X = 31;
		position.Y = 5;
		CW;
		cout << "   ";
		do {
			position.X = 31;
			position.Y = 5;
			CW;
			cin >> three[i].position;
		} while (!(three[i].position == 'v') && !(three[i].position == 'V') && !(three[i].position == 'H') && !(three[i].position == 'h'));
		position.X = 31;
		position.Y = 6;
		CW;
		cout << "[Y]  [X] coords";
		if (three[i].position == 'V' || three[i].position == 'v') {
			do {
				position.X = 34;
				position.Y = 7;
				CW;
				cin >> three[i].Y;
				position.X = 34;
				position.Y = 8;
				CW;
				cin >> three[i].X;
			} while (!(three[i].Y + three->deckNumber <= 11) || ptrField[three[i].Y][three[i].X] != '0' || ptrField[three[i].Y + 1][three[i].X] != '0' || ptrField[three[i].Y + 2][three[i].X] != '0');
		}
		else if (three[i].position == 'H' || three[i].position == 'h') {
			do {
				position.X = 34;
				position.Y = 7;
				CW;
				cin >> three[i].Y;
				position.X = 34;
				position.Y = 8;
				CW;
				cin >> three[i].X;
			} while (!(three[i].X + 3 <= 11) || ptrField[three[i].Y][three[i].X] != '0' || ptrField[three[i].Y][three[i].X + 1] != '0' || ptrField[three[i].Y][three[i].X + 2] != '0');
		}
		if (three[i].position == 'V' || three[i].position == 'v') {
			for (int j = 0; j < 3; j++) {
				ptrField[three[i].Y + j][three[i].X] = '1';
				ptrField[three[i].Y + j][three[i].X - 1] = '2'; //left aura
				ptrField[three[i].Y + j][three[i].X + 1] = '2'; //right aura
				if (j == 0) {
					for (int k = -1; k < 2; k++) {
						ptrField[three[i].Y - 1][three[i].X + k] = '2';  // up aura
					}
				}
				if (j == 2) {
					for (int k = -1; k < 2; k++) {
						ptrField[three[i].Y + three->deckNumber][three[i].X + k] = '2';  // down aura

					}
				}
				position.Y = (three[i].Y + j) * 2 + 3;
				position.X = three[i].X * 2 + 7;
				CW;
				cout << 'X';
			}
		}
		else if (three[i].position == 'H' || three[i].position == 'h') {
			for (int j = 0; j < 3; j++) {
				ptrField[three[i].Y][three[i].X + j] = '1';
				ptrField[three[i].Y - 1][three[i].X + j] = '2';
				ptrField[three[i].Y + 1][three[i].X + j] = '2';
				if (j == 0) {
					for (int k = -1; k < 2; k++) {
						ptrField[three[i].Y + k][three[i].X - 1] = '2';
					}
				}
				if (j == 2) {
					for (int k = -1; k < 2; k++) {
						ptrField[three[i].Y + k][three[i].X + three[i].deckNumber] = '2';
					}
				}
				position.Y = three[i].Y * 2 + 3;
				position.X = (three[i].X + j) * 2 + 7;
				CW;
				cout << 'X';
			}
		}
		position.X = 34;
		position.Y = 7;
		CW;
		cout << "   ";
		position.X = 34;
		position.Y = 8;
		CW;
		cout << "   ";
	}
}
void Position4DECK(Ship*four, char(*ptrField)[12]) {
	position.X = 31;   // ENTER FOUR-DECK SHIP
	position.Y = 2;
	CW;
	cout << "FOUR-deck:";
	position.X = 31;
	position.Y = 3;
	CW;
	cout << "'V'-vertical";
	position.X = 31;
	position.Y = 4;
	CW;
	cout << "'H'-horizontal";
	do {
		position.X = 31;
		position.Y = 5;
		CW;
		cout << "   ";
		position.X = 31;
		position.Y = 5;
		CW;
		cin >> four->position;
	} while (!(four->position == 'v') && !(four->position == 'V') && !(four->position == 'H') && !(four->position == 'h'));
	position.X = 31;
	position.Y = 6;
	CW;
	cout << "[Y]  [X] coords";
	if (four->position == 'V' || four->position == 'v') {
		do {
			position.X = 34;
			position.Y = 7;
			CW;
			cin >> four->Y;
			position.X = 34;
			position.Y = 8;
			CW;
			cin >> four->X;
		} while (!(four->Y + 4 <= 11));
	}
	else if (four->position == 'H' || four->position == 'h') {
		do {
			position.X = 34;
			position.Y = 7;
			CW;
			cin >> four->Y;
			position.X = 34;
			position.Y = 8;
			CW;
			cin >> four->X;
		} while (!(four->X + 4 <= 11));
	}
	if (four->position == 'V' || four->position == 'v') {
		for (int j = 0; j < four->deckNumber; j++) {
			ptrField[four->Y + j][four->X] = '1';

			ptrField[four->Y + j][four->X - 1] = '2'; //left aura
			ptrField[four->Y + j][four->X + 1] = '2'; //right aura
			if (j == 0) {
				for (int k = -1; k < 2; k++) {
					ptrField[four->Y - 1][four->X + k] = '2';  // up aura
				}
			}
			if (j == 3) {
				for (int k = -1; k < 2; k++) {
					ptrField[four->Y + four->deckNumber][four->X + k] = '2';  // down aura

				}
			}
			position.Y = (four->Y + j) * 2 + 3;
			position.X = four->X * 2 + 7;
			CW;
			cout << 'X';
		}
	}
	else if (four->position == 'H' || four->position == 'h') {
		for (int j = 0; j < 4; j++) {
			ptrField[four->Y][four->X + j] = '1';

			ptrField[four->Y - 1][four->X + j] = '2';
			ptrField[four->Y + 1][four->X + j] = '2';
			if (j == 0) {
				for (int k = -1; k < 2; k++) {
					ptrField[four->Y + k][four->X - 1] = '2';
				}
			}
			if (j == 3) {
				for (int k = -1; k < 2; k++) {
					ptrField[four->Y + k][four->X + 4] = '2';
				}
			}
			position.Y = four->Y * 2 + 3;
			position.X = (four->X + j) * 2 + 7;
			CW;
			cout << 'X';
		}
	}
	position.X = 34;
	position.Y = 7;
	CW;
	cout << "   ";
	position.X = 34;
	position.Y = 8;
	CW;
	cout << "   ";
}
void AutoPosition4DECK(Ship*four, char(*ptrField)[12]) {
	int shipPosition = rand() % 2;
	if (shipPosition == 0) {
		four->position = '0';
	}
	else {
		four->position = '1';
	}
	if (four->position == '0') {
		do {
			four->Y = rand() % 10 + 1;
			four->X = rand() % 10 + 1;
		} while (!(four->Y + four->deckNumber <= 11));
	}
	else if (four->position == '1') {
		do {
			four->Y = rand() % 9 + 1;
			four->X = rand() % 9 + 1;
		} while (!(four->X + 4 <= 11));
	}
	if (four->position == '0') {
		for (int j = 0; j < four->deckNumber; j++) {
			ptrField[four->Y + j][four->X] = '1';
			ptrField[four->Y + j][four->X - 1] = '2'; //left aura
			ptrField[four->Y + j][four->X + 1] = '2'; //right aura
			if (j == 0) {
				for (int k = -1; k < 2; k++) {
					ptrField[four->Y - 1][four->X + k] = '2';  // up aura
				}
			}
			if (j == 3) {
				for (int k = -1; k < 2; k++) {
					ptrField[four->Y + four->deckNumber][four->X + k] = '2';  // down aura

				}
			}
			position.Y = (four->Y + j) * 2 + 3;
			position.X = four->X * 2 + 7;
			CW;
			cout << 'X';
		}
	}
	else if (four->position == '1') {
		for (int j = 0; j < 4; j++) {
			ptrField[four->Y][four->X + j] = '1';

			ptrField[four->Y - 1][four->X + j] = '2';
			ptrField[four->Y + 1][four->X + j] = '2';
			if (j == 0) {
				for (int k = -1; k < 2; k++) {
					ptrField[four->Y + k][four->X - 1] = '2';
				}
			}
			if (j == 3) {
				for (int k = -1; k < 2; k++) {
					ptrField[four->Y + k][four->X + 4] = '2';
				}
			}
			position.Y = four->Y * 2 + 3;
			position.X = (four->X + j) * 2 + 7;
			CW;
			cout << 'X';
		}
	}


}
void AutoPosition3DECK(Ship*three, char(*ptrField)[12]) {
	for (int i = 0; i < 2; i++) {
		int shipPosition = rand() % 2;
		if (shipPosition == 0) {
			three[i].position = '0';
		}
		else {
			three[i].position = '1';
		}
		if (three[i].position == '0') {
			do {
				three[i].Y = rand() % 10 + 1;
				three[i].X = rand() % 10 + 1;
			} while (!(three[i].Y + three->deckNumber <= 11) || ptrField[three[i].Y][three[i].X] != '0' || ptrField[three[i].Y + 1][three[i].X] != '0' || ptrField[three[i].Y + 2][three[i].X] != '0');
		}
		else if (three[i].position == '1') {
			do {
				three[i].Y = rand() % 10 + 1;
				three[i].X = rand() % 10 + 1;
			} while (!(three[i].X + 3 <= 11) || ptrField[three[i].Y][three[i].X] != '0' || ptrField[three[i].Y][three[i].X + 1] != '0' || ptrField[three[i].Y][three[i].X + 2] != '0');
		}
		if (three[i].position == '0') {
			for (int j = 0; j < 3; j++) {
				ptrField[three[i].Y + j][three[i].X] = '1';
				ptrField[three[i].Y + j][three[i].X - 1] = '2'; //left aura
				ptrField[three[i].Y + j][three[i].X + 1] = '2'; //right aura
				if (j == 0) {
					for (int k = -1; k < 2; k++) {
						ptrField[three[i].Y - 1][three[i].X + k] = '2';  // up aura
					}
				}
				if (j == 2) {
					for (int k = -1; k < 2; k++) {
						ptrField[three[i].Y + three->deckNumber][three[i].X + k] = '2';  // down aura

					}
				}
				position.Y = (three[i].Y + j) * 2 + 3;
				position.X = three[i].X * 2 + 7;
				CW;
				cout << 'X';
			}
		}
		else if (three[i].position == '1') {
			for (int j = 0; j < 3; j++) {
				ptrField[three[i].Y][three[i].X + j] = '1';
				ptrField[three[i].Y - 1][three[i].X + j] = '2';
				ptrField[three[i].Y + 1][three[i].X + j] = '2';
				if (j == 0) {
					for (int k = -1; k < 2; k++) {
						ptrField[three[i].Y + k][three[i].X - 1] = '2';
					}
				}
				if (j == 2) {
					for (int k = -1; k < 2; k++) {
						ptrField[three[i].Y + k][three[i].X + three[i].deckNumber] = '2';
					}
				}
				position.Y = three[i].Y * 2 + 3;
				position.X = (three[i].X + j) * 2 + 7;
				CW;
				cout << 'X';
			}
		}
		position.X = 34;
		position.Y = 7;
		CW;
		cout << "   ";
		position.X = 34;
		position.Y = 8;
		CW;
		cout << "   ";
	}
}
void AutoPosition2DECK(Ship*doub, char(*ptrField)[12]) {

	for (int i = 0; i < 3; i++) {
		int shipPosition = rand() % 2;
		if (shipPosition == 0) {
			doub[i].position = '0';
		}
		else {
			doub[i].position = '1';
		}
		if (doub[i].position == '0') {
			do {
				doub[i].Y = rand() % 10 + 1;
				doub[i].X = rand() % 10 + 1;
			} while (!(doub[i].Y + 2 <= 11) || ptrField[doub[i].Y][doub[i].X - 1] != '0' || ptrField[doub[i].Y + 1][doub[i].X] != '0');
		}
		else if (doub[i].position == '1') {
			do {
				doub[i].Y = rand() % 10 + 1;
				doub[i].X = rand() % 10 + 1;
			} while (!(doub[i].X + 2 <= 11) || ptrField[doub[i].Y][doub[i].X - 1] != '0' || ptrField[doub[i].Y][doub[i].X + 1] != '0');
		}
		if (doub[i].position == '0') {
			for (int j = 0; j < doub->deckNumber; j++) {
				ptrField[doub[i].Y + j][doub[i].X] = '1';
				ptrField[doub[i].Y + j][doub[i].X - 1] = '2'; //left aura
				ptrField[doub[i].Y + j][doub[i].X + 1] = '2'; //right aura
				if (j == 0) {
					for (int k = -1; k < 2; k++) {
						ptrField[doub[i].Y - 1][doub[i].X + k] = '2';  // up aura
					}
				}
				if (j == 1) {
					for (int k = -1; k < 2; k++) {
						ptrField[doub[i].Y + doub->deckNumber][doub[i].X + k] = '2';  // down aura

					}
				}
				position.Y = (doub[i].Y + j) * 2 + 3;
				position.X = doub[i].X * 2 + 7;
				CW;
				cout << 'X';
			}
		}
		else if (doub[i].position == '1') {
			for (int j = 0; j < doub->deckNumber; j++) {
				ptrField[doub[i].Y][doub[i].X + j] = '1';
				ptrField[doub[i].Y - 1][doub[i].X + j] = '2';
				ptrField[doub[i].Y + 1][doub[i].X + j] = '2';
				if (j == 0) {
					for (int k = -1; k < 2; k++) {
						ptrField[doub[i].Y + k][doub[i].X - 1] = '2';
					}
				}
				if (j == 1) {
					for (int k = -1; k < 2; k++) {
						ptrField[doub[i].Y + k][doub[i].X + doub[i].deckNumber] = '2';
					}
				}
				position.Y = doub[i].Y * 2 + 3;
				position.X = (doub[i].X + j) * 2 + 7;
				CW;
				cout << 'X';
			}
		}
	}
}
void AutoPosition1DECK(Ship*single, char(*ptrField)[12]) {
	for (int i = 0; i < 4; i++) {
		do {
			single[i].Y = rand() % 10 + 1;
			single[i].X = rand() % 10 + 1;
		} while (!(single[i].Y <= 11 && single[i].X <= 11) || ptrField[single[i].Y][single[i].X] != '0');
		ptrField[single[i].Y][single[i].X] = '1';
		ptrField[single[i].Y][single[i].X - 1] = '2'; //left aura
		ptrField[single[i].Y][single[i].X + 1] = '2'; //right aura
		for (int k = -1; k < 2; k++) {
			ptrField[single[i].Y - 1][single[i].X + k] = '2';  // up aura
		}
		for (int k = -1; k < 2; k++) {
			ptrField[single[i].Y + single->deckNumber][single[i].X + k] = '2';  // down aura
		}
		position.Y = single[i].Y * 2 + 3;
		position.X = single[i].X * 2 + 7;
		CW;
		cout << 'X';
		position.X = 34;
		position.Y = 7;
		CW;
		cout << "   ";
		position.X = 34;
		position.Y = 8;
		CW;
		cout << "   ";

	}
}
void Position1DECKBOT(Ship*singleBOT, char(*ptrFieldBOT)[12]) {
	for (int i = 0; i < 4; i++) {
		do {
			singleBOT[i].Y = rand() % 10 + 1;
			singleBOT[i].X = rand() % 10 + 1;
		} while (!(singleBOT[i].Y <= 11 && singleBOT[i].X <= 11) || ptrFieldBOT[singleBOT[i].Y][singleBOT[i].X] != '0');
		ptrFieldBOT[singleBOT[i].Y][singleBOT[i].X] = '1';
		ptrFieldBOT[singleBOT[i].Y][singleBOT[i].X - 1] = '2'; //left aura
		ptrFieldBOT[singleBOT[i].Y][singleBOT[i].X + 1] = '2'; //right aura
		for (int k = -1; k < 2; k++) {
			ptrFieldBOT[singleBOT[i].Y - 1][singleBOT[i].X + k] = '2';  // up aura
		}
		for (int k = -1; k < 2; k++) {
			ptrFieldBOT[singleBOT[i].Y + singleBOT->deckNumber][singleBOT[i].X + k] = '2';  // down aura
		}
		position.Y = singleBOT[i].Y * 2 + 3;
		position.X = singleBOT[i].X * 2 + 47;
		CW;
		//cout << 'X';

	}
}
void Position2DECKBOT(Ship*doubBOT, char(*ptrFieldBOT)[12]) {
	for (int i = 0; i < 3; i++) {
		int shipPosition = rand() % 2;
		if (shipPosition == 0) {
			doubBOT[i].position = '0';
		}
		else {
			doubBOT[i].position = '1';
		}
		if (doubBOT[i].position == '0') {
			do {
				doubBOT[i].Y = rand() % 10 + 1;
				doubBOT[i].X = rand() % 10 + 1;
			} while (!(doubBOT[i].Y + 2 <= 11) || ptrFieldBOT[doubBOT[i].Y][doubBOT[i].X - 1] != '0' || ptrFieldBOT[doubBOT[i].Y + 1][doubBOT[i].X] != '0');
		}
		else if (doubBOT[i].position == '1') {
			do {
				doubBOT[i].Y = rand() % 10 + 1;
				doubBOT[i].X = rand() % 10 + 1;
			} while (!(doubBOT[i].X + 2 <= 11) || ptrFieldBOT[doubBOT[i].Y][doubBOT[i].X - 1] != '0' || ptrFieldBOT[doubBOT[i].Y][doubBOT[i].X + 1] != '0');
		}
		if (doubBOT[i].position == '0') {
			for (int j = 0; j < doubBOT->deckNumber; j++) {
				ptrFieldBOT[doubBOT[i].Y + j][doubBOT[i].X] = '1';
				ptrFieldBOT[doubBOT[i].Y + j][doubBOT[i].X - 1] = '2'; //left aura
				ptrFieldBOT[doubBOT[i].Y + j][doubBOT[i].X + 1] = '2'; //right aura
				if (j == 0) {
					for (int k = -1; k < 2; k++) {
						ptrFieldBOT[doubBOT[i].Y - 1][doubBOT[i].X + k] = '2';  // up aura
					}
				}
				if (j == 1) {
					for (int k = -1; k < 2; k++) {
						ptrFieldBOT[doubBOT[i].Y + doubBOT->deckNumber][doubBOT[i].X + k] = '2';  // down aura

					}
				}
				position.Y = (doubBOT[i].Y + j) * 2 + 3;
				position.X = doubBOT[i].X * 2 + 47;
				CW;
				//cout << 'X';
			}
		}
		else if (doubBOT[i].position == '1') {
			for (int j = 0; j < doubBOT->deckNumber; j++) {
				ptrFieldBOT[doubBOT[i].Y][doubBOT[i].X + j] = '1';
				ptrFieldBOT[doubBOT[i].Y - 1][doubBOT[i].X + j] = '2';
				ptrFieldBOT[doubBOT[i].Y + 1][doubBOT[i].X + j] = '2';
				if (j == 0) {
					for (int k = -1; k < 2; k++) {
						ptrFieldBOT[doubBOT[i].Y + k][doubBOT[i].X - 1] = '2';
					}
				}
				if (j == 1) {
					for (int k = -1; k < 2; k++) {
						ptrFieldBOT[doubBOT[i].Y + k][doubBOT[i].X + doubBOT[i].deckNumber] = '2';
					}
				}
				position.Y = doubBOT[i].Y * 2 + 3;
				position.X = (doubBOT[i].X + j) * 2 + 47;
				CW;
				//cout << 'X';
			}
		}
	}
}
void Position3DECKBOT(Ship*threeBOT, char(*ptrFieldBOT)[12]) {
	for (int i = 0; i < 2; i++) {
		int shipPosition = rand() % 2;
		if (shipPosition == 0) {
			threeBOT[i].position = '0';
		}
		else {
			threeBOT[i].position = '1';
		}
		if (threeBOT[i].position == '0') {
			do {
				threeBOT[i].Y = rand() % 10 + 1;
				threeBOT[i].X = rand() % 10 + 1;
			} while (!(threeBOT[i].Y + threeBOT->deckNumber <= 11) || ptrFieldBOT[threeBOT[i].Y][threeBOT[i].X] != '0' || ptrFieldBOT[threeBOT[i].Y + 1][threeBOT[i].X] != '0' || ptrFieldBOT[threeBOT[i].Y + 2][threeBOT[i].X] != '0');
		}
		else if (threeBOT[i].position == '1') {
			do {
				threeBOT[i].Y = rand() % 10 + 1;
				threeBOT[i].X = rand() % 10 + 1;
			} while (!(threeBOT[i].X + 3 <= 11) || ptrFieldBOT[threeBOT[i].Y][threeBOT[i].X] != '0' || ptrFieldBOT[threeBOT[i].Y][threeBOT[i].X + 1] != '0' || ptrFieldBOT[threeBOT[i].Y][threeBOT[i].X + 2] != '0');
		}
		if (threeBOT[i].position == '0') {
			for (int j = 0; j < 3; j++) {
				ptrFieldBOT[threeBOT[i].Y + j][threeBOT[i].X] = '1';
				ptrFieldBOT[threeBOT[i].Y + j][threeBOT[i].X - 1] = '2'; //left aura
				ptrFieldBOT[threeBOT[i].Y + j][threeBOT[i].X + 1] = '2'; //right aura
				if (j == 0) {
					for (int k = -1; k < 2; k++) {
						ptrFieldBOT[threeBOT[i].Y - 1][threeBOT[i].X + k] = '2';  // up aura
					}
				}
				if (j == 2) {
					for (int k = -1; k < 2; k++) {
						ptrFieldBOT[threeBOT[i].Y + threeBOT->deckNumber][threeBOT[i].X + k] = '2';  // down aura

					}
				}
				position.Y = (threeBOT[i].Y + j) * 2 + 3;
				position.X = threeBOT[i].X * 2 + 47;
				CW;
				//cout << 'X';
			}
		}
		else if (threeBOT[i].position == '1') {
			for (int j = 0; j < 3; j++) {
				ptrFieldBOT[threeBOT[i].Y][threeBOT[i].X + j] = '1';
				ptrFieldBOT[threeBOT[i].Y - 1][threeBOT[i].X + j] = '2';
				ptrFieldBOT[threeBOT[i].Y + 1][threeBOT[i].X + j] = '2';
				if (j == 0) {
					for (int k = -1; k < 2; k++) {
						ptrFieldBOT[threeBOT[i].Y + k][threeBOT[i].X - 1] = '2';
					}
				}
				if (j == 2) {
					for (int k = -1; k < 2; k++) {
						ptrFieldBOT[threeBOT[i].Y + k][threeBOT[i].X + threeBOT[i].deckNumber] = '2';
					}
				}
				position.Y = threeBOT[i].Y * 2 + 3;
				position.X = (threeBOT[i].X + j) * 2 + 47;
				CW;
				//cout << 'X';
			}
		}
		position.X = 34;
		position.Y = 7;
		CW;
		cout << "   ";
		position.X = 34;
		position.Y = 8;
		CW;
		cout << "   ";
	}
}
void Position4DECKBOT(Ship*fourBOT, char(*ptrFieldBOT)[12]) {
	int shipPosition = rand() % 2;
	if (shipPosition == 0) {
		fourBOT->position = '0';
	}
	else {
		fourBOT->position = '1';
	}
	if (fourBOT->position == '0') {
		do {
			fourBOT->Y = rand() % 10 + 1;
			fourBOT->X = rand() % 10 + 1;
		} while (!(fourBOT->Y + fourBOT->deckNumber <= 11));
	}
	else if (fourBOT->position == '1') {
		do {
			fourBOT->Y = rand() % 9 + 1;
			fourBOT->X = rand() % 9 + 1;
		} while (!(fourBOT->X + 4 <= 11));
	}
	if (fourBOT->position == '0') {
		for (int j = 0; j < fourBOT->deckNumber; j++) {
			ptrFieldBOT[fourBOT->Y + j][fourBOT->X] = '1';
			ptrFieldBOT[fourBOT->Y + j][fourBOT->X - 1] = '2'; //left aura
			ptrFieldBOT[fourBOT->Y + j][fourBOT->X + 1] = '2'; //right aura
			if (j == 0) {
				for (int k = -1; k < 2; k++) {
					ptrFieldBOT[fourBOT->Y - 1][fourBOT->X + k] = '2';  // up aura
				}
			}
			if (j == 3) {
				for (int k = -1; k < 2; k++) {
					ptrFieldBOT[fourBOT->Y + fourBOT->deckNumber][fourBOT->X + k] = '2';  // down aura

				}
			}
		}
	}
	else if (fourBOT->position == '1') {
		for (int j = 0; j < 4; j++) {
			ptrFieldBOT[fourBOT->Y][fourBOT->X + j] = '1';

			ptrFieldBOT[fourBOT->Y - 1][fourBOT->X + j] = '2';
			ptrFieldBOT[fourBOT->Y + 1][fourBOT->X + j] = '2';
			if (j == 0) {
				for (int k = -1; k < 2; k++) {
					ptrFieldBOT[fourBOT->Y + k][fourBOT->X - 1] = '2';
				}
			}
			if (j == 3) {
				for (int k = -1; k < 2; k++) {
					ptrFieldBOT[fourBOT->Y + k][fourBOT->X + 4] = '2';
				}
			}
		}
	}
}
void MovePlayer(int*Y, int*X, char(*ptrFieldBOT)[12]) {
	position.X = 31;
	position.Y = 5;
	CW;
	cout << "    ";
	position.X = 31;
	position.Y = 6;
	CW;
	cout << "    ";
	position.X = 31;
	position.Y = 3;
	CW;
	cout << "MOVE [Y] [X]:";
	do {
		do {
			position.X = 31;
			position.Y = 5;
			CW;
			cout << "   ";
			position.X = 31;
			position.Y = 6;
			CW;
			cout << "   ";
			position.X = 31;
			position.Y = 5;
			CW;
			cin >> *Y;
			position.X = 31;
			position.Y = 6;
			CW;
			cin >> *X;
		} while (!(*Y > 0 && *Y < 11 && *X>0 && *X < 11));
		if (ptrFieldBOT[*Y][*X] == '1') {
			ptrFieldBOT[*Y][*X] = '3';
			position.Y = *Y * 2 + 3;
			position.X = *X * 2 + 47;
			CW;
			cout << 'X';
			if (ptrFieldBOT[*Y - 1][*X] == '1' || ptrFieldBOT[*Y][*X - 1] == '1' || ptrFieldBOT[*Y + 1][*X] == '1' || ptrFieldBOT[*Y][*X + 1] == '1') {
				position.X = 31;
				position.Y = 8;
				CW;
				cout << "            ";
				position.X = 31;
				position.Y = 8;
				CW;
				cout << "HIT!";
			}
			else {
				ptrFieldBOT[*Y][*X] = '4';
				position.X = 31;
				position.Y = 8;
				CW;
				cout << "DESTROYED!";

			}
		}
		else {
			position.X = 31;
			position.Y = 8;
			CW;
			cout << "         ";
			position.X = 31;
			position.Y = 8;
			CW;
			cout << "MISS!";
			position.Y = *Y * 2 + 3;
			position.X = *X * 2 + 47;
			CW;
			cout << '*';
		}
	} while (ptrFieldBOT[*Y][*X] == '3' || ptrFieldBOT[*Y][*X] == '4');
}
void MoveBOT(int*Y, int*X, char(*ptrField)[12]) {
	do {
		*Y = rand() % 10 + 1;
		*X = rand() % 10 + 1;
		position.X = 31;
		position.Y = 5;
		CW;
		Sleep(1000);
		cout << *Y;
		position.X = 31;
		position.Y = 6;
		CW;
		Sleep(1000);
		cout << *X;
		if (ptrField[*Y][*X] == '1') {
			ptrField[*Y][*X] = '4';
			position.Y = *Y * 2 + 3;
			position.X = *X * 2 + 7;
			CW;
			Sleep(1000);
			cout << char(176);
			if (ptrField[*Y - 1][*X] == '1' || ptrField[*Y][*X - 1] == '1' || ptrField[*Y + 1][*X] == '1' || ptrField[*Y][*X + 1] == '1') {
					position.X = 31;
					position.Y = 8;
					CW;
					Sleep(200);
					cout << "ENEMY'S HIT!";
					do {

					} while (ptrField[*Y - 1][*X] != '1' && ptrField[*Y][*X - 1] != '1' && ptrField[*Y + 1][*X] != '1' && ptrField[*Y][*X + 1] != '1');
				}
			else {
				ptrField[*Y][*X] = '4';
				position.X = 31;
				position.Y = 8;
				CW;
				Sleep(200);
				cout << "SHIP DESTROYED!";
				position.Y = *Y * 2 + 3;
				position.X = *X * 2 + 7;
				CW;
				Sleep(1000);
				cout << char(176);
			}
		}
		else {
			position.X = 31;
			position.Y = 8;
			CW;
			cout << "         ";
			position.X = 31;
			position.Y = 8;
			CW;
			cout << "ENEMY'S MISS!";
			position.Y = *Y * 2 + 3;
			position.X = *X * 2 + 7;
			CW;
			Sleep(1000);
			cout << '*';
		}
	} while (ptrField[*Y][*X] == '3' || ptrField[*Y][*X] == '4');
}
void TEST(char(*ptrField)[12]) {
	position.Y = 30;
	position.X = 3;
	CW;
	for (int i = 1; i < 11; i++) {
		cout << "\n";
		for (int j = 1; j < 11; j++) {
			cout << ptrField[i][j];
		}
	}
}