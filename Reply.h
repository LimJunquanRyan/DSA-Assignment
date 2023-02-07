#pragma once
#include <string>
#include <iostream>
#include "List.h"
using namespace std;


class Reply : virtual public ForumElements {
public:
	Reply();
	Reply(string title, string description);
	void print() override;
};
