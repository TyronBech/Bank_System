#include"functions.h"
#include<iomanip>
// Declared variables, initialized below the main function
// of this .cpp file
void Deposit(user::Account& User);
void Withdraw(user::Account& User);
std::string amount_view(double amount);
bool Valid_amount(std::string& amount);
void Copy_CSV_balance(user::Account& User);
// Main_Bank is a function to do the transactions
// User can deposit, withdraw, check balance, view
// profile, and delete an account
// The function is called only if log_in is successful
bool BANK::Main_Bank(user::Account& User) {
	unsigned choice = 0;
	do {
		system("cls");
		BANK::Design(0);
		BANK::Color(2);
		// Displaying the menu to he users alongside with input choice
		BANK::gotoxy(56, 10);  std::cout << "C++ Bank" << std::endl;
		BANK::gotoxy((119 - (8 + static_cast<short>(User.get_Name().length()))) / 2, 11);
		std::cout << "Welcome " << User.get_Name() << std::endl;
		BANK::gotoxy(48, 13); std::cout << "1 - Check Balance" << std::endl;
		BANK::gotoxy(48, 14); std::cout << "2 - Deposit" << std::endl;
		BANK::gotoxy(48, 15); std::cout << "3 - Withdraw" << std::endl;
		BANK::gotoxy(48, 16); std::cout << "4 - Profile" << std::endl;
		BANK::gotoxy(48, 17); std::cout << "5 - Delete account" << std::endl;
		BANK::gotoxy(48, 18); std::cout << "6 - Log out" << std::endl;
		BANK::gotoxy(48, 19); std::cout << "Enter your choice: ";
		choice = BANK::Try_catch_int(static_cast<long long>(choice));
		// Switch case to specifically run chosen function
		switch (choice) {
		// Case 0 is used if the user did not choose any of the
		// available choices
		case 0: break;
		// Case 1 for displaying the current balance of the user
		case 1:
			BANK::gotoxy(53, 21); std::cout << "Balance Section" << std::endl;
			BANK::gotoxy(48, 22); std::cout << "Your current balance: " << amount_view(User.get_Balance()) << std::endl;
			system("pause>0");
			break;
		// Case 2 for running the Deposit function
		// and perform deposit transaction 
		case 2: Deposit(User);
			break;
		// Case 3 for running the withdrawal function
		// and perform withdrawal transaction
		case 3: Withdraw(User);
			break;
		// Case 4 is for displaying the information of the user
		case 4: User.Profile_Info();
			break;
		// Case 5 is for deleting the account
		// Account can only be deleted if user satisfy the requirements
		// of deleting the account with 50 or less balance on account
		case 5: if (User.get_Balance() >= 50) {
			BANK::Color(4);
			BANK::gotoxy(44, 21); std::cout << "You still have 50 or above amount" << std::endl;
			BANK::gotoxy(42, 22); std::cout << "in the account, cannot delete account" << std::endl;
			system("pause>0");
			}
			else {
			return true;
			}
			break;
		// Case 6 for exit case, the menu will go bank to main menu
		case 6: // Exit case
			break;
		// Default for invalid input of the user
		default: BANK::Color(4);
			BANK::gotoxy(48, 20); std::cout << "That is a invalid choice" << std::endl;
			system("pause>0");
		}
		// Every loop, the Copy_CSV_balance function is called
		// to rewrite the contents of the accounts alongside
		// with updated balance of the user
		Copy_CSV_balance(User);
	} while (choice != 6);
	return false;
}
// Deposit function is used to let the user deposit certain amount of money
// The deposit function function automatically deduct user's deposit based
// the amount in 5% maximum of 500, it also checks if the deposit is valid or not
void Deposit(user::Account& User) {
	double amount = 0;
	std::string temp_amount = "";
	system("cls");
	BANK::Design(0);
	BANK::Color(2);
	// Displaying the input section for deposit
	BANK::gotoxy(52, 11); std::cout << "Deposit Section" << std::endl;
	BANK::gotoxy(42, 13); std::cout << "Enter the amount you want deposit: ";
	std::cin >> temp_amount;
	// Before depositing the balance, it will be checked by the
	// Valid_amount function to check if the input amount is valid
	bool result = Valid_amount(temp_amount);
	if (!result) {
		BANK::Color(4);
		BANK::gotoxy(41, 15); std::cout << "The input amount contains character" << std::endl;
		BANK::gotoxy(48, 16); std::cout << "Please try valid amount" << std::endl;
		system("pause>0");
		return;
	}
	// If valid it will be checked again if the amount is negative or 0
	else {
		amount = std::stod(temp_amount);
		if (amount <= 0) {
			BANK::Color(4);
			BANK::gotoxy(48, 14); std::cout << "That is a invalid amount" << std::endl;
		}
		else if (amount > 50000) {
			BANK::gotoxy(33, 15); std::cout << "You cannot deposit more the 50,000 in one transaction" << std::endl;
			BANK::gotoxy(48, 16); std::cout << "Please try below 50,000" << std::endl;
		}
		// If nothing became true in conditions above
		// it will be deposited successfully with automatic
		// deduction of charge based on the amount of deposit
		else {
			BANK::gotoxy(48, 15); std::cout << "Amount deposit: " << amount_view(amount) << std::endl;
			if (amount > 0 && amount <= 500) User.Add_Balance(amount);
			else if (amount > 500 && amount <= 10000) {
				BANK::gotoxy(48, 16); std::cout << "Deposit charge: " << amount * 0.05 << std::endl;
				User.Add_Balance(amount - (amount * 0.05));
			}
			else {
				BANK::gotoxy(48, 16); std::cout << "Deposit charge: " << static_cast<double>(500) << std::endl;
				User.Add_Balance(amount - static_cast<double>(500));
			}
			BANK::gotoxy(48, 17); std::cout << "Updated balance: " << amount_view(User.get_Balance()) << std::endl;
		}
	}
	system("pause>0");
}
// Withdraw function is used to let the user get a certain amount on his/her account
// This function deducts user's withdrawal based on amount in 5% maximum of 500
// It also checks if the input amount is valid and if the amount is sufficient for
// user's withdrawal
void Withdraw(user::Account& User) {
	double amount;
	std::string temp_amount = "";
	system("cls");
	BANK::Design(0);
	BANK::Color(2);
	// Displaying the input section for withdrawal
	BANK::gotoxy(51, 11); std::cout << "Withdraw Section" << std::endl;
	BANK::gotoxy(42, 13); std::cout << "Enter the amount you want to withdraw: ";
	std::cin >> temp_amount;
	// Before withdrawing the balance, it will be checked by the
	// Valid_amount function to check if the input amount is valid
	bool result = Valid_amount(temp_amount);
	if (!result) {
		BANK::Color(4);
		BANK::gotoxy(41, 15); std::cout << "The input amount contains character" << std::endl;
		BANK::gotoxy(48, 16); std::cout << "Please try valid amount" << std::endl;
		system("pause>0");
		return;
	}
	// If there is not invalid characters in the amount
	// it will be checked if the amount is valid based on
	// input, current balance, and total amount of withdrawal
	// plus the charge
	else {
		amount = std::stod(temp_amount);
		if (amount <= 0) {
			BANK::Color(4);
			BANK::gotoxy(48, 14); std::cout << "That is a invalid amount" << std::endl;
		}
		else if (amount > 50000) {
			BANK::gotoxy(32, 15); std::cout << "You cannot withdraw more the 50,000 in one transaction" << std::endl;
			BANK::gotoxy(48, 16); std::cout << "Please try below 50,000" << std::endl;
		}
		else if (amount > 0 && amount <= 500 && amount > User.get_Balance()) {
			BANK::Color(4);
			BANK::gotoxy(48, 14); std::cout << "You have insufficient balance" << std::endl;
		}
		else if (amount > 500 && amount <= 10000 && amount + (amount * 0.05) > User.get_Balance()) {
			BANK::Color(4);
			BANK::gotoxy(48, 14); std::cout << "You have insuffient balance" << std::endl;
		}
		else if (amount > 10000 && (amount + 500) > User.get_Balance()) {
			BANK::Color(4);
			BANK::gotoxy(48, 14); std::cout << "You have insufficient balance" << std::endl;
		}
		// If nothing became true in conditions above
		// it will be withdrawn successfully with automatic
		// deduction of charge based on the amount of withdrawal
		else {
			BANK::gotoxy(48, 15); std::cout << "Amount withdrawn: " << amount_view(amount) << std::endl;
			if (amount > 0 && amount <= 500) User.Deduct_Balance(amount);
			else if (amount > 500 && amount <= 10000) {
				BANK::gotoxy(48, 16); std::cout << "Withdraw charge: " << amount * 0.05 << std::endl;
				User.Deduct_Balance(amount + (amount * 0.05));
			}
			else {
				BANK::gotoxy(48, 16); std::cout << "Withdraw charge: " << static_cast<double>(500) << std::endl;
				User.Deduct_Balance(amount + static_cast<double>(500));
			}
			BANK::gotoxy(48, 17); std::cout << "Updated balance: " << amount_view(User.get_Balance()) << std::endl;
		}
	}
	system("pause>0");
}
/// <summary>
/// This function creates a easy way to read the amount or balance
/// as it put ',' comma in each 3 digits of the numbers
/// </summary>
/// <param name="amount">
/// The parameter is the user balance
/// </param>
/// <returns>
/// it returns the updated format of the amount in string data type
/// </returns>
std::string amount_view(double amount) {
	std::stringstream stream;
	stream << std::fixed << std::setprecision(2) << amount;
	std::string str_amount = stream.str();
	size_t pos = str_amount.find('.');
	int num_of_digits = pos == std::string::npos ? static_cast<int>(str_amount.length())
		: static_cast<int>(pos);
	for (int i = num_of_digits - 3; i > 0; i -= 3) {
		str_amount.insert(i, ",");
	}
	return str_amount;
}
/// <summary>
/// This function checks if the input amount is valid
/// It checks if the amounts contain any non-integral
/// characters or not
/// </summary>
/// <param name="amount">
/// The amount parameter is the input amount of the user
/// </param>
/// <returns>
/// it will return true if it catches any characters else false
/// </returns>
bool Valid_amount(std::string& amount) {
	std::stringstream ss(amount);
	double gotAmount = 0.00;
	char character;
	if (ss >> gotAmount && !(ss >> character)) {
		return true;
	}
	return false;
}
/// <summary>
/// This function is going to retrieve the contents of the 
/// csv file and rewrite the contents with updated balance
/// on user's account
/// </summary>
/// <param name="User"></param>
void Copy_CSV_balance(user::Account& User) {
	std::vector<user::Account> Users;
	BANK::Account_List(0, Users);
	size_t index = BANK::binary_search(Users, User.get_Username());
	Users[index].set_Balance(User.get_Balance());
	BANK::Account_List(1, Users);
}