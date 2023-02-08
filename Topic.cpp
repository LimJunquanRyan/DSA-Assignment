#include <string>
#include <iostream>
#include "Topic.h"


Topic::Topic() { 
	posts = new List();
}

Topic::Topic(string t, string d, int s) : ForumElement(t, d, s) { 
	List* temp = new List();
	temp->add(new Post("Post1", "Desc", 1, "1"));
	temp->add(new Post("Post2", "Desc", 2, "2"));
	temp->add(new Post("Post3", "Desc", 3, "3"));
	posts = temp;
}

List* Topic::getSubElements() { return posts; }

void Topic::addSubElements(Post* post) { posts->add(post); }

void Topic::printSubElements() {
	if (!(posts->print())) {
		cout << "No Posts yet." << endl;
	}
}

void Topic::print() { ForumElement::print(); }