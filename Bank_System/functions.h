#pragma once
// Incluced C++ libraries
#include"Account.h"
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
	void Main_Bank(user::Account& User);
}