#pragma once
#include<iostream>
namespace user {
	class Account
	{
	//Necessary members to be used to setup user's account
	protected:
		std::string Name;
		unsigned Age;
		std::string Gender;
		std::string Birthdate;
	private:
		std::string Username;
		std::string Password;
		unsigned ID = 0;
		long Balance = 0;

	public:
		// Default constructor for Account class
		Account() = default;
		void Profile_Info();
		//setters and getters
		void set_Name(const std::string Name){
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
	};
}