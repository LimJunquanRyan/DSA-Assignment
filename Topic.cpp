#include <string>
#include <iostream>
#include "Topic.h"

// Default Constructor
Topic::Topic() { posts = new List(); }

// Parameterized Constructor
Topic::Topic(string t, string d, int s) : ForumElement(t, d, s) { posts = new List(); }

// Returns pointer to the address of the posts stored in the Topic
List* Topic::getSubElements() { return posts; }

// Adds a Post object to the posts list
void Topic::addSubElements(Post* post) { posts->add(post); }

// Prints all Post objects
void Topic::printSubElements() {
	if (!(posts->print())) {
		cout << "No Posts yet." << endl;
	}
}

// Print Topic Details
void Topic::print() { ForumElement::print(); }

// Sorts posts List by Priority and Serial Number
void Topic::sortByPriorityAndSerial() { posts->mergeSortbyPriorityAndSerial(posts->getFirstNode()); }