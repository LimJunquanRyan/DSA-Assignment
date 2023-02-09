/*
Members:
Xiao Yaojie (S10222764)
Lim Junquan Ryan (S10192609)

Group: Dr Pamela Fanclub
*/

#pragma once
#include <iostream>
using namespace std;

class ForumElement {
private:
	string title;
	string description;
	bool priority;
	int serial;

public:
	// Constructor
	ForumElement();

	// Destructor
	virtual ~ForumElement();

	// Parameterized Contructor
	ForumElement(string t, string d, int s);

	// Gets Title
	string getTitle();

	// Sets Title to value passed
	void setTitle(string newTitle);

	// Gets Description
	string getDescription();

	// Sets Description to value passed
	void setDescription(string newDescription);

	// Gets Priority
	bool getPriority();

	// Flips Priority boolean
	void updatePriority();

	// Sets Priority boolean when loading forum
	void setPriority(bool newPriority);

	// Gets Serial Number
	int getSerial();

	// Prints ForumElement Details
	virtual void print();
};