#pragma once
#include <string>
#include <iostream>
#include "List.h"
#include "Post.h"
using namespace std;


class Topic : virtual public ForumElements {
private:
	List* posts;

public:
	Topic();
	Topic(string t, string d);
	void addSubElements(Post post);
	void printSubElements();
	void print() override;
};
