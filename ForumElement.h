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
	ForumElement();
	virtual ~ForumElement();
	ForumElement(string t, string d, int s);
	string getTitle();
	void setTitle(string newTitle);
	string getDescription();
	void setDescription(string newDescription);
	bool getPriority();
	void updatePriority();
	virtual void print();
};