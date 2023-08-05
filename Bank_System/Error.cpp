#include"functions.h"
#include<stdexcept>
/// <summary>
/// The function helps to improve the program since
/// it helps to avoid errors during run time
/// it it used to validate user's input particularly in
/// integral inputs
/// </summary>
/// <param name="choice">
/// The parameter choice is the input variable that is
/// going to be checked
/// </param>
/// <returns>
/// It will return the original value of the choice
/// if the input is successful else 0 if it encounter
/// any error
/// </returns>
int BANK::Try_catch_int(long long choice) {
	try {
		std::cin >> choice;
		// Letting the std::cin to throw its own exceptions
		// particularly the cin.fail()
		std::cin.exceptions(std::ios_base::failbit);
		// If the user exceeds the value that int can hold, it will
		// throw std::out_of_range to indicate that input is not valid anymore
		if (choice > std::numeric_limits<int>::max() || choice < std::numeric_limits<int>::min())
			throw std::out_of_range("The input is out of range");
		return static_cast<int>(choice);
	}
	// This catch will get the error mainly in cin exceptions
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
	// This catch will get the error based on the std::out_of_range
	catch (const std::out_of_range& e) {
		system("cls");
		BANK::Design(0);
		BANK::Color(4);
		BANK::gotoxy(41, 14); std::cerr << "Exception caught: " << e.what() << std::endl;
		BANK::gotoxy(52, 15); std::cout << "Please try again" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		system("pause>0");
		return 0;
	}
	// This catch will get the other exception that program will get
	catch (const std::exception& e) {
		system("cls");
		BANK::Design(0);
		BANK::Color(4);
		BANK::gotoxy(41, 14); std::cerr << "Exception caught: " << e.what() << std::endl;
		BANK::gotoxy(52, 15); std::cout << "Please try again" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		system("pause>0");
		return 0;
	}
}