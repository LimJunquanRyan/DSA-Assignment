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
	Post(string t, string d, bool p, int sR, int mR, int cR, int s, string a);
	string getAccountName();
	int getSmileReaction();
	void addSmileReaction();
	void setSmileReaction(int num);
	int getMehReaction();
	void addMehReaction();
	void setMehReaction(int num);
	int getCryReaction();
	void addCryReaction();
	void setCryReaction(int num);
	List* getSubElements();
	void addSubElements(Reply* reply);
	void printSubElements();
	void print() override;
};
