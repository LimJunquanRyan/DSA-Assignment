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

// add an item to the front of the list (depends on priority)
// pre : size < MAX_SIZE
// post: item is added to the front of the list
//       size of list is increased by 1
bool List::add(ItemType* item) {
	Node* newNode = new Node;
	newNode->item = item;
	newNode->next = NULL;
	if (!isEmpty()) { 
		Node* ptr = firstNode;
		Node* prev = nullptr;
		while (ptr->item->getPriority())
		{
			prev = ptr;
			ptr = ptr->next;
		}
		if (prev != nullptr) {
			prev->next = newNode;
			newNode->next = ptr;
		}
		else {
			newNode->next = firstNode;
			firstNode = newNode;
		}
	}
	else firstNode = newNode;
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
		while (ptr->next != NULL && ptr->item->getTitle() != item.getTitle()) {
			ptr = ptr->next;
		}
		if (ptr->item->getTitle() == item.getTitle()) { return ptr->item; }
	}
	return nullptr;
}

List::Node** List::getFirstNode() { return &firstNode; }

List::Node* List::SortedMerge(Node* a, Node* b) {
	Node* result = NULL;

	// Base cases
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);

	// Pick either a or b, and recur
	if (a->item->getPriority() && b->item->getPriority() || !(a->item->getPriority()) && !(b->item->getPriority())) {
		if (a->item->getSerial() >= b->item->getSerial()) {
			result = a;
			result->next = SortedMerge(a->next, b);
		}
		else {
			result = b;
			result->next = SortedMerge(a, b->next);
		}
	}
	else if (a->item->getPriority()) {
		result = a;
		result->next = SortedMerge(a->next, b);
	}
	else if (b->item->getPriority()) {
		result = b;
		result->next = SortedMerge(a, b->next);
	}
	return result;
}

void List::FrontBackSplit(Node* source,
	Node** frontRef, Node** backRef)
{
	Node* fast;
	Node* slow;
	slow = source;
	fast = source->next;

	// Advance 'fast' two nodes, and advance 'slow' one node
	while (fast != NULL) {
		fast = fast->next;
		if (fast != NULL) {
			slow = slow->next;
			fast = fast->next;
		}
	}

	// 'slow' is before the midpoint in the list, so split it in two at that point.
	*frontRef = source;
	*backRef = slow->next;
	slow->next = NULL;
}

void List::mergeSortbyPriorityAndSerial(Node** headRef) {
	Node* head = *headRef;
	Node* a;
	Node* b;

	// Base case -- length 0 or 1
	if ((head == NULL) || (head->next == NULL)) {
		return;
	}

	// Split head into 'a' and 'b' sublists
	FrontBackSplit(head, &a, &b);

	// Recursively sort the sublists
	mergeSortbyPriorityAndSerial(&a);
	mergeSortbyPriorityAndSerial(&b);

	// answer = merge the two sorted lists together
	*headRef = SortedMerge(a, b);
}
