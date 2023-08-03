#include"functions.h"

// partition function is used to sort actiually the quicksort based on pivot
size_t BANK::partition(std::vector<user::Account>& arr, size_t low, size_t high) {
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
void BANK::quicksort(std::vector<user::Account>& arr, size_t low, size_t high) {
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
size_t BANK::binary_search(std::vector<user::Account> arr, const std::string target) {
	size_t low = 0, high = arr.size() - 1;
	while (low <= high) {
		size_t mid = low + (high - low) / 2;
		if (arr[mid].get_Username() == target) return mid;
		else if (arr[mid].get_Username() < target) low = mid + 1;
		else high = mid - 1;
	}
	return -1;
}