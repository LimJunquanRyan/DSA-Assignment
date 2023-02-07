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
	Account();
	Account(string u, string p);
	string getUsername();
	bool checkPassword(string inputPassword);
};