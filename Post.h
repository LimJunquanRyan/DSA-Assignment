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
	int smileReaction;
	int mehReaction;
	int cryReaction;

public:
	Post();
	~Post();
	Post(string t, string d, int s, string a);
	string getAccountName();
	int getSmileReaction();
	void addSmileReaction();
	int getMehReaction();
	void addMehReaction();
	int getCryReaction();
	void addCryReaction();
	List* getSubElements();
	void addSubElements(Reply* reply);
	void printSubElements();
	void print() override;
};
