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
	Reply(string title, string description, string accountName);
	void print() override;
};
