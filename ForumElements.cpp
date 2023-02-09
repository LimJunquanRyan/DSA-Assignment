#include <string>
#include <iostream>
#include "ForumElement.h"

// Constructor
ForumElement::ForumElement() { 
	title = "";
	description = "";
	priority = false;
	serial = 0;
};

// Destructor
ForumElement::~ForumElement() { }

// Parameterized Contructor
ForumElement::ForumElement(string t, string d, int s) { 
	title = t;
	description = d;
	priority = false;
	serial = s;
};

// Gets Title
string ForumElement::getTitle() { return title; };

// Sets Title to value passed
void ForumElement::setTitle(string newTitle) { title = newTitle; }

// Gets Description
string ForumElement::getDescription() { return description; }

// Sets Description to value passed
void ForumElement::setDescription(string newDescription) { description = newDescription; }

// Gets Priority
bool ForumElement::getPriority() { return priority; }

// Flips Priority boolean
void ForumElement::updatePriority() { priority = !priority; }

// Sets Priority boolean when loading forum
void ForumElement::setPriority(bool newPriority) { priority = newPriority; }

// Gets Serial Number
int ForumElement::getSerial() { return serial; }

// Prints ForumElement Details
void ForumElement::print() {
	cout << title << endl;
	cout << description << endl;
};