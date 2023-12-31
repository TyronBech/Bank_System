#include"functions.h"
#include<conio.h>
// This function is used to check if the user input a
// non-alphabetic character to his/her name
bool Name_checker(const std::string name) {
	for (size_t i = 0; i < name.length(); i++) {
		if (isalpha(name[i])) continue;
		else if (name[i] == ' ') continue;
		else if (name[i] == '.') continue;
		else return false;
	}
	return true;
}
/// <summary>
/// This Sign_up function will be the input account of the user
/// it let the user to input necessary information
/// </summary>
/// <param name="Users">
/// Users is a parameter for finding existing username
/// that stops user from repeating the same username
/// </param>
/// <returns>
/// returns a boolean the identify if successful then will also
/// return User based on boolean value
/// </returns>
std::tuple<bool, user::Account> BANK::Sign_up(std::vector<user::Account>& Users) {
	std::string name = "";
	bool set = false, succeed = false, set_name = false;
	user::Account User;
	// counter variable to identify how many fails does
	// user done, if more than 3 the Sign_up section will terminate
	// the counter resets in each inputs
	unsigned counter = 1;
	// This is the part where user input his/her information
	do {
		system("cls");
		BANK::Design(0);
		BANK::Color(2);
		// This part is for user's name
		BANK::gotoxy(52, 10); std::cout << "Sign Up Section" << std::endl;
		BANK::gotoxy(48, 12); std::cout << "Enter your name: ";
		std::getline(std::cin >> std::ws, name);
		set_name = Name_checker(name);
		if (!set_name) {
			BANK::Color(4);
			BANK::gotoxy(37, 14); std::cout << "Your name contains non-alphabetic characters" << std::endl;
			BANK::gotoxy(51, 15); std::cout << "Please try again" << std::endl;
			counter++;
			system("pause>0");
		}
		else break;
		if (counter > 3) return std::make_tuple(false, User);
	} while (true);
	counter = 1;
	unsigned age = 0;
	std::string birthdate = "";
	// Lambda function to setup user's birthdate
	auto set_birthdate = [&birthdate, &age, &counter]() -> bool {
		// variables needed for setting the user's birthdate
		time_t now = time(0);
		std::tm Local_Time;
		if (localtime_s(&Local_Time, &now) != 0) {
			system("cls");
			BANK::Design(0);
			BANK::Color(4);
			BANK::gotoxy(47, 11); std::cerr << "Error: Local Time failed" << std::endl;
			system("pause>0");
			return false;
		}
		signed day, month, year;
		char dash = '-', input_dash;
		do {
			system("cls");
			BANK::Design(0);
			BANK::Color(2);
			BANK::gotoxy(52, 10); std::cout << "Sign Up Section" << std::endl;
			BANK::gotoxy(48, 12); std::cout << "Ex: 01-02-2003" << std::endl;
			BANK::gotoxy(48, 13); std::cout << "Enter your birthdate(dd/mm/yyy): ";
			// input inside if statement will help to extract the input of the user
			// in proper format
			if (std::cin >> day && day <= 31 && day >= 1 &&
				std::cin >> input_dash && input_dash == dash &&
				std::cin >> month && month > 0 && month < 13 &&
				std::cin >> input_dash && input_dash == dash &&
				std::cin >> year && year >= 1900 && year < (Local_Time.tm_year + 1900)) {
				std::string Months[] = {
					"", "January", "February", "March", "April",
					"May", "June", "July", "August",
					"September", "October", "November", "December"
				};
				// The ostringstream will stitch the date together and
				// will be inserted in birthdate variable
				std::ostringstream oss;
				oss << Months[month] << ' ' << day << ' ' << year;
				birthdate = oss.str();
				// Setting the age based on birthdate
				age = static_cast<unsigned>(Local_Time.tm_year + 1900) - year;
				if (month > (Local_Time.tm_mon + 1) ||
					(month == (Local_Time.tm_mon + 1) && day > Local_Time.tm_mday)) age--;
				return true;
			}
			// If the user did not satisfy the requirements, it won't bind
			// the input dates together and user will input the date again
			else {
				BANK::Color(4);
				BANK::gotoxy(40, 15); std::cout << "You entered a birthdate in wrong format" << std::endl;
				BANK::gotoxy(52, 16); std::cout << "Please try again" << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				counter++;
			}
			if (counter > 3) return false;
			system("pause>0");
		} while (true);
		return false;
	};
	// lambda function call for birthdate
	set = set_birthdate();
	if (!set) return std::make_tuple(false, User);
	counter = 1;
	char gender;
	do {
		// User will choose one of the available genders including LGBTQ+
		system("cls");
		BANK::Design(0);
		BANK::Color(2);
		// Displaying the available options for user's gender
		BANK::gotoxy(52, 10); std::cout << "Sign Up Section" << std::endl;
		BANK::gotoxy(48, 12); std::cout << "Enter your gender:" << std::endl;
		BANK::gotoxy(48, 13); std::cout << "A. Male" << std::endl;
		BANK::gotoxy(48, 14); std::cout << "B. Female" << std::endl;
		BANK::gotoxy(48, 15); std::cout << "C. LGBTQ+" << std::endl;
		BANK::gotoxy(48, 16); std::cout << "Enter your choice: ";
		std::cin >> gender;
		gender = toupper(gender);
		// Checking if the user's input is valid
		if (gender != 'A' && gender != 'B' && gender != 'C') {
			BANK::Color(4);
			BANK::gotoxy(48, 17); std::cout << "That is a invalid choice" << std::endl;
			BANK::gotoxy(48, 18); std::cout << "Please try again" << std::endl;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			counter++;
		}
		else break;
		if (counter > 3) return std::make_tuple(false, User);
		system("pause>0");
	} while (true);
	// Username and password input
	std::string username = "", userpass = "";
	size_t result = -1;
	counter = 1;
	do {
		system("cls");
		BANK::Design(0);
		BANK::Color(2);
		// Entering the username of the user
		BANK::gotoxy(52, 10); std::cout << "Sign Up Section" << std::endl;
		BANK::gotoxy(48, 12); std::cout << "Enter a username: ";
		std::getline(std::cin >> std::ws, username);
		result = BANK::binary_search(Users, username);
		// If the input username has the same username in the existing accounts
		// it will notify the user, and letting him/her to try again
		if (result != -1) {
			BANK::Color(4);
			BANK::gotoxy(43, 14); std::cout << "The username is already been taken" << std::endl;
			BANK::gotoxy(46, 15); std::cout << "Please try another username" << std::endl;
			counter++;
			system("pause>0");
		}
		else break;
		if (counter > 3) return std::make_tuple(false, User);
	} while (true);
	// Entering for user's password
	BANK::gotoxy(48, 13); std::cout << "Enter a password: ";
	char temp_char;
	// While typing the password, the characters will change into '*'
	// to hide the user's password
	while ((temp_char = _getch()) != 13) {
		if (temp_char == 8) {
			if (!userpass.empty()) {
				userpass.pop_back();
				std::cout << "\b \b";
			}
		}
		else {
			userpass.push_back(temp_char);
			std::cout << '*';
		}
	}
	succeed = true;
	// If the input succeeded all the information stored in the
	// temporary variables will be stored in the Account User
	if (succeed) {
		User.set_Name(name);
		User.set_Age(age);
		switch (gender) {
		case 'A': User.set_Gender("Male");
			break;
		case 'B': User.set_Gender("Female");
			break;
		case 'C': User.set_Gender("LGBTQ+");
			break;
		}
		User.set_Birthdate(birthdate);
		User.set_Username(username);
		User.set_Password(userpass);
		// Random ID number generator
		std::random_device rand;
		std::mt19937 generator(rand());
		unsigned min = 10000000, max = 99999999;
		std::uniform_int_distribution<unsigned> distribution(min, max);
		User.set_ID(distribution(generator));
		return std::make_tuple(true, User);
	}
	return std::make_tuple(false, User);
}