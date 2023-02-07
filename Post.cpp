#include <string>
#include <iostream>
#include "Post.h"


Post::Post() {
	replies = new List();
}
Post::Post(string t, string d) : ForumElements(t, d) 
{
	replies = new List();
}

//bool Post::getPriority() { return priority; }

//void Post::setPriority() { priority = !priority; }

void Post::addSubElements(Reply reply) { replies->add(reply); }

void Post::printSubElements() { replies->print(); }

void Post::print() { ForumElements::print(); }
