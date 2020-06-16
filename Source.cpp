#include <iostream>
#include <string>
#include <Windows.h>
#include <cmath>

#define SIZE 8
#define WHITE_FIELD "Wh"
#define BLACK_FIELD "Bl"
#define KING_WHITE "kWh"
#define KING_BLACK "kBl"
#define EMPTY '-'
#define COUNT_OF_CHECKERS 3
#define CHECKER "*"

using namespace std;

class Checker {
public:
	bool isQueen = false;
	bool isAlive = true;
	int row;
	int column;
	bool canKill = false;
	bool canDead = false;
	bool isWhite;

	void init(int row, int column, bool color) {
		this->row = row;
		this->column = column;
		isWhite = color;
	}


};

void updateField(Checker* checker, string** field) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			field[i][j] = EMPTY;
		}
	}

	for (int i = 0; i < COUNT_OF_CHECKERS; i++) {	
		field[checker[i].row][checker[i].column] = CHECKER;
	}
}

bool findCheckerColor(Checker* checker, int pos_row, int pos_column) {
	for (int i = 0; i < COUNT_OF_CHECKERS; i++) {
		if (checker[i].row == pos_row && checker[i].column == pos_column) {
			return checker[i].isWhite;
		}
	}
	return false;
}

void showField(Checker* checker, string** field) {
	system("cls");
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (field[i][j] == CHECKER) {
				if (findCheckerColor(checker, i, j)) {
					HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(hConsole, (WORD)((15 << 4) | 4));//red
				}
				else {
					HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(hConsole, (WORD)((15 << 4) | 0));
				}
			}
			cout << field[i][j] << " ";
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, (WORD)((15 << 4) | 0));
		}
		cout << endl;
	}
} 


int main() {
	system("color F0");
	string** field = new string* [SIZE];
	for (int i = 0; i < SIZE; i++) {
		field[i] = new string[SIZE];
	}
	//Checker c(0,0);
	
	Checker checker[3];
	checker[0].init(1, 1, 0);
	checker[1].init(1, 3, 1);
	checker[2].init(1, 5, 0);
	updateField(checker, field);
	showField(checker, field);
	

	return 0;
}