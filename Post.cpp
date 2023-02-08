#include <string>
#include <iostream>
#include "Post.h"


Post::Post() {
	replies = new List();
	smileReaction = 0;
	mehReaction = 0;
	cryReaction = 0;
}

Post::~Post() {
	setTitle("");
	setDescription("");
	while (replies->getLength() != 0) replies->remove(0);
}

Post::Post(string t, string d, int s, string a) : ForumElement(t, d, s) 
{
	accountName = a;
	List* temp = new List();
	temp->add(new Reply("Reply1", "desc", 1, "1"));
	temp->add(new Reply("Reply2", "desc", 1, "2"));
	temp->add(new Reply("Reply3", "desc", 1, "2"));
	replies = temp;
	smileReaction = 0;
	mehReaction = 0;
	cryReaction = 0;
}

string Post::getAccountName() { return accountName; }

int Post::getSmileReaction() {
	return smileReaction;
}
void Post::addSmileReaction() {
	smileReaction++;
}
int Post::getMehReaction() {
	return mehReaction;
}
void Post::addMehReaction() {
	mehReaction++;
}
int Post::getCryReaction() {
	return cryReaction;
}
void Post::addCryReaction() {
	cryReaction++;
}

List* Post::getSubElements() { return replies; }

void Post::addSubElements(Reply* reply) { replies->add(reply); }

void Post::printSubElements() {
	if (!(replies->print())) {
		cout << "No Replies yet." << endl;
	}
}

void Post::print() { ForumElement::print(); }
