#pragma once
#include <string>
#include <iostream>
#include "List.h"
#include "Reply.h"
using namespace std;


class Post : virtual public ForumElements {
private:
	List* replies;

public:
	Post();
	Post(string t, string d);
	bool getPriority();
	void setPriority();
	void addSubElements(Reply reply);
	void printSubElements();
	void print() override;
};
