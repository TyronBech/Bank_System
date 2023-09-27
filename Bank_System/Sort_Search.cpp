#include"functions.h"

/// <summary>
/// This function will find the index of the sorted accounts in the vector
/// </summary>
/// <param name="arr">
/// arr parameter is the vector of accounts
/// </param>
/// <param name="target">
/// target is the username as argument that is going to find if existing
/// in the vector
/// </param>
/// <returns>
/// It will return the index of the username if found else -1 if not
/// </returns>
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
/// <summary>
/// The Bubble sort is going to sort the vector of accounts alphabetically
/// based on usernames of the users.
/// </summary>
/// <param name="User">
/// User is the passed vector argument that is going to be sorted by the function
/// </param>
void BANK::BubbleSort(std::vector<user::Account>& User) {
	for (size_t i = 0; i < User.size(); i++)
		for(size_t j = 0; j < User.size() - 1; j++)
			if (User[j].get_Username() > User[j + 1].get_Username()) {
				user::Account temp = User[j];
				User[j] = User[j + 1];
				User[j + 1] = temp;
			}
}