#pragma once
#include <string>
#include <iostream>
#include "List.h"
using namespace std;

class Reply : public ForumElement {
private:
	string accountName;

public:
	Reply();
	~Reply();
	Reply(string t, string d, int s, string a);
	string getAccountName();
	void print() override;
};
