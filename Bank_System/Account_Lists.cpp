#include"functions.h"

// Declared functions. All the initialization is below the
// Account_List function
std::vector<user::Account> Retrieve();
void Rewrite(std::vector<user::Account>& user);
// Delete function is used to delete an existing account to the csv file
// It is independent to the other functions of Account_Lists.cpp because
// of different approach on function calling
void BANK::Delete(std::vector<user::Account>& Data, user::Account User) {
	size_t index = BANK::binary_search(Data, User.get_Username());
	if (index < Data.size()) {
		Data.erase(Data.begin() + index);
		BANK::Account_List(1, Data);
	}
	else std::cout << "Cannot Find the username in the database" << std::endl;
}
// Account_List is a function that handle account in the csv file
// it retrieve and rewrite the contents of the csv file
// It also help the delete function to delete certain account in the csv file
void BANK::Account_List(unsigned flag, std::vector<user::Account>& List_of_Accounts) {
	switch (flag) {
		// Retrieve all the contents/Accounts inside the csv file
	case 0: List_of_Accounts = Retrieve();
		break;
		// Append an account to csv file
	case 1: Rewrite(List_of_Accounts);
		break;
	}
}
std::vector<user::Account> Retrieve() {
	// Retrieve all the contents/Accounts inside the csv file
	std::vector<user::Account> Users;
	// Temporary Account object
	user::Account user;
	std::ifstream inFile;
	std::string line;
	// Temporary variables
	std::string name = "", gender = "", birthdate = "";
	std::string username = "", userpass = "";
	unsigned age = 0, id = 0, i = 0;
	double balance = 0;
	char dash;
	inFile.open("Account_Lists.csv", std::ios::in);
	if (inFile.is_open()) {
		while (std::getline(inFile, line)) {
			std::stringstream ss(line);
			// Extract all the contents of the line
			std::getline(ss, name, ',');
			ss >> age >> dash;
			std::getline(ss, gender, ',');
			std::getline(ss, birthdate, ',');
			ss >> id >> dash;
			std::getline(ss, username, ',');
			std::getline(ss, userpass, ',');
			ss >> balance;
			// Insert the extracted values in the temp Account
			user.set_Name(name);
			user.set_Age(age);
			user.set_Gender(gender);
			user.set_Birthdate(birthdate);
			user.set_ID(id);
			user.set_Username(username);
			user.set_Password(userpass);
			user.set_Balance(balance);
			// Push the temp Account to the vector of Accounts
			Users.push_back(user);
		}
	}
	return Users;
}
// This function is used to append an added account and rewrite all to the csv file
void Rewrite(std::vector<user::Account>& user) {
	std::ofstream outFile;
	outFile.open("Account_Lists.csv", std::ios::out | std::ios::trunc);
	if (outFile.is_open()) {
		outFile.close();
		outFile.open("Account_Lists.csv", std::ios::app);
		if (outFile.is_open()) {
			for (size_t i = 0; i < user.size(); i++) {
				outFile << user[i].get_Name() << ',' << user[i].get_Age() << ','
					<< user[i].get_Gender() << ',' << user[i].get_Birthdate() << ','
					<< user[i].get_ID() << ',' << user[i].get_Username() << ','
					<< user[i].get_Password() << ',' << user[i].get_Balance() << '\n';
			}
		}
		else std::cerr << "The file did not open" << std::endl;
		outFile.close();
	}
	else std::cerr << "The file did not open" << std::endl;
	outFile.close();
}