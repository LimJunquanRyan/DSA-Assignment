#include <string>
#include <iostream>
#include "Post.h"


Post::Post() {
	replies = new List();
}

Post::~Post() {
	setTitle("");
	setDescription("");
	while (replies->getLength() != 0) replies->remove(0);
}

Post::Post(string t, string d, string a) : ForumElement(t, d) 
{
	accountName = a;
	List* temp = new List();
	temp->add(new Reply("Reply1", "desc", "1"));
	temp->add(new Reply("Reply2", "desc", "2"));
	temp->add(new Reply("Reply3", "desc", "2"));
	replies = temp;
	reactions = new List();
}

//bool Post::getPriority() { return priority; }

//void Post::setPriority() { priority = !priority; }

string Post::getAccountName() { return accountName; }

void Post::addSubElements(Reply* reply) { replies->add(reply); }

void Post::printSubElements() {
	if (!(replies->print())) {
		cout << "No Replies yet." << endl;
	}
}

void Post::print() { ForumElement::print(); }
