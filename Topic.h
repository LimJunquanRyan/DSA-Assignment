#pragma once
#include <string>
#include <iostream>
#include "List.h"
#include "Post.h"
using namespace std;


class Topic : public ForumElement {
private:
	List* posts;

public:
	Topic();
	Topic(string t, string d, int s);
	List* getSubElements();
	void addSubElements(Post* post);
	void printSubElements();
	void print() override;
	void sortByPriorityAndSerial();
};
