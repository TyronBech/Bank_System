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
	// if ending is equal to 1 it means the funtion
	// will print the design in the console with
	// randomly selected color set to '-', '+' and '.'
	// it resets the design based on forloop of the main
	// function
	if (ending == 1) {
		std::random_device rand;
		std::mt19937 generator(rand());
		short min = 5, max = 115;
		std::uniform_int_distribution<short> distribution(min, max);
		short low = 1, high = 6;
		std::uniform_int_distribution<short> distribution1(low, high);
		short value = distribution(generator);
		short value1 = distribution1(generator);
		BANK::Color(value1);
		for (short i = 5; i <= 115; i++) {
			BANK::gotoxy(i, 1); std::cout << dash;
			BANK::gotoxy(i, 26); std::cout << dash;
		}
		for (short j = 10; j <= 110; j++) {
			BANK::gotoxy(j, 2); std::cout << dash;
			BANK::gotoxy(j, 25); std::cout << dash;
		}
		for (short i = value, j = 3; i <= 110, j < 24; i += value) {
			value1 = distribution1(generator);
			BANK::Color(value1);
			if (i >= 110) { j++; i = value; }
			BANK::gotoxy(value, j); std::cout << star;
			value = distribution(generator);
		}
		for (short i = value, j = 3; i <= 110, j < 24; i += value) {
			value1 = distribution1(generator);
			BANK::Color(value1);
			if (i >= 110) { j++; i = value; }
			BANK::gotoxy(value, j); std::cout << little_star;
			value = distribution(generator);
		}
	}
	// the else statement is used for general usage of the function
	// it only changes if the program changes menu or printing error
	else {
		for (short i = 5; i <= 115; i++) {
			BANK::gotoxy(i, 1); std::cout << dash;
			BANK::gotoxy(i, 26); std::cout << dash;
		}
		for (short j = 10; j <= 110; j++) {
			BANK::gotoxy(j, 2); std::cout << dash;
			BANK::gotoxy(j, 25); std::cout << dash;
		}
		std::random_device rand;
		std::mt19937 generator(rand());
		short min = 5, max = 115;
		std::uniform_int_distribution<short> distribution(min, max);
		short low = 1, high = 6;
		std::uniform_int_distribution<short> distribution1(low, high);
		short value = distribution(generator);
		short value1 = distribution1(generator);
		for (short i = value, j = 3; i <= 110, j < 24; i += value) {
			value1 = distribution1(generator);
			BANK::Color(value1);
			BANK::gotoxy(value, j); std::cout << star;
			if (i >= 110) { j++; i = value; }
			value = distribution(generator);
		}
		for (short i = value, j = 3; i <= 110, j < 24; i += value) {
			value1 = distribution1(generator);
			BANK::Color(value1);
			BANK::gotoxy(value, j); std::cout << little_star;
			if (i >= 110) { j++; i = value; }
			value = distribution(generator);
		}
	}
}