#include"functions.h"
#include<conio.h>
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
	char temp_char;
	bool result;
	do {
		system("cls");
		BANK::Design(0);
		BANK::Color(2);
		// Displaying the log in section alongside with the inputs for the user
		BANK::gotoxy(53, 10); std::cout << "Log In Section" << std::endl;
		BANK::gotoxy(48, 12); std::cout << "Enter username: ";
		std::getline(std::cin >> std::ws, input_username);
		BANK::gotoxy(48, 13); std::cout << "Enter a password: ";
		// Every character input it will change into '*' to hide the
		// user's password
		while ((temp_char = _getch()) != 13) {
			if (temp_char == 8) {
				if (!input_pass.empty()) {
					input_pass.pop_back();
					std::cout << "\b \b";
				}
			}
			else {
				input_pass.push_back(temp_char);
				std::cout << '*';
			}
		}
		// This function call will find the index of the account in the vector
		size_t index = BANK::binary_search(Data, input_username);
		// This part will check is the account exist and if the
		// input password is correct
		// This if statement used if there is no the correct username found in the vector
		if (index == -1) {
			BANK::Color(4);
			BANK::gotoxy(43, 15); std::cout << "Sorry there is no existing account" << std::endl;
			BANK::gotoxy(47, 16); std::cout << "Please try another account" << std::endl;
			counter++;
		}
		// If the log in is successful, the program will direct the user to the Main_Bank function
		else {
			if (input_pass == Data[index].get_Password()) {
				result = BANK::Main_Bank(Data[index]);
				// If the result is true, it means that the user wants to delete the account
				// The the program will delete it using the Delete function
				if (result) {
					BANK::Delete(Data, Data[index]);
				}
				// Account_List is called for retrieving the updated accounts in the csv file
				BANK::Account_List(0, Data);
				return true;
			}
			// If the username exists but the password is correct, it will display incorrect text
			// then let the user try again
			else {
				BANK::Color(4);
				BANK::gotoxy(44, 15); std::cout << "The input password is incorrect" << std::endl;
				BANK::gotoxy(52, 16); std::cout << "Please try again" << std::endl;
				counter++;
			}
		}
		// Once the user fail 3x, the log in will terminate and back to the main menu
		if (counter > 3) {
			system("cls");
			BANK::Design(0);
			BANK::Color(4);
			BANK::gotoxy(47, 12); std::cout << "You have tried many times" << std::endl;
			BANK::gotoxy(50, 13); std::cout << "Log in is terminated" << std::endl;
			system("pause>0");
			return false;
		}
		system("pause>0");
	} while (true);
	return false;
}