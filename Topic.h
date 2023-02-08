#pragma once
#include <string>
#include <fstream>
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
	
	friend ostream &operator<<(ostream &os, const Topic &t) {
    os << t.posts;
    return os;
	}

	friend istream &operator>>(istream &is, Topic &t) {
    is >> t.posts;
    return is;
  }
};
