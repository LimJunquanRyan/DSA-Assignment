#include <string>
#include <iostream>
#include "ForumElement.h"

ForumElement::ForumElement() { 
	title = "";
	description = "";
	priority = false;
	serial = 0;
};

ForumElement::~ForumElement() { }

ForumElement::ForumElement(string t, string d, int s) { 
	title = t;
	description = d;
	priority = false;
	serial = s;
};

string ForumElement::getTitle() { return title; };

void ForumElement::setTitle(string newTitle) { title = newTitle; }

string ForumElement::getDescription() { return description; }

void ForumElement::setDescription(string newDescription) { description = newDescription; }

bool ForumElement::getPriority() { return priority; }

void ForumElement::updatePriority() { priority = !priority; }

void ForumElement::setPriority(bool newPriority) { priority = newPriority; }

int ForumElement::getSerial() { return serial; }

void ForumElement::print() {
	cout << title << endl;
	cout << description << endl;
};