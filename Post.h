#pragma once
#include <string>
#include <iostream>
#include "List.h"
#include "Reply.h"
using namespace std;


class Post : public ForumElement {
private:
	List* replies;
	string accountName;
	List* reactions;

public:
	Post();
	~Post();
	Post(string t, string d, string a);
	bool getPriority();
	void setPriority();
	string getAccountName();
	void addSubElements(Reply* reply);
	void printSubElements();
	void print() override;
};
