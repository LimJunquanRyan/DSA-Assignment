#include "TopicList.h"

TopicList::TopicList() {	// constructor
	firstNode = NULL;
	size = 0; 
}			

TopicList::~TopicList() {	// destructor
	while (!isEmpty()) {
		remove(0);
	}
} 

// add an item to the back of the list (append)
// pre : size < MAX_SIZE
// post: item is added to the front of the list
//       size of list is increased by 1
bool TopicList::add(string title, string description) {
	TopicNode *newNode = new TopicNode;
	newNode->title = title;
	newNode->description = description;
	newNode->posts = new PostList;
	newNode->nextTopic = NULL;

	if (!isEmpty()) { newNode->nextTopic = firstNode; }
	firstNode = newNode;
	size++;
	return true;
}

bool TopicList::addPost(string topic, string title, string description, bool priority, string createdBy) {
	//Navigate to Topic
	TopicNode* ptr = firstNode;
	while (ptr->title != topic) { ptr = ptr->nextTopic; }

	ptr->posts->add(title, description, priority, createdBy);
	return true;
}

// remove an item at a specified position in the list
// pre : 0 <= index < size
// post: item is removed the specified position in the list
//       items after the position are shifted forward by 1 position
//       size of list is decreased by 1
void TopicList::remove(int index) {
	if (0 <= index and index <= size) {
		if (index == 0) {
			TopicNode* remove = firstNode;
			firstNode = firstNode->nextTopic;
			remove->nextTopic = NULL;
			delete remove;
		}
		else {
			TopicNode* current = firstNode;
			TopicNode* previous = NULL;
			for (index; index > 0; index--) {
				previous = current;
				current = current->nextTopic;
			}
			previous->nextTopic = current->nextTopic;
			current->nextTopic = NULL;
			delete current;
		}
		size--;
	}
}

// get an item at a specified position of the list (retrieve)
// pre : 0 <= index < size
// post: none
// return the item in the specified index of the list
ItemType TopicList::get(int index) {
	if (0 <= index and index <= size) {
		TopicNode* ptr = firstNode;
		for (index; index - 1 > 0; index--) { ptr = ptr->nextTopic; }
		return ptr->title;
	}
	else { return ""; }
}

// check if the list is empty
// pre : none
// post: none
// return true if the list is empty; otherwise returns false
bool TopicList::isEmpty() {
	if (size == 0) { return true; }
	else { return false; }
}

// check the size of the list
// pre : none
// post: none
// return the number of items in the list
int TopicList::getLength() { return size; }

//------------------- Other useful functions -----------------

// display the items in the list
void TopicList::print() {
	if (firstNode != NULL) {
		TopicNode* ptr = firstNode;
		int counter = 0;
		while (ptr != NULL) {
			counter++;
			cout << counter << ".  " << ptr->title << endl;
			cout << "    " << ptr->description << "\n" << endl;
			ptr = ptr->nextTopic;
		}
	}
	else {
		cout << "No Topics yet!" << endl;
	}
}

// display the items in the list
void TopicList::printPosts(string topic) {
	//Navigate to Topic
	TopicNode* ptr = firstNode;
	while (ptr->title != topic) { ptr = ptr->nextTopic; }
	ptr->posts->print();
}
