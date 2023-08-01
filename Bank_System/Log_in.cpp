#include"functions.h"

// Declaration of the functions. All the initialization are located
// below the Log_in function
size_t partition(std::vector<user::Account>& arr, size_t low, size_t high, int flag);
void quicksort(std::vector<user::Account>& arr, size_t low, size_t high, int flag);
bool binary_search(std::vector<user::Account> arr, const std::string target, int flag);
/// <summary>
/// Log_in function is used to let the user log to his/her account
/// it will check if the input username and password exists in the 
/// vector and if the input is correct
/// </summary>
/// <param name="Data"> Data is where the Accounts is stored </param>
/// <returns> return true if log in is successful false if not </returns>
bool BANK::Log_in(std::vector<user::Account>& Data) {
	std::string input_username = "", input_pass = "";
	unsigned counter = 1;
	// created a copy of account to sort based on usernames
	std::vector<user::Account> sorted_username(Data);
	quicksort(sorted_username, 0, sorted_username.size() - 1, 0);
	// created a copy of account to sort based on passwords
	std::vector<user::Account> sorted_password(Data);
	quicksort(sorted_password, 0, sorted_password.size() - 1, 1);
	do {
		std::cout << "Log In Section" << std::endl;
		std::cout << "Enter username: ";
		std::getline(std::cin >> std::ws, input_username);
		std::cout << "Enter a password: ";
		std::getline(std::cin >> std::ws, input_pass);
		// This for loop is going the check the user's input
		// and compare to the existing account in the vector one by one
		// In if statement we use the binary search to help the searching
		// and lessen the unecessary search
		for (size_t i = 0; i < Data.size(); i++) {
			if (binary_search(sorted_username, input_username, 0) &&
				binary_search(sorted_password, input_pass, 1)) return true;
		}
		size_t flag = 0;
		for (size_t i = 0; i < Data.size(); i++) {
			if (binary_search(sorted_username, input_username, 0) &&
				!binary_search(sorted_password, input_pass, 1)) {
				std::cout << "Wrong password" << std::endl;
				std::cout << "Please try again" << std::endl;
				break;
			}
			else if (!binary_search(sorted_username, input_username, 0) &&
				binary_search(sorted_password, input_pass, 1)) {
				std::cout << "Wrong username" << std::endl;
				std::cout << "Please try again" << std::endl;
				break;
			}
			// if the searching come out false in all iteration, the flag will be
			// equal to the size of the vector and signal that the user's input
			// or account does not exist in the vector of accounts
			if (flag = Data.size()) {
				std::cout << "The input account does not exist" << std::endl;
				std::cout << "Please try another account" << std::endl;
				return false;
			}
			flag++;
		}
		// If the user fail to get the correct account in 3 time, the log in will terminate
		if (counter > 3) {
			std::cout << "You have tried moultiple times and failed" << std::endl;
			std::cout << "Log in terminated" << std::endl;
			return false;
		}
		counter++;
	} while (true);
	return false;
}
// partition function is used to sort actiually the quicksort based on pivot
size_t partition(std::vector<user::Account>& arr, size_t low, size_t high, int flag) {
	if (flag == 0) {
		std::string pivot = arr[high].get_Username();
		size_t i = low - 1;

		for (size_t j = low; j < high; j++) {
			if (arr[j].get_Username() < pivot) {
				i++;
				std::swap(arr[i], arr[j]);
			}
		}
		std::swap(arr[i + 1], arr[high]);
		return i + 1;
	}
	else {
		std::string pivot = arr[high].get_Password();
		size_t i = low - 1;

		for (size_t j = low; j < high; j++) {
			if (arr[j].get_Password() < pivot) {
				i++;
				std::swap(arr[i], arr[j]);
			}
		}
		std::swap(arr[i + 1], arr[high]);
		return i + 1;
	}
	return 0;
}

// it is used to sort the vector of account for the binary search
// the flag is used to identify if the whether the part of the vector
// to be sorted is username based or password
void quicksort(std::vector<user::Account>& arr, size_t low, size_t high, int flag) {
	if (low < high) {
		size_t pivot = partition(arr, low, high, flag);
		quicksort(arr, low, pivot - 1, flag);
		quicksort(arr, pivot + 1, high, flag);
	}
}
// The binary search will help minimize the search time
// The parameter arr will be the vector handling all the accounts to find
// target is the searching point of the function if there is no equality
// it will return false
// flag is used to identify of the search is for username or password
// returns boolean either true is the function found the target or
// false if it doesn't
bool binary_search(std::vector<user::Account> arr, const std::string target, int flag) {
	size_t low = 0, high = arr.size() - 1;
	if(flag == 0)
		while (low <= high) {
			size_t mid = low + (high - low) / 2;
			if (arr[mid].get_Username() == target) return true;
			else if (arr[mid].get_Username() < target) low = mid + 1;
			else high = mid - 1;
		}
	else
		while (low <= high) {
			size_t mid = low + (high - low) / 2;
			if (arr[mid].get_Password() == target) return true;
			else if (arr[mid].get_Password() < target) low = mid + 1;
			else high = mid - 1;
		}
	return false;
}