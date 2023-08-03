#pragma once
// Incluced C++ libraries
#include"Account.h"
#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<fstream>
#include<ctime>
#include<random>
#include<limits>
#include<cctype>
#include<tuple>
namespace BANK {
	// Declaration of all important functions of the program
	// Each functions is initialized in a separated .cpp files
	std::tuple<bool, user::Account> Sign_up();
	void Account_List(unsigned flag, std::vector<user::Account>& List_of_Accounts);
	bool Log_in(std::vector<user::Account>& Data);
	bool Main_Bank(user::Account& User);
	size_t binary_search(std::vector<user::Account> arr, const std::string target);
	void Delete(std::vector<user::Account>& Data, user::Account User);
	void BubbleSort(std::vector<user::Account>& User);
}