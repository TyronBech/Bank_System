#include"functions.h"

void Deposit(user::Account& User);
void Withdraw(user::Account& User);
void Delete(user::Account& User);

bool BANK::Main_Bank(user::Account& User) {
	unsigned choice = 0;
	do {
		std::cout << "C++ Bank" << std::endl;
		std::cout << "Welcome " << User.get_Name() << std::endl;
		std::cout << "1 - Check Balance" << std::endl;
		std::cout << "2 - Deposit" << std::endl;
		std::cout << "3 - Withdraw" << std::endl;
		std::cout << "4 - Profile" << std::endl;
		std::cout << "5 - Delete account" << std::endl;
		std::cout << "6 - Log out" << std::endl;
		std::cout << "Enter your choice: ";
		std::cin >> choice;
		switch (choice) {
		case 1:
			std::cout << "Balance Section" << std::endl;
			std::cout << "Your current balance: " << User.get_Balance() << std::endl;
			break;
		case 2: Deposit(User);
			break;
		case 3: Withdraw(User);
			break;
		case 4: User.Profile_Info();
			break;
		case 5: return true;
			break;
		case 6: // Exit case
			break;
		default: std::cout << "That is a invalid choice" << std::endl;
		}
	} while (choice != 6);
	return false;
}
// Deposit function is used to let the user deposit certain amount of money
// The deposit function function automatically deduct user's deposit based
// the amount in 5% maximum of 500, it also checks if the deposit is valid or not
void Deposit(user::Account& User) {
	double amount = 0;
	std::cout << "Deposit Section" << std::endl;
	std::cout << "Enter the amount you want deposit: ";
	std::cin >> amount;
	if (amount <= 0) std::cout << "That is a invalid amount" << std::endl;
	else {
		std::cout << "Amount deposit: " << amount << std::endl;
		if (amount > 0 && amount <= 500) User.Add_Balance(amount);
		else if (amount > 500 && amount <= 10000) {
			std::cout << "Deposit charge: " << amount * 0.05 << std::endl;
			User.Add_Balance(amount - (amount * 0.05));
		}
		else {
			std::cout << "Deposit charge: " << static_cast<double>(500) << std::endl;
			User.Add_Balance(amount - static_cast<double>(500));
		}
		std::cout << "Updated balance: " << User.get_Balance() << std::endl;
	}
}
// Withdraw function is used to let the user get a certain amount on his/her account
// This function deducts user's withdrawal based on amount in 5% maximum of 500
// It also checks if the input amount is valid and if the amount is sufficient for
// user's withdrawal
void Withdraw(user::Account& User) {
	double amount;
	std::cout << "Withdraw Section" << std::endl;
	std::cout << "Enter the amount you want to deposit: ";
	std::cin >> amount;
	if (amount <= 0) std::cout << "That is a invalid amount" << std::endl;
	else if (amount > 0 && amount <= 500 && amount > User.get_Balance())
		std::cout << "You have insufficient balance" << std::endl;
	else if (amount > 500 && amount <= 10000 && (amount * 0.05) > User.get_Balance())
		std::cout << "You have insuffient balance" << std::endl;
	else if (amount > 10000 && (amount + 500) > User.get_Balance())
		std::cout << "You have insufficient balance" << std::endl;
	else {
		std::cout << "Amount withdrawn: " << amount << std::endl;
		if (amount > 0 && amount <= 500) User.Deduct_Balance(amount);
		else if (amount > 500 && amount <= 10000) {
			std::cout << "Withdraw charge: " << amount * 0.05 << std::endl;
			User.Deduct_Balance(amount + (amount * 0.05));
		}
		else {
			std::cout << "Withdraw charge: " << static_cast<double>(500) << std::endl;
			User.Deduct_Balance(amount + static_cast<double>(500));
		}
		std::cout << "Updated balance: " << User.get_Balance() << std::endl;
	}
}
void Delete(user::Account& User) {
	std::ofstream outFile;
	std::ifstream inFile;
	std::vector<user::Account> Data;
	BANK::Account_List(0, Data);
	size_t index = BANK::binary_search(Data, User.get_Username());
	if (index < Data.size()) {
		Data.erase(Data.begin() + index);
		BANK::Account_List(1, Data);
	}
	else std::cout << "Cannot Find the username in the database" << std::endl;
}