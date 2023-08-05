#include "functions.h"
#include<Windows.h>
// Declared function to be initialized below
void Display();
std::atomic_bool stop_running(false);
void Thank_you();
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
    bool result = true;
    Display();
    // Main menu where program is going the let the user to choose
    // based on available choices and check it to the switch case
    do {
        system("cls");
        BANK::Design(0);
        BANK::Color(2);
        BANK::gotoxy(56, 10); std::cout << "C++ Bank" << std::endl;
        BANK::gotoxy(54, 11); std::cout << "Welcome User" << std::endl;
        BANK::gotoxy(53, 13); std::cout << "1 - Log in" << std::endl;
        BANK::gotoxy(53, 14); std::cout << "2 - Sign up" << std::endl;
        BANK::gotoxy(53, 15); std::cout << "3 - Exit" << std::endl;
        BANK::gotoxy(51, 16); std::cout << "Enter your choice: ";
        choice = BANK::Try_catch_int(static_cast<long long>(choice));
        // Switch case is used to check the user's input
        switch (choice) {
        case 0: break;
            // Case 1 if for log in and directing to the Main_Bank function
        case 1: result = BANK::Log_in(User);
            if (result) BANK::Account_List(1, User);
            break;
            // Case 2 is for sign up
        case 2: Get_info = BANK::Sign_up(User);
            // Getting the first return which the boolean result to be check
            // if the sign up is successful
            result = std::get<0>(Get_info);
            if (!result) {
                system("cls");
                BANK::Design(0);
                BANK::Color(4);
                BANK::gotoxy(40, 12); std::cout << "You may tried multiple times and failed" << std::endl;
                BANK::gotoxy(43, 13); std::cout << "or encounter error during sign up" << std::endl;
                BANK::gotoxy(51, 14); std::cout << "Sign up terminated" << std::endl;
                system("pause>0");
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
                system("cls");
                BANK::Design(0);
                BANK::Color(6);
                BANK::gotoxy(45, 12); std::cout << "Signed an account successfully" << std::endl;
                BANK::gotoxy(51, 13); std::cout << "You may now log in" << std::endl;
                system("pause>0");
            }
            break;
        case 3: // Exit case
            break;
        default: BANK::Color(4);
            BANK::gotoxy(48, 17); std::cout << "That is a invalid choice" << std::endl;
            system("pause>0");
        }
    } while (choice != 3);
    std::thread thread1(Thank_you);
    std::thread thread2([]() { system("pause>0"); stop_running = true; });
    thread1.join();
    thread2.join();
    system("cls");
    BANK::Color(7);
    return 0;
}
void Display() {
    // ASCII Drawing (Keyboard) for the title page of the program
    // The keyboard used was modified to show program's title
    /// @author Nieminen Mika
    // Link: https://www.asciiart.eu/computers/keyboards
    system("cls");
    BANK::Design(0);
    BANK::gotoxy(30, 9); std::cout << ",---,---,---,---,---,---,---,---,---,---,---,---,---,-------," << std::endl;
    BANK::gotoxy(30, 10); std::cout << "|1/2| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | + | ' | <-    |" << std::endl;
    BANK::gotoxy(30, 11); std::cout << "|---'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-----|" << std::endl;
    BANK::gotoxy(30, 12); std::cout << "| ->| | Q | W | E | R | T | Y | U | I | O | P | ] | ^ |     |" << std::endl;
    BANK::gotoxy(30, 13); std::cout << "|-----',--'---'---'---'---'---'---'---'---'---',--',--'|    |" << std::endl;
    BANK::gotoxy(30, 14); std::cout << "| Caps |                                       | [ | * |    |" << std::endl;
    BANK::gotoxy(30, 15); std::cout << "|----,-'-,---,---,---,---,---,---,---,---,---,-'-,-'---'----|" << std::endl;
    BANK::gotoxy(30, 16); std::cout << "|    | < | Z | X | C | V | B | N | M | , | . | - |          |" << std::endl;
    BANK::gotoxy(30, 17); std::cout << "|----'-,-',--'--,'---'---'---'---'---'---'-,-'---',--,------|" << std::endl;
    BANK::gotoxy(30, 18); std::cout << "| ctrl |  | alt |                          |altgr |  | ctrl |" << std::endl;
    BANK::gotoxy(30, 19); std::cout << "'------'  '-----'--------------------------'------'  '------'" << std::endl;
    BANK::Color(2);
    BANK::gotoxy(43, 14); std::cout << "C   +   +       B   A   N   K";
    std::this_thread::sleep_for(std::chrono::seconds(5));
}
void Thank_you() {
    while(!stop_running) {
        system("cls");
        BANK::Design(1);
        BANK::Color(2);
        BANK::gotoxy(46, 11); std::cout << "Thank you for using C++ Bank" << std::endl;
        BANK::gotoxy(54, 12); std::cout << "See you again" << std::endl;
        BANK::gotoxy(50, 20); std::cout << "Enter any key to exit" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}