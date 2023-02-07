#include <string>
#include <iostream>
#include "ForumElement.h"

ForumElement::ForumElement() { 
	title = "";
	description = "";
};

ForumElement::~ForumElement() { }

ForumElement::ForumElement(string t, string d) { 
	setTitle(t);
	setDescription(d);
};

string ForumElement::getTitle() { return title; };

void ForumElement::setTitle(string newTitle) {
	title = newTitle;
};

string ForumElement::getDescription() {
	return description;
};

void ForumElement::setDescription(string newDescription) {
	description = newDescription;
};

void ForumElement::print() {
	cout << title << endl;
	cout << description << endl;
};