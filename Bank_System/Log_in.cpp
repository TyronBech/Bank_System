#include"functions.h"

// Declaration of the functions. All the initialization are located
// below the Log_in function
size_t partition(std::vector<user::Account>& arr, size_t low, size_t high);
void quicksort(std::vector<user::Account>& arr, size_t low, size_t high);
size_t binary_search(std::vector<user::Account> arr, const std::string target);
/// <summary>
/// Log_in function is used to let the user log to his/her account
/// it will check if the input username and password exists in the 
/// vector and if the input is correct
/// </summary>
/// <param name="Data"> Data is where the Accounts is stored </param>
bool BANK::Log_in(std::vector<user::Account>& Data) {
	std::string input_username = "", input_pass = "";
	unsigned counter = 1;
	quicksort(Data, 0, Data.size() - 1);
	do {
		std::cout << "Log In Section" << std::endl;
		std::cout << "Enter username: ";
		std::getline(std::cin >> std::ws, input_username);
		std::cout << "Enter a password: ";
		std::getline(std::cin >> std::ws, input_pass);
		size_t index = binary_search(Data,input_username);
		if (index == -1) {
			std::cout << "Sorry there is no existing account" << std::endl;
			std::cout << "Please try another account" << std::endl;
		}
		else {
			if (input_pass == Data[index].get_Password()) {
				BANK::Main_Bank(Data[index]);
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
// partition function is used to sort actiually the quicksort based on pivot
size_t partition(std::vector<user::Account>& arr, size_t low, size_t high) {
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

// it is used to sort the vector of account for the binary search
void quicksort(std::vector<user::Account>& arr, size_t low, size_t high) {
	if (low < high) {
		size_t pivot = partition(arr, low, high);
		quicksort(arr, low, pivot - 1);
		quicksort(arr, pivot + 1, high);
	}
}
// The binary search will help minimize the search time
// The parameter arr will be the vector handling all the accounts to find
// target is the searching point of the function if there is no equality
// it will return false
// returns boolean either true is the function found the target or
// false if it doesn't
size_t binary_search(std::vector<user::Account> arr, const std::string target) {
	size_t low = 0, high = arr.size() - 1;
	while (low <= high) {
		size_t mid = low + (high - low) / 2;
		if (arr[mid].get_Username() == target) return mid;
		else if (arr[mid].get_Username() < target) low = mid + 1;
		else high = mid - 1;
	}
	return -1;
}