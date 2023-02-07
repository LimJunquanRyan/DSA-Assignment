#pragma once
#include <iostream>
using namespace std;

class ForumElements {
private:
	string title;
	string description;
	//bool priority;

public:
	ForumElements();
	ForumElements(string t, string d);
	string getTitle();
	void setTitle(string newTitle);
	string getDescription();
	void setDescription(string newDescription);
	virtual void print();
};