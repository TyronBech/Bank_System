#include"functions.h"
#include<Windows.h>

void BANK::gotoxy(short x, short y) {
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void BANK::Color(short colorCode) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	short colors1 = FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY; // Purple
	short colors2 = FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY; // Bright Yellow
	short colors3 = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY; // Indigo
	short colors4 = FOREGROUND_RED | FOREGROUND_INTENSITY; // Red
	short colors5 = FOREGROUND_BLUE | FOREGROUND_INTENSITY; // Blue
	short colors6 = FOREGROUND_GREEN | FOREGROUND_INTENSITY; // Green
	switch (colorCode) {
	case 1: SetConsoleTextAttribute(handle, colors1);
		break;
	case 2: SetConsoleTextAttribute(handle, colors2);
		break;
	case 3: SetConsoleTextAttribute(handle, colors3);
		break;
	case 4: SetConsoleTextAttribute(handle, colors4);
		break;
	case 5: SetConsoleTextAttribute(handle, colors5);
		break;
	case 6: SetConsoleTextAttribute(handle, colors6);
		break;
	}
}