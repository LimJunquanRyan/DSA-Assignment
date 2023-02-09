#include "Account.h"

// Default Constructor
Account::Account() {
	username = "";
	password = "";
}

// Destructor
Account::~Account() {
	username = "";
	password = "";
}
// Parameterized Constructor
Account::Account(string u, string p) : username(u), password(p) {}

// Get username of account
string Account::getUsername() { return username; }

// Get password of account
string Account::getPassword() { return password; }

// Compares and check password of account
bool Account::checkPassword(string inputPassword) {
	// Compare password (CaseSensitive)
	if (inputPassword == password) return true;
	else return false;
}