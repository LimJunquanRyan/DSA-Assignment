#pragma once
#include <iostream>
using namespace std;

class ForumElement {
private:
	string title;
	string description;
	//bool priority;

public:
	ForumElement();
	virtual ~ForumElement();
	ForumElement(string t, string d);
	string getTitle();
	void setTitle(string newTitle);
	string getDescription();
	void setDescription(string newDescription);
	virtual void print();
};