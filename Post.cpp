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
	replies = new List();
	smileReaction = 0;
	mehReaction = 0;
	cryReaction = 0;
}

Post::Post(string t, string d, bool p, int sR, int mR, int cR, int s, string a) : ForumElement(t, d, s)
{
	accountName = a;
	replies = new List();
	setPriority(p);
	smileReaction = sR;
	mehReaction = mR;
	cryReaction = cR;
}

string Post::getAccountName() { return accountName; }

int Post::getSmileReaction() {
	return smileReaction;
}

void Post::addSmileReaction() {
	smileReaction++;
}

void Post::setSmileReaction(int num) {
	smileReaction = num;
}

int Post::getMehReaction() {
	return mehReaction;
}

void Post::addMehReaction() {
	mehReaction++;
}

void Post::setMehReaction(int num) {
	mehReaction = num;
}

int Post::getCryReaction() {
	return cryReaction;
}

void Post::addCryReaction() {
	cryReaction++;
}

void Post::setCryReaction(int num) {
	cryReaction = num;
}

List* Post::getSubElements() { return replies; }

void Post::addSubElements(Reply* reply) { replies->add(reply); }

void Post::printSubElements() {
	if (!(replies->print())) {
		cout << "No Replies yet." << endl;
	}
}

void Post::print() { ForumElement::print(); }
