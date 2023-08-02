#include"Account.h"

void user::Account::Add_Balance(double amount) {
	user::Account::Balance += amount;
}
void user::Account::Deduct_Balance(double amount) {
	user::Account::Balance -= amount;
}