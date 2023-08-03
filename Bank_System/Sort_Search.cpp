#include"functions.h"

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
// The sorting method is changed from quicksort to bubble sort because of 
// vector related issues, bubble sort chosen since number of accounts
// is not big for efficient sorting
void BANK::BubbleSort(std::vector<user::Account>& User) {
	for (size_t i = 0; i < User.size(); i++) {
		for(size_t j = 0; j < User.size() - 1; j++) {
			if (User[j].get_Username() > User[j + 1].get_Username()) {
				user::Account temp = User[j];
				User[j] = User[j + 1];
				User[j + 1] = temp;
			}
		}
	}
}