#include"functions.h"

bool BANK::Log_in(std::vector<user::Account>& Data) {
	std::string input_username = "", input_pass = "";
	unsigned counter = 1;
	do {
		std::cout << "Log In Section" << std::endl;
		std::cout << "Enter username: ";
		std::getline(std::cin >> std::ws, input_username);
		std::cout << "Enter a password: ";
		std::getline(std::cin >> std::ws, input_pass);
		for (size_t i = 0; i < Data.size(); i++) {
			if (input_username == Data[i].get_Username() && input_pass == Data[i].get_Password()) return true;
		}
		size_t flag = 0;
		for (size_t i = 0; i < Data.size(); i++) {
			if (input_username == Data[i].get_Username() && input_pass != Data[i].get_Password()) {
				std::cout << "Wrong password" << std::endl;
				std::cout << "Please try again" << std::endl;
				break;
			}
			else if (input_username != Data[i].get_Username() && input_pass == Data[i].get_Password()) {
				std::cout << "Wrong username" << std::endl;
				std::cout << "Please try again" << std::endl;
				break;
			}
			if (flag = Data.size()) {
				std::cout << "The input account does not exist" << std::endl;
				std::cout << "Please try another account" << std::endl;
				return false;
			}
			flag++;
		}
		if (counter > 3) {
			std::cout << "You have tried moultiple times and failed" << std::endl;
			std::cout << "Log in terminated" << std::endl;
			return false;
		}
		counter++;
	} while (true);
	return false;
}