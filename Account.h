/* 
Members:
Xiao Yaojie (S10222764)
Lim Junquan Ryan (S10192609)

Group: Dr Pamela Fanclub
*/

#pragma once
#include <string>
#include <iostream>
#include "List.h"
using namespace std;

class Account {
private:
	string username;
	string password;

public:
	// Default Constructor
	Account();

	// Destructor
	~Account();

	// Parameterized Constructor
	Account(string u, string p);

	// Get Username of account
	string getUsername();

	// Get password of account
	string getPassword();

	// Compare and checks password 
	bool checkPassword(string inputPassword);
};