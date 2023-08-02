#pragma once
#include<iostream>
namespace user {
	class Account
	{
		//Necessary members to be used to setup user's account
	protected:
		std::string Name = "";
		unsigned Age = 0;
		std::string Gender = "";
		std::string Birthdate = "";
	private:
		std::string Username = "";
		std::string Password = "";
		unsigned ID = 0;
		double Balance = 0;

	public:
		// Default constructor for Account class
		Account() = default;
		void Profile_Info();
		void Add_Balance(double amount);
		void Deduct_Balance(double amount);
		//setters and getters
		void set_Name(const std::string Name) {
			this->Name = Name;
		}
		void set_Age(const unsigned Age) {
			this->Age = Age;
		}
		void set_Gender(const std::string Gender) {
			this->Gender = Gender;
		}
		void set_Birthdate(const std::string Birthdate) {
			this->Birthdate = Birthdate;
		}
		void set_Username(const std::string Username) {
			this->Username = Username;
		}
		void set_Password(const std::string Password) {
			this->Password = Password;
		}
		void set_ID(const unsigned ID) {
			this->ID = ID;
		}
		void set_Balance(const double Balance) {
			this->Balance = Balance;
		}
		std::string get_Name() {
			return Name;
		}
		unsigned get_Age() {
			return Age;
		}
		std::string get_Gender() {
			return Gender;
		}
		std::string get_Birthdate() {
			return Birthdate;
		}
		std::string get_Username() {
			return Username;
		}
		std::string get_Password() {
			return Password;
		}
		unsigned get_ID() {
			return ID;
		}
		double get_Balance() {
			return Balance;
		}
	};
}