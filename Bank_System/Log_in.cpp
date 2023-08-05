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
	size_t index = -1;
	bool result;
	do {
		system("cls");
		BANK::Design();
		BANK::Color(2);
		BANK::gotoxy(53, 10); std::cout << "Log In Section" << std::endl;
		BANK::gotoxy(48, 12); std::cout << "Enter username: ";
		std::getline(std::cin >> std::ws, input_username);
		BANK::gotoxy(48, 13); std::cout << "Enter a password: ";
		std::getline(std::cin >> std::ws, input_pass);
		size_t index = BANK::binary_search(Data, input_username);
		// This part will check is the account exist and if the
		// input password is correct
		if (index == -1) {
			BANK::gotoxy(43, 15); std::cout << "Sorry there is no existing account" << std::endl;
			BANK::gotoxy(47, 16); std::cout << "Please try another account" << std::endl;
			counter++;
		}
		else {
			if (input_pass == Data[index].get_Password()) {
				result = BANK::Main_Bank(Data[index]);
				if (result) {
					BANK::Delete(Data, Data[index]);
				}
				return true;
			}
			else {
				BANK::gotoxy(44, 15); std::cout << "The input password is incorrect" << std::endl;
				BANK::gotoxy(52, 16); std::cout << "Please try again" << std::endl;
				counter++;
			}
		}
		if (counter > 3) {
			system("cls");
			BANK::Design();
			BANK::Color(2);
			BANK::gotoxy(47, 12); std::cout << "You have tried many times" << std::endl;
			BANK::gotoxy(50, 13); std::cout << "Log in is terminated" << std::endl;
			system("pause>0");
			return false;
		}
		system("pause>0");
	} while (true);
	return false;
}