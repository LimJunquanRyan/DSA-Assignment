#pragma once
#include<string>
#include<iostream>
#include "PostList.h"
using namespace std;

typedef string ItemType;

class TopicList
{
private:
	struct TopicNode
	{
		string title;		// title
		string description;	// description
		PostList* posts;
		TopicNode* nextTopic;	// pointer pointing to next item
	};

	TopicNode* firstNode;	// point to the first item
	int  size;			// number of items in the list

public:
	TopicList();			// constructor

	~TopicList();		// destructor

	// add an item to the back of the list (append)
	// pre : size < MAX_SIZE
	// post: item is added to the front of the list
	//       size of list is increased by 1
	bool add(string title, string description);

	bool addPost(string topic, string title, string description, bool priority, string createdBy);

	// remove an item at a specified position in the list
	// pre : 0 <= index < size
	// post: item is removed the specified position in the list
	//       items after the position are shifted forward by 1 position
	//       size of list is decreased by 1
	void remove(int index);

	// get an item at a specified position of the list (retrieve)
	// pre : 0 <= index < size
	// post: none
	// return the item in the specified index of the list
	ItemType get(int index);

	// check if the list is empty
	// pre : none
	// post: none
	// return true if the list is empty; otherwise returns false
	bool isEmpty();

	// check the size of the list
	// pre : none
	// post: none
	// return the number of items in the list
	int getLength();

	//------------------- Other useful functions -----------------

	// display the items in the list
	void print();

	// display the items in the list
	void printPosts(string topics);

	// void replace(int index, ItemType item);
	// int search(ItemType item);
};

