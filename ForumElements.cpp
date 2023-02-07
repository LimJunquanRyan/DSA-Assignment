#include <string>
#include <iostream>
#include "ForumElements.h"

ForumElements::ForumElements() { 
	title = "";
	description = "";
};

ForumElements::ForumElements(string t, string d) { 
	setTitle(t);
	setDescription(d);
};

string ForumElements::getTitle() { return title; };

void ForumElements::setTitle(string newTitle) {
	title = newTitle;
};

string ForumElements::getDescription() {
	return description;
};

void ForumElements::setDescription(string newDescription) {
	description = newDescription;
};

void ForumElements::print() {
	cout << title << endl;
	cout << description << endl;
};