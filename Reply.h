#pragma once
#include <string>
#include <iostream>
#include "List.h"
using namespace std;

class Reply : public ForumElement {
private:
	string accountName;

public:
	// Default Constructor
	Reply();

	// Destructor
	~Reply();

	// Parameterized Constructor
	Reply(string t, string d, int s, string a);
	
	// Gets Account Name
	string getAccountName();

	// Prints Reply Details
	void print() override;
};
