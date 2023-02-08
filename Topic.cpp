#include <string>
#include <iostream>
#include "Topic.h"


Topic::Topic() { 
	posts = new List();
}

Topic::Topic(string t, string d, int s) : ForumElement(t, d, s) { 
	posts = new List();
}

List* Topic::getSubElements() { return posts; }

void Topic::addSubElements(Post* post) { posts->add(post); }

void Topic::printSubElements() {
	if (!(posts->print())) {
		cout << "No Posts yet." << endl;
	}
}

void Topic::print() { ForumElement::print(); }

void Topic::sortByPriorityAndSerial() { posts->mergeSortbyPriorityAndSerial(posts->getFirstNode()); }