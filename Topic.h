/*
Members:
Xiao Yaojie (S10222764)
Lim Junquan Ryan (S10192609)

Group: Dr Pamela Fanclub
*/

#pragma once
#include <string>
#include <iostream>
#include "List.h"
#include "Post.h"
using namespace std;


class Topic : public ForumElement {
private:
	List* posts;

public:
	// Default Constructor
	Topic();

	// Parameterized Constructor
	Topic(string t, string d, int s);

	// Returns pointer to the address of the posts stored in the Topic
	List* getSubElements();

	// Adds a Post object to the posts list
	void addSubElements(Post* post);

	// Prints all Post objects
	void printSubElements();

	// Print Topic Details
	void print() override;

	// Sorts posts List by Priority and Serial Number
	void sortByPriorityAndSerial();
};
