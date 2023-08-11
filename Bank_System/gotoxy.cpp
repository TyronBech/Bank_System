#include"functions.h"
#include<Windows.h>

/// <summary>
/// This function is used to realign the text in the console
/// during program execution
/// </summary>
/// <param name="x">
/// The paramater x will give the x coordinate of the console
/// </param>
/// <param name="y">
/// The paramater y will give the y coordinate of the console
/// </param>
void BANK::gotoxy(short x, short y) {
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
/// <summary>
/// This enum will help the programmer to distinguish the color based
/// on the set name on each combinations
/// </summary>
enum TEXT_COLOR {
	MAGENTA = FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY,
	YELLOW = FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY,
	CYAN = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY,
	RED = FOREGROUND_RED | FOREGROUND_INTENSITY,
	BLUE = FOREGROUND_BLUE | FOREGROUND_INTENSITY,
	GREEN = FOREGROUND_GREEN | FOREGROUND_INTENSITY,
	RESET_COLOR = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE
};

/// <summary>
/// This function will give the color of the text during program
/// execution, and the color will be identified based on passed argument
/// </summary>
/// <param name="colorCode">
/// The colorCode will define which color to be used to change the
/// text color in the console
/// </param>
void BANK::Color(short colorCode) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	switch (colorCode) {
	case 1: SetConsoleTextAttribute(handle, MAGENTA);
		break;
	case 2: SetConsoleTextAttribute(handle, YELLOW);
		break;
	case 3: SetConsoleTextAttribute(handle, CYAN);
		break;
	case 4: SetConsoleTextAttribute(handle, RED);
		break;
	case 5: SetConsoleTextAttribute(handle, BLUE);
		break;
	case 6: SetConsoleTextAttribute(handle, GREEN);
		break;
	case 7: SetConsoleTextAttribute(handle, RESET_COLOR);
	}
}