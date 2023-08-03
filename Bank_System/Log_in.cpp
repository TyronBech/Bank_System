#include"functions.h"
/// <summary>
/// This log in function is used to input user's username & password
/// it check if the input is equal to the existing account and if its correct,
/// it will direct to the Main_Bank function to do some transactions
/// </summary>
/// <param name="Data"> Data is used to check if user's input 
/// exists in the vector Data which retrieved in csv file</param>
/// <returns> returns true if log in is successful & false if not</returns>
bool BANK::Log_in(std::vector<user::Account>& Data) {
	std::string input_username = "", input_pass = "";
	unsigned counter = 1;
	do {
		std::cout << "Log In Section" << std::endl;
		std::cout << "Enter username: ";
		std::getline(std::cin >> std::ws, input_username);
		std::cout << "Enter a password: ";
		std::getline(std::cin >> std::ws, input_pass);
		size_t index = BANK::binary_search(Data,input_username);
		// This part will check is the account exist and if the
		// input password is correct
		if (index == -1) {
			std::cout << "Sorry there is no existing account" << std::endl;
			std::cout << "Please try another account" << std::endl;
			counter++;
		}
		else {
			if (input_pass == Data[index].get_Password()) {
				BANK::Main_Bank(Data[index]);
				return true;
			}
			else {
				std::cout << "The input password is incorrect" << std::endl;
				std::cout << "Please try again" << std::endl;
				counter++;
			}
		}
		if (counter > 3) {
			std::cout << "You have tried many times" << std::endl;
			std::cout << "Log in is terminated" << std::endl;
			return false;
		}
	} while (true);
}