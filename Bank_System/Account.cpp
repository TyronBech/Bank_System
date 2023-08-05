#include "functions.h"

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
	BANK::Design();
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