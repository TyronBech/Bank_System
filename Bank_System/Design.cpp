#include"functions.h"

void BANK::Design() {
	const char dash = '-';
	const char star = '+';
	const char little_star = '.';
	BANK::Color(3);
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
	short value = distribution(generator);
	for (short i = value, j = 3; i <= 110, j < 25; i += value) {
		BANK::gotoxy(value, j); std::cout << star;
		if (i >= 110) j++;
		value = distribution(generator);
	}
	for (short i = value, j = 3; i <= 110, j < 25; i += value) {
		BANK::gotoxy(value, j); std::cout << little_star;
		if (i >= 110) j++;
		value = distribution(generator);
	}

}