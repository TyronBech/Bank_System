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
	std::cout << "ID: " << ID << std::endl;
	std::cout << "Name: " << Name << std::endl;
	std::cout << "Age: " << Age << std::endl;
	std::cout << "Birthdate: " << Birthdate << std::endl;
	std::cout << "Gender: " << Gender << std::endl;
	std::cout << "Username: " << Username << std::endl;
	std::cout << "Password: " << Asterisk(Password.length()) << std::endl;
}