#include "Account.h"

Account::Account() {}

Account::Account(string u, string p) : username(u), password(p) {}

string Account::getUsername() { return username; }

bool Account::checkPassword(string inputPassword) {
	// Compare password (CaseSensitive)
	if (inputPassword == password) return true;
	else return false;
}