#include"functions.h"
#include<stdexcept>

int BANK::Try_catch_int(long long choice) {
	try {
		std::cin >> choice;
		std::cin.exceptions(std::ios_base::failbit);
		if (choice > std::numeric_limits<int>::max() || choice < std::numeric_limits<int>::min())
			throw std::out_of_range("The input is out of range");
		return static_cast<int>(choice);
	}
	catch (const std::ios_base::failure& e) {
		system("cls");
		BANK::Design(0);
		BANK::Color(4);
		if (e.code() == std::make_error_code(std::io_errc::stream)) {
			BANK::gotoxy(41, 14); std::cerr << "Exception caught: Input must be integer" << std::endl;
			BANK::gotoxy(52, 15); std::cout << "Please try again" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			system("pause>0");
			return 0;
		}
		else {
			BANK::gotoxy(41, 14); std::cerr << "Exception caught: " << e.what() << std::endl;
			BANK::gotoxy(52, 15); std::cout << "Please try again" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			system("pause>0");
			return 0;
		}
	}
	catch (const std::out_of_range& e) {
		system("cls");
		BANK::Design(0);
		BANK::Color(4);
		BANK::gotoxy(41, 14); std::cerr << "Exception caught: input is out of range" << std::endl;
		BANK::gotoxy(52, 15); std::cout << "Please try again" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		system("pause>0");
		return 0;
	}
}