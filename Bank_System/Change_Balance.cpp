#include"Account.h"
// This method is used to add amount to user's current balance
// charge will be deducted before passing to this method
void user::Account::Add_Balance(double amount) {
	user::Account::Balance += amount;
}
// This method is used to subtract amount to user's current balance
// charge will be deducted before passing to this method
void user::Account::Deduct_Balance(double amount) {
	user::Account::Balance -= amount;
}