#include"functions.h"

void Delete(std::vector<user::Account>& Data, user::Account User) {
	BANK::Account_List(0, Data);
	size_t index = BANK::binary_search(Data, User.get_Username());
	if (index < Data.size()) {
		Data.erase(Data.begin() + index);
		BANK::Account_List(1, Data);
	}
	else std::cout << "Cannot Find the username in the database" << std::endl;
}
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
	size_t index = -1;
	bool result;
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
				result = BANK::Main_Bank(Data[index], index);
				if (result) {
					Delete(Data, Data[index]);
				}
				BANK::Account_List(2, Data);
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