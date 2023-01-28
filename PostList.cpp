#include "PostList.h"

PostList::PostList() {};			// constructor

PostList::~PostList() {};		// destructor

// add an item to the back of the list (append)
// pre : size < MAX_SIZE
// post: item is added to the back of the list
//       size of list is increased by 1
bool PostList::add(string title, string description, bool priority, string createdBy) {
	PostNode *newNode = new PostNode;
	newNode->title = title;
	newNode->description = description;
	newNode->priority = priority;
	newNode->createdBy = createdBy;
	newNode->nextPost = NULL;

	if (size == 0) { firstNode = newNode; }
	else {
		PostNode*ptr = firstNode;
		while (ptr->nextPost != NULL) {
			ptr = ptr->nextPost;
		}
		ptr->nextPost = newNode;
	}
	size++;
	return true;
}
/*
// add an item at a specified position in the list (insert)
// pre : 0 <= index <= size
// post: item is added to the specified position in the list
//       items after the position are shifted back by 1 position
//       size of list is increased by 1
bool PostList::add(int index, ItemType item) {
	if (0 <= index and index <= size) {
		PostNode* newNode = new Node;
		newNode->item = item;
		newNode->next = NULL;
		if (index == 0) {
			newNode->next = firstNode;
			firstNode = newNode;
		}
		else {
			PostNode* ptr = firstNode;
			for (index; index-1 > 0; index--) { ptr = ptr->next; }
			newNode->next = ptr->next;
			ptr->next = newNode;
		}
		size++;
		return true;
	}
	else { return false; }
}
*/

// remove an item at a specified position in the list
// pre : 0 <= index < size
// post: item is removed the specified position in the list
//       items after the position are shifted forward by 1 position
//       size of list is decreased by 1
void PostList::remove(int index) {
	if (0 <= index and index <= size) {
		if (index == 0) {
			PostNode* remove = firstNode;
			firstNode = firstNode->nextPost;
			remove->nextPost = NULL;
			delete remove;
		}
		else {
			PostNode* current = firstNode;
			PostNode* previous = NULL;
			for (index; index > 0; index--) {
				previous = current;
				current = current->nextPost;
			}
			previous->nextPost = current->nextPost;
			current->nextPost = NULL;
			delete current;
		}
		size--;
	}
}

// get an item at a specified position of the list (retrieve)
// pre : 0 <= index < size
// post: none
// return the item in the specified index of the list
ItemType PostList::get(int index) {
	if (0 <= index and index <= size) {
		PostNode* ptr = firstNode;
		for (index; index - 1 > 0; index--) { ptr = ptr->nextPost; }
		return ptr->title;
	}
	else { return ""; }
}

// check if the list is empty
// pre : none
// post: none
// return true if the list is empty; otherwise returns false
bool PostList::isEmpty() {
	if (size == 0) { return true; }
	else { return false; }
}

// check the size of the list
// pre : none
// post: none
// return the number of items in the list
int PostList::getLength() { return size; }

//------------------- Other useful functions -----------------

// display the items in the list
void PostList::print() {
	if (firstNode != NULL) {
		PostNode* ptr = firstNode;
		int counter = 0;
		while (ptr != NULL) {
			counter++;
			cout << counter << ".  " << ptr->title << endl;
			cout << "    " << ptr->description << "\n" << endl;
			ptr = ptr->nextPost;
		}
	}
	else {
		cout << "No Posts yet!" << endl;
	}
}

// sort by priority
void PostList::sort() {

}
