#include <string>
#include <iostream>
#include "Reply.h"

Reply::Reply() { }

Reply::~Reply() {
	setTitle("");
	setDescription("");
}

Reply::Reply(string t, string d, string a) : ForumElement(t, d) { 
	accountName = a;
}

void Reply::print() { ForumElement::print(); }