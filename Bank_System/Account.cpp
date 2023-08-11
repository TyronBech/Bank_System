#include "functions.h"
#include "Account.h"

/// <summary>
/// This function is used to calculate the user's age
/// based on the given birthdate, it will automatically
/// updated once the program run again
/// </summary>
void user::Account::Age_counter() {
	const std::string Months[] = {
		"", "January", "February", "March", "April",
		"May", "June", "July", "August",
		"September", "October", "November", "December"
	};
	std::stringstream ss(Birthdate);
	std::string month = "";
	unsigned day = 0, year = 0;
	ss >> month >> day >> year;
	time_t now = time(0);
	std::tm Local_Time;
	if (localtime_s(&Local_Time, &now) != 0) {
		system("cls");
		BANK::Design(0);
		BANK::Color(4);
		BANK::gotoxy(47, 11); std::cerr << "Error: Local Time failed" << std::endl;
		system("pause>0");
	}
	else {
		Age = static_cast<unsigned>(Local_Time.tm_year + 1900) - year;
		for (signed i = 1; i < 13; i++) {
			if (month == Months[i]) {
				if ((i > Local_Time.tm_mon + 1) ||
					(i == Local_Time.tm_mon + 1 && static_cast<signed>(day) > Local_Time.tm_mday))
					Age--;
			}
		}
	}
};
// This function changes each characters to '*' based on its length
std::string Asterisk(size_t size) {
	const char asterisk = '*';
	std::string converted_string = "";
	for (size_t i = 0; i < size; i++) {
		converted_string += asterisk;
	}
	return converted_string;
}
// This function declared in class Account is used to display user's information
// just like any profile application
void user::Account::Profile_Info() {
	system("cls");
	BANK::Design(0);
	BANK::Color(2);
	BANK::gotoxy(52, 10); std::cout << "Profile Section" << std::endl;
	BANK::gotoxy(48, 11); std::cout << "ID: " << ID << std::endl;
	BANK::gotoxy(48, 12); std::cout << "Name: " << Name << std::endl;
	BANK::gotoxy(48, 13); std::cout << "Age: " << Age << std::endl;
	BANK::gotoxy(48, 14); std::cout << "Birthdate: " << Birthdate << std::endl;
	BANK::gotoxy(48, 15); std::cout << "Gender: " << Gender << std::endl;
	BANK::gotoxy(48, 16); std::cout << "Username: " << Username << std::endl;
	BANK::gotoxy(48, 17); std::cout << "Password: " << Asterisk(Password.length()) << std::endl;
	system("pause>0");
}