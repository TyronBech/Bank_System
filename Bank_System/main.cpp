#include "functions.h"
// Main function of the program
int main()
{
    // vector that handle all the accounts during program execution
    std::vector<user::Account> User;
    // Temporary object for class Account
    user::Account temp_user;
    // tuple to retrieve multiple returns in Sign_up function
    std::tuple<bool, user::Account> Get_info;
    // Retrieving all the present account in the csv using the 0 flag
    // to note that the program should retrieve the accounts only
    BANK::Account_List(0, User);
    unsigned choice = 0;
    bool result;
    // Main menu where program is going the let the user to choose
    // based on available choices and check it to the switch case
    do {
        std::cout << "C++ Bank" << std::endl;
        std::cout << "Welcome" << std::endl;
        std::cout << "1 - Log in" << std::endl;
        std::cout << "2 - Sign up" << std::endl;
        std::cout << "3 - Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        // Switch case is used to check the user's input
        switch (choice) {
            // Case 1 if for log in and directing to the Main_Bank function
        case 1: result = BANK::Log_in(User);
            if (result) BANK::Account_List(1, User);
            break;
            // Case 2 is for sign up
        case 2: Get_info = BANK::Sign_up();
            // Getting the first return which the boolean result to be check
            // if the sign up is successful
            result = std::get<0>(Get_info);
            if (!result) {
                std::cout << "You may tried multiple times and failed" << std::endl;
                std::cout << "or encounter error during sign up" << std::endl;
                std::cout << "Sign up terminated" << std::endl;
            }
            else {
                // Getting the second return which is the account
                temp_user = std::get<1>(Get_info);
                User.push_back(temp_user);
                // Bubble sort is used before rewriting the list of account to the csv file
                // to sort the account alphabetically based on usernames
                BANK::BubbleSort(User);
                // Calling the Account_List function with flag 1 to command that the
                // function is called to rewrite the contents of the account alongside
                // with new created account done by Sign_up
                BANK::Account_List(1, User);
                std::cout << "Signed an Account successfully" << std::endl;
                std::cout << "You may now log in" << std::endl;
            }
            break;
        case 3: // Exit case
            break;
        default: std::cout << "That is a invalid choice" << std::endl;
        }
        if (!result) break;
    } while (choice != 3);
}