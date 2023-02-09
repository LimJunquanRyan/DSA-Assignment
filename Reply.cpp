#include <string>
#include <iostream>
#include "Reply.h"

// Default Constructor
Reply::Reply() { }

// Destructor
Reply::~Reply() {
	setTitle("");
	setDescription("");
}

// Parameterized Constructor
Reply::Reply(string t, string d, int s, string a) : ForumElement(t, d, s) { 
	accountName = a;
}

// Gets Account Name
string Reply::getAccountName() { return accountName; }

// Prints Reply Details
void Reply::print() { ForumElement::print(); }