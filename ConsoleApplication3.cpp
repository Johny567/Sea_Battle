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
void CreateShips();
void ShipPosition(Ship*, Ship*, Ship*, Ship*, char(*ptrField)[10]);
void Position1DECK(Ship*, char(*ptrField)[10]);
void Position2DECK(Ship*, char(*ptrField)[10]);
void Position3DECK(Ship*, char(*ptrField)[10]);
void Position4DECK(Ship*, char(*ptrField)[10]);
void TestViewMassiv(char(*ptrField)[10]);

int main() {
	CreateShips();
	BattleFieldTable();
	int deckNumber;
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
	char Battlefield[10][10];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			Battlefield[i][j] = '0';
		}
	}
	char(*ptrField)[10];
	ptrField = Battlefield;
	position.X = 31;
	position.Y = 2;
	CW;
	cout << "What-deck ship?";
	do {
		position.X = 31;
		position.Y = 3;
		CW;
		cout << "   ";
		position.X = 31;
		position.Y = 3;
		CW;
		cin >> deckNumber;
	} while (!(deckNumber >= 1 && deckNumber <= 4));
	if (deckNumber == 1)
		Position1DECK(single, ptrField);
	else if (deckNumber == 2)
		Position2DECK(doub, ptrField);
	else if (deckNumber == 3)
		Position3DECK(three, ptrField);
	else if (deckNumber == 4)
		Position4DECK(four, ptrField);
	//ShipPosition(single, doub, three, four, ptrField);
	TestViewMassiv(ptrField);
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
void CreateShips() {
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
	Ship*single = singleDeck;  //
	Ship*doub = doubleDeck;    //
	Ship*three = threeDeck;    //
	Ship*four = fourDeck;      //
}
void ShipPosition(Ship*single, Ship*doub, Ship*three, Ship*four, char(*ptrField)[10]) {
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
		for (int j = 0; j < 4; j++) {
			ptrField[four->Y + j - 1][four->X - 1] = '1';
			if (four->Y != 1 && four->Y != 10 && four->X != 1 && four->X != 10) {  // IF NO LIMITES
				ptrField[four->Y + j - 1][four->X - 1 - 1] = '2'; //left aura
				ptrField[four->Y + j - 1][four->X + 1 - 1] = '2'; //right aura
				if (j == 0) {
					for (int k = -1; k < 2; k++) {
						ptrField[four->Y - 1 - 1][four->X + k - 1] = '2';  // up aura
					}
				}
				if (j == 3) {
					for (int k = -1; k < 2; k++) {
						ptrField[four->Y + four->deckNumber - 1][four->X + k - 1] = '2';  // down aura

					}
				}
			}
			else if (!(four->Y != 1 && four->Y != 10 && four->X != 1 && four->X != 10)){ // aura
				if (four->X == 1){ // NO AURA FOR LIEFT Y-LINE
					ptrField[four->Y + j - 1][four->X + 1 - 1] = '2';
					if (four->Y == 1){
						for (int k = 0; k < 2; k++) {
							ptrField[four->Y + four->deckNumber - 1][four->X + k - 1] = '2';  // down aura

						}
					}
					else if (four->Y == 11 - four->deckNumber){
						for (int k = 0; k < 2; k++) {
							ptrField[four->Y - 1 - 1][four->X + k - 1] = '2';  // up aura
						}
					}
					else {
						for (int k = 0; k < 2; k++) {
							ptrField[four->Y - 1 - 1][four->X + k - 1] = '2';  // up aura
						}
						for (int k = 0; k < 2; k++) {
							ptrField[four->Y + four->deckNumber - 1][four->X + k - 1] = '2';  // down aura

						}
					}
				}
				else if (four->X == 10){  // NO AURA FOR RIGHT Y-LINE
					ptrField[four->Y + j - 1][four->X - 1 - 1] = '2'; //left aura
					if (four->Y == 1){
						for (int k = -1; k < 1; k++) {
							ptrField[four->Y + four->deckNumber - 1][four->X + k - 1] = '2';  // down aura

						}
					}
					else if (four->Y == 11 - four->deckNumber){
						for (int k = -1; k < 1; k++) {
							ptrField[four->Y - 1 - 1][four->X + k - 1] = '2';  // up aura
						}
					}
					else {
						for (int k = -1; k < 1; k++) {
							ptrField[four->Y - 1 - 1][four->X + k - 1] = '2';  // up aura
						}
						for (int k = -1; k < 1; k++) {
							ptrField[four->Y + four->deckNumber - 1][four->X + k - 1] = '2';  // down aura

						}
					}
				}
			}
			position.Y = (four->Y + j) * 2 + 3;
			position.X = four->X * 2 + 7;
			CW;
			cout << 'X';
		}
		position.Y = 30;    //TESTING VIEW MASSIV
		position.X = 3;
		CW;
		for (int i = 0; i < 10; i++) {
			cout << "\n";
			for (int j = 0; j < 10; j++) {
				cout << ptrField[i][j];
			}
		}
	}
	else if (four->position == 'H' || four->position == 'h') {
		for (int j = 0; j < 4; j++) {
			ptrField[four->Y - 1][four->X + j - 1] = '1';
			if (four->Y != 1 && four->Y != 10 && four->X != 1 && four->X != 10) {  // IF NO LIMITES
				ptrField[four->Y - 1 - 1][four->X + j - 1] = '2';
				ptrField[four->Y + 1 - 1][four->X + j - 1] = '2';

				if (j == 0) {
					for (int k = -1; k < 2; k++) {
						ptrField[four->Y + k - 1][four->X - 1 - 1] = '2';
					}
				}
				if (j == 3) {
					for (int k = -1; k < 2; k++) {
						ptrField[four->Y + k - 1][four->X + 4 - 1] = '2';

					}
				}
			}
			position.Y = four->Y * 2 + 3;
			position.X = (four->X + j) * 2 + 7;
			CW;
			cout << 'X';
		}
		position.Y = 30;    //TESTING VIEW MASSIV
		position.X = 3;
		CW;
		for (int i = 0; i < 10; i++) {
			cout << "\n";
			for (int j = 0; j < 10; j++) {
				cout << ptrField[i][j];
			}
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
			} while (!(three[i].Y + 3 <= 11) || !(ptrField[three[i].Y - 1][three[i].X - 1] == '0') || !(ptrField[three[i].Y + 1 - 1][three[i].X - 1] == '0') || !(ptrField[three[i].Y + 2 - 1][three[i].X - 1] == '0'));
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
			} while (!(three[i].X + 3 <= 11) || !(ptrField[three[i].Y - 1][three[i].X - 1] == '0') || !(ptrField[three[i].Y - 1][three[i].X + 1 - 1] == '0') || !(ptrField[three[i].Y - 1][three[i].X + 2 - 1] == '0'));
		}
		if (three[i].position == 'V' || three[i].position == 'v') {
			for (int j = 0; j < 3; j++) {
				ptrField[three[i].Y + j - 1][three[i].X - 1] = '1';
				position.Y = (three[i].Y + j) * 2 + 3;
				position.X = three[i].X * 2 + 7;
				CW;
				cout << 'X';
			}
		}
		else if (three[i].position == 'H' || three[i].position == 'h') {
			for (int j = 0; j < 3; j++) {
				ptrField[three[i].Y - 1][three[i].X + j - 1] = '1';
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
			} while (!(doub[i].Y + 2 <= 11) || !(ptrField[doub[i].Y - 1][doub[i].X - 1] == '0') || !(ptrField[doub[i].Y + 1 - 1][doub[i].X - 1] == '0'));
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
			} while (!(doub[i].X + 2 <= 11) || !(ptrField[doub[i].Y - 1][doub[i].X - 1] == '0') || !(ptrField[doub[i].Y - 1][doub[i].X + 1 - 1] == '0'));
		}
		if (doub[i].position == 'V' || doub[i].position == 'v') {
			for (int j = 0; j < 2; j++) {
				ptrField[doub[i].Y + j - 1][doub[i].X - 1] = '1';
				position.Y = (doub[i].Y + j) * 2 + 3;
				position.X = doub[i].X * 2 + 7;
				CW;
				cout << 'X';
			}
		}
		else if (doub[i].position == 'H' || doub[i].position == 'h') {
			for (int j = 0; j < 2; j++) {
				ptrField[doub[i].Y - 1][doub[i].X + j - 1] = '1';
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
		} while (!(single[i].Y <= 11 && single[i].X <= 11) || !(single[i].Y >0 && single[i].X >0) || !(ptrField[single[i].Y - 1][single[i].X - 1] == '0'));
		ptrField[single[i].Y - 1][single[i].X - 1] = '1';
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
void Position4DECK(Ship*four, char(*ptrField)[10]){
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
		for (int j = 0; j < 4; j++) {
			ptrField[four->Y + j - 1][four->X - 1] = '1';
			if (four->Y != 1 && four->Y != 10 && four->X != 1 && four->X != 10) {  // IF NO LIMITES
				ptrField[four->Y + j - 1][four->X - 1 - 1] = '2'; //left aura
				ptrField[four->Y + j - 1][four->X + 1 - 1] = '2'; //right aura
				if (j == 0) {
					for (int k = -1; k < 2; k++) {
						ptrField[four->Y - 1 - 1][four->X + k - 1] = '2';  // up aura
					}
				}
				if (j == 3) {
					for (int k = -1; k < 2; k++) {
						ptrField[four->Y + four->deckNumber - 1][four->X + k - 1] = '2';  // down aura

					}
				}
			}
			else if (!(four->Y != 1 && four->Y != 10 && four->X != 1 && four->X != 10)){ // aura
				if (four->X == 1){ // NO AURA FOR LIEFT Y-LINE
					ptrField[four->Y + j - 1][four->X + 1 - 1] = '2';
					if (four->Y == 1){
						for (int k = 0; k < 2; k++) {
							ptrField[four->Y + four->deckNumber - 1][four->X + k - 1] = '2';  // down aura

						}
					}
					else if (four->Y == 11 - four->deckNumber){
						for (int k = 0; k < 2; k++) {
							ptrField[four->Y - 1 - 1][four->X + k - 1] = '2';  // up aura
						}
					}
					else {
						for (int k = 0; k < 2; k++) {
							ptrField[four->Y - 1 - 1][four->X + k - 1] = '2';  // up aura
						}
						for (int k = 0; k < 2; k++) {
							ptrField[four->Y + four->deckNumber - 1][four->X + k - 1] = '2';  // down aura

						}
					}
				}
				else if (four->X == 10){  // NO AURA FOR RIGHT Y-LINE
					ptrField[four->Y + j - 1][four->X - 1 - 1] = '2'; //left aura
					if (four->Y == 1){
						for (int k = -1; k < 1; k++) {
							ptrField[four->Y + four->deckNumber - 1][four->X + k - 1] = '2';  // down aura

						}
					}
					else if (four->Y == 11 - four->deckNumber){
						for (int k = -1; k < 1; k++) {
							ptrField[four->Y - 1 - 1][four->X + k - 1] = '2';  // up aura
						}
					}
					else {
						for (int k = -1; k < 1; k++) {
							ptrField[four->Y - 1 - 1][four->X + k - 1] = '2';  // up aura
						}
						for (int k = -1; k < 1; k++) {
							ptrField[four->Y + four->deckNumber - 1][four->X + k - 1] = '2';  // down aura

						}
					}
				}
			}
			position.Y = (four->Y + j) * 2 + 3;
			position.X = four->X * 2 + 7;
			CW;
			cout << 'X';
		}
		position.Y = 30;    //TESTING VIEW MASSIV
		position.X = 3;
		CW;
		for (int i = 0; i < 10; i++) {
			cout << "\n";
			for (int j = 0; j < 10; j++) {
				cout << ptrField[i][j];
			}
		}
	}
	else if (four->position == 'H' || four->position == 'h') {
		for (int j = 0; j < 4; j++) {
			ptrField[four->Y - 1][four->X + j - 1] = '1';
			if (four->Y != 1 && four->Y != 10 && four->X != 1 && four->X != 10) {  // IF NO LIMITES
				ptrField[four->Y - 1 - 1][four->X + j - 1] = '2';
				ptrField[four->Y + 1 - 1][four->X + j - 1] = '2';

				if (j == 0) {
					for (int k = -1; k < 2; k++) {
						ptrField[four->Y + k - 1][four->X - 1 - 1] = '2';
					}
				}
				if (j == 3) {
					for (int k = -1; k < 2; k++) {
						ptrField[four->Y + k - 1][four->X + 4 - 1] = '2';

					}
				}
			}
			position.Y = four->Y * 2 + 3;
			position.X = (four->X + j) * 2 + 7;
			CW;
			cout << 'X';
		}
		position.Y = 30;    //TESTING VIEW MASSIV
		position.X = 3;
		CW;
		for (int i = 0; i < 10; i++) {
			cout << "\n";
			for (int j = 0; j < 10; j++) {
				cout << ptrField[i][j];
			}
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
void TestViewMassiv(char(*ptrField)[10]) {  //TESTING VIEW READY MASSIV
	position.Y = 30;
	position.X = 3;
	CW;
	for (int i = 0; i < 10; i++) {
		cout << "\n";
		for (int j = 0; j < 10; j++) {
			cout << ptrField[i][j];
		}
	}
}