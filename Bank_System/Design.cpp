#include"functions.h"
/// <summary>
/// This function is used to give life to the console while
/// running the program, it prints bar both on top and bottom
/// It also compost of '+' and '.' as stars that randomly
/// prints to the console each time the program clear screen
/// </summary>
/// <param name="ending">
/// the ending parameter is a flag to identify if the function
/// will change its color and reset the design overtime or
/// just reset if the program changes menu
/// </param>
void BANK::Design(int ending) {
	// constant parameter used to print necessary design
	const char dash = '-';
	const char star = '+';
	const char little_star = '.';
	BANK::Color(3);
	std::random_device rand;
	std::mt19937 generator(rand());
	// Random number set for stars
	short min = 5, max = 115;
	std::uniform_int_distribution<short> distribution(min, max);
	short value = distribution(generator);
	// Random number set for color
	short low = 1, high = 6;
	std::uniform_int_distribution<short> distribution1(low, high);
	short value_color = distribution1(generator);
	// if ending is equal to 1 it means the function
	// will print the design in the console with
	// randomly selected color set to '-', '+' and '.'
	// it resets the design based on for loop of the main
	// function
	if (ending == 0) BANK::Color(3);
	else BANK::Color(value_color);
	// For loop for dash
	for (short i = 5; i <= 115; i++) {
		BANK::gotoxy(i, 1); std::cout << dash;
		BANK::gotoxy(i, 26); std::cout << dash;
	}
	for (short j = 10; j <= 110; j++) {
		BANK::gotoxy(j, 2); std::cout << dash;
		BANK::gotoxy(j, 25); std::cout << dash;
	}
	// For loop for stars
	for (short i = value, j = 3; i <= 110, j < 24; i += value) {
		value_color = distribution1(generator);
		BANK::Color(value_color);
		if (i >= 110) { j++; i = value; }
		BANK::gotoxy(value, j); std::cout << star;
		value = distribution(generator);
	}
	for (short i = value, j = 3; i <= 110, j < 24; i += value) {
		value_color = distribution1(generator);
		BANK::Color(value_color);
		if (i >= 110) { j++; i = value; }
		BANK::gotoxy(value, j); std::cout << little_star;
		value = distribution(generator);
	}
}