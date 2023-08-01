#include"functions.h"

size_t partition(std::vector<user::Account>& arr, size_t low, size_t high, int flag);
void quicksort(std::vector<user::Account>& arr, size_t low, size_t high, int flag);
bool binary_search(std::vector<user::Account> arr, const std::string target, int flag);

bool BANK::Log_in(std::vector<user::Account>& Data) {
	std::string input_username = "", input_pass = "";
	unsigned counter = 1;
	std::vector<user::Account> sorted_username(Data);
	quicksort(sorted_username, 0, sorted_username.size() - 1, 0);
	std::vector<user::Account> sorted_password(Data);
	quicksort(sorted_password, 0, sorted_password.size() - 1, 1);
	do {
		std::cout << "Log In Section" << std::endl;
		std::cout << "Enter username: ";
		std::getline(std::cin >> std::ws, input_username);
		std::cout << "Enter a password: ";
		std::getline(std::cin >> std::ws, input_pass);
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
			if (flag = Data.size()) {
				std::cout << "The input account does not exist" << std::endl;
				std::cout << "Please try another account" << std::endl;
				return false;
			}
			flag++;
		}
		if (counter > 3) {
			std::cout << "You have tried moultiple times and failed" << std::endl;
			std::cout << "Log in terminated" << std::endl;
			return false;
		}
		counter++;
	} while (true);
	return false;
}
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
void quicksort(std::vector<user::Account>& arr, size_t low, size_t high, int flag) {
	if (low < high) {
		size_t pivot = partition(arr, low, high, flag);
		quicksort(arr, low, pivot - 1, flag);
		quicksort(arr, pivot + 1, high, flag);
	}
}
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