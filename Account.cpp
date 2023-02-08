#include "Account.h"

Account::Account() {
	username = "";
	password = "";
}

Account::~Account() {
	username = "";
	password = "";
}

Account::Account(string u, string p) : username(u), password(p) {}

string Account::getUsername() { return username; }

string Account::getPassword() { return password; }

bool Account::checkPassword(string inputPassword) {
	// Compare password (CaseSensitive)
	if (inputPassword == password) return true;
	else return false;
}