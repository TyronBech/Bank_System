#include"functions.h"

void Deposit(user::Account& User);
void Withdraw(user::Account& User);
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
		switch (choice) {
		case 0: break;
		case 1:
			BANK::gotoxy(52, 21); std::cout << "Balance Section" << std::endl;
			BANK::gotoxy(48, 22); std::cout << "Your current balance: " << User.get_Balance() << std::endl;
			system("pause>0");
			break;
		case 2: Deposit(User);
			break;
		case 3: Withdraw(User);
			break;
		case 4: User.Profile_Info();
			break;
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
		case 6: // Exit case
			break;
		default: BANK::Color(4);
			BANK::gotoxy(48, 20); std::cout << "That is a invalid choice" << std::endl;
			system("pause>0");
		}
	} while (choice != 6);
	return false;
}
// Deposit function is used to let the user deposit certain amount of money
// The deposit function function automatically deduct user's deposit based
// the amount in 5% maximum of 500, it also checks if the deposit is valid or not
void Deposit(user::Account& User) {
	double amount = 0;
	system("cls");
	BANK::Design(0);
	BANK::Color(2);
	BANK::gotoxy(52, 11); std::cout << "Deposit Section" << std::endl;
	BANK::gotoxy(42, 13); std::cout << "Enter the amount you want deposit: ";
	std::cin >> amount;
	if (amount <= 0) {
		BANK::Color(4);
		BANK::gotoxy(48, 14); std::cout << "That is a invalid amount" << std::endl;
	}
	else {
		BANK::gotoxy(48, 15); std::cout << "Amount deposit: " << amount << std::endl;
		if (amount > 0 && amount <= 500) User.Add_Balance(amount);
		else if (amount > 500 && amount <= 10000) {
			BANK::gotoxy(48, 16); std::cout << "Deposit charge: " << amount * 0.05 << std::endl;
			User.Add_Balance(amount - (amount * 0.05));
		}
		else {
			BANK::gotoxy(48, 16); std::cout << "Deposit charge: " << static_cast<double>(500) << std::endl;
			User.Add_Balance(amount - static_cast<double>(500));
		}
		BANK::gotoxy(48, 17); std::cout << "Updated balance: " << User.get_Balance() << std::endl;
	}
	system("pause>0");
}
// Withdraw function is used to let the user get a certain amount on his/her account
// This function deducts user's withdrawal based on amount in 5% maximum of 500
// It also checks if the input amount is valid and if the amount is sufficient for
// user's withdrawal
void Withdraw(user::Account& User) {
	double amount;
	system("cls");
	BANK::Design(0);
	BANK::Color(2);
	BANK::gotoxy(51, 11); std::cout << "Withdraw Section" << std::endl;
	BANK::gotoxy(42, 13); std::cout << "Enter the amount you want to withdraw: ";
	std::cin >> amount;
	if (amount <= 0) {
		BANK::Color(4);
		BANK::gotoxy(48, 14); std::cout << "That is a invalid amount" << std::endl;
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
	else {
		BANK::gotoxy(48, 15); std::cout << "Amount withdrawn: " << amount << std::endl;
		if (amount > 0 && amount <= 500) User.Deduct_Balance(amount);
		else if (amount > 500 && amount <= 10000) {
			BANK::gotoxy(48, 16); std::cout << "Withdraw charge: " << amount * 0.05 << std::endl;
			User.Deduct_Balance(amount + (amount * 0.05));
		}
		else {
			BANK::gotoxy(48, 16); std::cout << "Withdraw charge: " << static_cast<double>(500) << std::endl;
			User.Deduct_Balance(amount + static_cast<double>(500));
		}
		BANK::gotoxy(48, 17); std::cout << "Updated balance: " << User.get_Balance() << std::endl;
	}
	system("pause>0");
}