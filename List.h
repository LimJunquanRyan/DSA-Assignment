/*
Members:
Xiao Yaojie (S10222764)
Lim Junquan Ryan (S10192609)

Group: Dr Pamela Fanclub
*/

#pragma once
#include<iostream>
#include "ForumElement.h"
using namespace std;

typedef ForumElement ItemType;

class List
{
private:
	struct Node
	{
		ItemType* item;
		Node* next;	// pointer pointing to next item
	};

	Node* firstNode;	// point to the first item
	int  size;			// number of items in the list

public:
	List();			// constructor

	~List();		// destructor

	// add an item to the back of the list (append)
	// pre : size < MAX_SIZE
	// post: item is added to the front of the list
	//       size of list is increased by 1
	bool add(ItemType* item);

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
	bool print();

	// Returns pointer to the address of the ForumElement in the argument Node passed
	ForumElement* returnAddress(ItemType item);

	// Returns pointer to the address of the first Node
	Node** getFirstNode();

	// Recursive helper function used in mergeSortByPriorityAndSerial
	Node* SortedMerge(Node* a, Node* b);

	// Splits list in two by providing frontReference as pointer to the front of the list and backReference as pointer to the back of the list
	void FrontBackSplit(Node* source,
		Node** frontReference, Node** backReference);

	// Merge Sort Algorithm based on Priority and Serial Number
	void mergeSortbyPriorityAndSerial(Node** headRef);
	
	// void replace(int index, ItemType item);
	// int search(ItemType item);
};

