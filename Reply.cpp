#include <string>
#include <iostream>
#include "Reply.h"

Reply::Reply() { }

Reply::~Reply() {
	setTitle("");
	setDescription("");
}

Reply::Reply(string t, string d, int s, string a) : ForumElement(t, d, s) { 
	accountName = a;
}

string Reply::getAccountName() { return accountName; }

void Reply::print() { ForumElement::print(); }