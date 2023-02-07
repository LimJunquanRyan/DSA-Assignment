#include <string>
#include <iostream>
#include "Topic.h"


Topic::Topic() { }

Topic::Topic(string t, string d) : ForumElements(t, d) { 
	List temp;
	temp.add(Post("1", "1"));
	temp.add(Post("2", "2"));
	temp.add(Post("3", "3"));
	posts = &temp;
}

void Topic::addSubElements(Post post) { posts->add(post); }

void Topic::printSubElements() { posts->print(); }

void Topic::print() { ForumElements::print(); }