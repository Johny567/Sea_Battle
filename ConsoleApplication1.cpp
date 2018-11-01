// Morskoi_Boi.cpp: определяет точку входа для консольного приложения.
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
	int X; // А-К
	int deckNumber; //кол-во палуб
	char position; // положение (В\Г)
};
void BattleFieldTable();
void CreateShips();
void ShipPosition(Ship*, Ship*, Ship*, Ship*, char(*ptrField)[10]);
void TestViewMassiv(char(*ptrField)[10]);

int main() {
	//CreateShips();
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
	char Battlefield[10][10];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			Battlefield[i][j] = '0';
		}
	}
	char(*ptrField)[10];
	ptrField = Battlefield;
	ShipPosition(single, doub, three, four, ptrField);
	TestViewMassiv(ptrField);
	return 0;
}

void BattleFieldTable(){
	system("color 3");
	cout << "\n\n\n";
	cout << "\t 1 2 3 4 5 6 7 8 9 10 \t\t\t 1 2 3 4 5 6 7 8 9 10";
	for (int j = 0; j < 10; j++){
		cout << "\n\t---------------------\t\t\t---------------------\t\n\t";
		for (int i = 0; i <= 10; i++){
			cout << "|";
			cout << " ";
		}
		cout << "\t\t\t";
		for (int i = 0; i <= 10; i++){
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
	Ship*single = singleDeck;  //создание
	Ship*doub = doubleDeck;    //указателей
	Ship*three = threeDeck;    //на структуры
	Ship*four = fourDeck;      //кораблей
}
void ShipPosition(Ship*single, Ship*doub, Ship*three, Ship*four, char(*ptrField)[10]) {
	int x=0, y=0;
	position.X = 31;
	position.Y = 6;
	CW;
	cout << "[Y]  [X] coords";
	position.X = 34;
	position.Y = 7;
	CW;
	cout << "FOUR-deck:";
	for (int i = 0; i < four->deckNumber; i++) {  //расстановка 4-палубника
		do {
			do {
				position.X = 30;
				position.Y = 8;
				CW;
				cin >> four->Y;
			} while (four->Y > 10 || four->Y < 1);
			y = four->Y;
			do {
				position.X = 30;
				position.Y = 9;
				CW;
				cin >> four->X;
			} while (four->X > 10 || four->X < 1);
			x = four->X;
		} while (!(i == 0) || !(four->X <= x + 1) || !(four->X >= x - 1) || !(four->Y <= y + 1) || !(four->Y >= y - 1));
		ptrField[four->Y][four->X] = '1';
			position.Y = four->Y * 2 + 3;
			position.X = four->X * 2 + 7;
			CW;
			cout << 'X';
			position.X = 30;
			position.Y = 8;
			CW;
			cout << "   ";
			position.X = 30;
			position.Y = 9;
			CW;
			cout << "   ";
	}
	position.X = 34;
	position.Y = 7;
	CW;
	cout << "THREE-deck:";
	for (int j = 0; j < 2; j++){    //расстановка 3-палубников
		for (int i = 0; i < three->deckNumber; i++) {
			do{
				position.X = 30;
				position.Y = 8;
				CW;
				cin >> three->Y;
				position.X = 30;
				position.Y = 9;
				CW;
				cin >> three->X;
			} while (three->X > 10 || three->X <1 || three->Y>10 || three->Y <1);
			position.Y = three->Y * 2 + 3;
			position.X = three->X * 2 + 7;
			CW;
			cout << 'X';
			position.X = 30;
			position.Y = 8;
			CW;
			cout << "   ";
			position.X = 30;
			position.Y = 9;
			CW;
			cout << "   ";
			ptrField[three->Y][three->X] = '1';
		}
	}
	position.X = 34;
	position.Y = 7;
	CW;
	cout << "DOUBLE-deck:";
	for (int j = 0; j < 3; j++){  //расстановка 2-палубников
		for (int i = 0; i < doub->deckNumber; i++) {
			do{
				position.X = 30;
				position.Y = 8;
				CW;
				cin >> doub->Y;
				position.X = 30;
				position.Y = 9;
				CW;
				cin >> doub->X;
			} while (doub->X > 10 || doub->X <1 || doub->Y>10 || doub->Y <1);
			position.Y = doub->Y * 2 + 3;
			position.X = doub->X * 2 + 7;
			CW;
			cout << 'X';
			position.X = 30;
			position.Y = 8;
			CW;
			cout << "   ";
			position.X = 30;
			position.Y = 9;
			CW;
			cout << "   ";
			ptrField[doub->Y][doub->X] = '1';
		}
	}
	position.X = 34;
	position.Y = 7;
	CW;
	cout << "SINGLE-deck:";
	for (int j = 0; j < 4; j++){ //расстановка 1-палубников
		for (int i = 0; i < single->deckNumber; i++) {
			do{
				position.X = 30;
				position.Y = 8;
				CW;
				cin >> single->Y;
				position.X = 30;
				position.Y = 9;
				CW;
				cin >> single->X;
			} while (single->X > 10 || single->X <1 || single->Y>10 || single->Y <1);
			position.Y = single->Y * 2 + 3;
			position.X = single->X * 2 + 7;
			CW;
			cout << 'X';
			position.X = 30;
			position.Y = 8;
			CW;
			cout << "   ";
			position.X = 30;
			position.Y = 9;
			CW;
			cout << "   ";
			ptrField[single->Y][single->X] = '1';
		}
	}
}
void TestViewMassiv(char(*ptrField)[10]){  //покажет системное поле для проверки (10х10)
	position.Y = 30;
	position.X = 3;
	CW;
	for (int i = 0; i < 10; i++){
		cout << "\n";
		for (int j = 0; j < 10; j++){
			cout << ptrField[i][j];
		}
	}
}
