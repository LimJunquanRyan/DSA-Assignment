#include "List.h"

List::List() {	// constructor
	firstNode = NULL;
	size = 0; 
}			

List::~List() {	// destructor
	while (!isEmpty()) {
		remove(0);
	}
} 

// add an item to the back of the list (append)
// pre : size < MAX_SIZE
// post: item is added to the front of the list
//       size of list is increased by 1
bool List::add(ItemType* item) {
	Node *newNode = new Node;
	newNode->item = item;
	newNode->next = NULL;
	if (!isEmpty()) { newNode->next = firstNode; }
	firstNode = newNode;
	size++;
	return true;
}

// remove an item at a specified position in the list
// pre : 0 <= index < size
// post: item is removed the specified position in the list
//       items after the position are shifted forward by 1 position
//       size of list is decreased by 1
void List::remove(int index) {
	if (0 <= index and index <= size) {
		if (index == 0) {
			Node* remove = firstNode;
			firstNode = firstNode->next;
			remove->next = NULL;
			delete remove;
		}
		else {
			Node* current = firstNode;
			Node* previous = NULL;
			for (index; index > 0; index--) {
				previous = current;
				current = current->next;
			}
			previous->next = current->next;
			current->next = NULL;
			delete current;
		}
		size--;
	}
}

// get an item at a specified position of the list (retrieve)
// pre : 0 <= index < size
// post: none
// return the item in the specified index of the list
ItemType List::get(int index) {
	ItemType item;
	if (0 <= index and index <= size) {
		Node* ptr = firstNode;
		for (index; index - 1 > 0; index--) { ptr = ptr->next; }
		return *(ptr->item);
	}
	else { return item; }
}

// check if the list is empty
// pre : none
// post: none
// return true if the list is empty; otherwise returns false
bool List::isEmpty() {
	if (size == 0) { return true; }
	else { return false; }
}

// check the size of the list
// pre : none
// post: none
// return the number of items in the list
int List::getLength() { return size; }

//------------------- Other useful functions -----------------

// display the items in the list
bool List::print() {
	if (firstNode != NULL) {
		Node* ptr = firstNode;
		int counter = 0;
		while (ptr != NULL) {
			string temp = (*(ptr->item)).getDescription();
			counter++;
			if (temp.length() > 80)
			{
				temp.resize(80);
				cout << counter << ". \t\b\b\b\b" << (*(ptr->item)).getTitle() << endl;
				cout << "\t\b\b\b\b" << temp << "..." << endl;
			}
			else
			{
				cout << counter << ". \t\b\b\b\b" << (*(ptr->item)).getTitle() << endl;
				cout << "\t\b\b\b\b" << temp << endl;
			}
			ptr = ptr->next;
		}
		return true;
	}
	return false;
}

ForumElement* List::returnAddress(ItemType item) {
	if (firstNode != NULL) {
		Node* ptr = firstNode;
		while (ptr->next != NULL && (*(ptr->item)).getTitle() != item.getTitle()) {
			ptr = ptr->next;
		}
		if ((*(ptr->item)).getTitle() == item.getTitle()) { return  (ptr->item); }
	}
	else return nullptr;
}
