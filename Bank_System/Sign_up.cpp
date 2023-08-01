#include"functions.h"

// This function is used to check if the user input a
// non-alphabetic character to his/her name
bool Name_checker(const std::string name) {
	for (size_t i = 0; i < name.length(); i++) {
		if (isalpha(name[i])) continue;
		else if (name[i] == ' ') continue;
		else return false;
	}
	return true;
}
// Initialization of the method Sign_up from Account
std::tuple<bool, user::Account> BANK::Sign_up() {
	std::string name = "";
	bool set = false, succeed = false, set_name = false;
	user::Account User;
	// counter variable to identify how many fails does
	// user done, if more than 3 the Sign_up section will terminate
	// the counter resets in each inputs
	unsigned counter = 1;
	// This is the part where user input his/her information
	std::cout << "Sign Up Section" << std::endl;
	do {
		std::cout << "Enter your name: ";
		std::getline(std::cin >> std::ws, name);
		set_name = Name_checker(name);
		if (!set_name) {
			std::cout << "Your name contains non-alphabetic characters" << std::endl;
			std::cout << "Please try again" << std::endl;
			counter++;
		}
		else break;
		if (counter > 3) return std::make_tuple(false, User);
	} while (true);
	counter = 1;
	// Lambda function to setup user's birthdate
	unsigned age = 0;
	std::string birthdate = "";
	auto set_birthdate = [&birthdate, &age, &counter]() -> bool {
		// variables needed for setting the user's birthdate
		time_t now = time(0);
		std::tm Local_Time;
		if (localtime_s(&Local_Time, &now) != 0) {
			std::cerr << "Error: Local Time failed" << std::endl;
			return false;
		}
		signed day, month, year;
		char dash = '-', input_dash;
		do {
			std::cout << "Ex: 01-02-2003" << std::endl;
			std::cout << "Enter your birthdate(dd/mm/yyy): ";
			// input inside if statement will help to extract the input of the user
			// in proper format
			if (std::cin >> day && day <= 31 && day >= 1 &&
				std::cin >> input_dash && input_dash == dash &&
				std::cin >> month && month > 0 && month < 13 &&
				std::cin >> input_dash && input_dash == dash &&
				std::cin >> year && year >= 1900 && year < (Local_Time.tm_year + 1900)) {
				std::string Months[] = {
					"", "January", "Febuary", "March", "April",
					"May", "June", "July", "August",
					"September", "October", "November", "December"
				};
				// The ostringstream will stitch the date together and
				// will be inserted in birthdate variable
				std::ostringstream oss;
				oss << Months[month] << ' ' << day << ' ' << year;
				birthdate = oss.str();
				age = (Local_Time.tm_year + 1900) - year;
				if (month > (Local_Time.tm_mon + 1) ||
					(month == (Local_Time.tm_mon + 1) && day > Local_Time.tm_mday)) age--;
				return true;
			}
			// If the user did not satify the requirements, it won't bind
			// the input dates together and user will input the date again
			else {
				std::cout << "You entered a birthdate in wrong format" << std::endl;
				std::cout << "Please try again" << std::endl;
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				counter++;
			}
			if (counter > 3) return false;
		} while (true);
		return false;
	};
	set = set_birthdate();
	if (!set) return std::make_tuple(false, User);
	counter = 1;
	char gender;
	do {
		std::cout << "Enter your gender:" << std::endl;
		std::cout << "A. Male" << std::endl;
		std::cout << "B. Female" << std::endl;
		std::cout << "C. LGBTQ+" << std::endl;
		std::cout << "Enter your choice: ";
		std::cin >> gender;
		gender = toupper(gender);
		if (gender != 'A' && gender != 'B' && gender != 'C') {
			std::cout << "That is a invalid choice" << std::endl;
			std::cout << "Please try again" << std::endl;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			counter++;
		}
		else break;
		if (counter > 3) return std::make_tuple(false, User);
	} while (true);
	// Username and password input
	std::string username = "", userpass = "";
	std::cout << "Enter a username: ";
	std::getline(std::cin >> std::ws, username);
	std::cout << "Enter a password: ";
	std::getline(std::cin >> std::ws, userpass);
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
