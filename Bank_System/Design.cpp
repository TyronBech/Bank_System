#include"functions.h"

void BANK::Design(int ending) {
	const char dash = '-';
	const char star = '+';
	const char little_star = '.';
	BANK::Color(3);
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
		value1 = distribution1(generator);
		BANK::Color(value1);
		for (short i = value, j = 3; i <= 110, j < 24; i += value) {
			if (i >= 110) j++;
			BANK::gotoxy(value, j); std::cout << star;
			value = distribution(generator);
		}
		value1 = distribution1(generator);
		BANK::Color(value1);
		for (short i = value, j = 3; i <= 110, j < 24; i += value) {
			if (i >= 110) j++;
			BANK::gotoxy(value, j); std::cout << little_star;
			value = distribution(generator);
		}
	}
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
		short value = distribution(generator);
		for (short i = value, j = 3; i <= 110, j < 24; i += value) {
			BANK::gotoxy(value, j); std::cout << star;
			if (i >= 110) j++;
			value = distribution(generator);
		}
		for (short i = value, j = 3; i <= 110, j < 24; i += value) {
			BANK::gotoxy(value, j); std::cout << little_star;
			if (i >= 110) j++;
			value = distribution(generator);
		}
	}
}