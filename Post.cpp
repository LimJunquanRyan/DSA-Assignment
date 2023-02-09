#include <string>
#include <iostream>
#include "Post.h"

// Default Constructor
Post::Post() {
	replies = new List();
	smileReaction = 0;
	mehReaction = 0;
	cryReaction = 0;
}

// Destructor
Post::~Post() {
	setTitle("");
	setDescription("");
	while (replies->getLength() != 0) replies->remove(0);
}

// Parameterized Constructor when adding in the main loop
Post::Post(string t, string d, int s, string a) : ForumElement(t, d, s) 
{
	accountName = a;
	replies = new List();
	smileReaction = 0;
	mehReaction = 0;
	cryReaction = 0;
}

// Parameterised Constructor when adding by loading into the application
Post::Post(string t, string d, bool p, int sR, int mR, int cR, int s, string a) : ForumElement(t, d, s)
{
	accountName = a;
	replies = new List();
	setPriority(p);
	smileReaction = sR;
	mehReaction = mR;
	cryReaction = cR;
}

// Gets Account Name
string Post::getAccountName() { return accountName; }

// Gets Number of Smile Reactions
int Post::getSmileReaction() { return smileReaction; }

// Increments Number of Smile Reactions by 1
void Post::addSmileReaction() { smileReaction++; }

// Sets Number of Smile Reactions to value passed
void Post::setSmileReaction(int num) { smileReaction = num; }

// Gets Number of Meh Reactions
int Post::getMehReaction() { return mehReaction; }

// Increments Number of Meh Reactions by 1
void Post::addMehReaction() { mehReaction++; }

// Sets Number of Meh Reactions to value passed
void Post::setMehReaction(int num) { mehReaction = num; }

// Gets Number of Cry Reactions 
int Post::getCryReaction() { return cryReaction; }

// Increments Number of Meh Reactions by 1
void Post::addCryReaction() { cryReaction++; }

// Sets Number of Cry Reactions to value passed
void Post::setCryReaction(int num) { cryReaction = num; }

// Returns pointer to address of the replies List
List* Post::getSubElements() { return replies; }

// Adds Reply object to the replies List
void Post::addSubElements(Reply* reply) { replies->add(reply); }

// Prints all Reply objects under this Post
void Post::printSubElements() {
	if (!(replies->print())) {
		cout << "No Replies yet." << endl;
	}
}

// Print Post Details
void Post::print() { ForumElement::print(); }
