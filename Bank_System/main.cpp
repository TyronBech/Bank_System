#include"Account.h"
#include"functions.h"

int main()
{
    std::cout << "C++ Bank" << std::endl;
    std::cout << "Welcome" << std::endl;
    std::cout << "New Bank System" << std::endl;
    std::vector<user::Account> User;
    user::Account temp_user;
    bool result = BANK::Sign_up(temp_user);
    if (!result) {
        std::cout << "You tried many times" << std::endl;
        std::cout << "Sign up terminated" << std::endl;
    }
    else {
        User.push_back(temp_user);
        User[0].Profile_Info();
    }
}