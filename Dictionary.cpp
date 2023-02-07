#include "Dictionary.h"

Dictionary::Dictionary() {
	size = 0; 
	for (int i = 0; i < MAX_SIZE; i++) {
		items[i] = NULL;
	}
}

Dictionary::~Dictionary() {
	for (int i = 0; i < MAX_SIZE; i++) {
		if (items[i] != NULL) {
			while (items[i]->next != NULL) {
				Node* remove = items[i];
				items[i] = items[i]->next;
				remove->next = NULL;
				delete remove;
			}
			items[i]->next = NULL;
			delete items[i];
		}
	}
}

int Dictionary::hash(KeyType key) {
	int total = 1;
	for (int i = 0; i < key.size(); i++) {
		int temp;
		if (isalpha(key[i])) {
			if (isupper(key[i])) {
				temp = ((int)key[i] - (int)'A');
			}
			else {
				temp = ((int)key[i] - (int)'a' + 26);
			}
			total = (total * 52 + temp) % MAX_SIZE;
		}
		else {
			temp = key[i] - 48;
			total = (total * 10 + temp) % MAX_SIZE;
		}
	}
	return total;
}

bool Dictionary::add(KeyType newKey, ValueType newItem) {
	int index = hash(newKey);
	Node* newNode = new Node;
	newNode->key = newKey;
	newNode->item = newItem;
	newNode->next = NULL;
	if (items[index] == NULL) { items[index] = newNode; }
	else {
		Node* current = items[index];
		if (current->key == newKey) { return false; }
		while (current->next != NULL) { 
			current = current->next; 
			if (current->key == newKey) { return false; }
		}
		current->next = newNode;
	}
	size++;
	return true;
}

void Dictionary::remove(KeyType key) {
	int index = hash(key);
	if (items[index] != NULL) {
		Node* prev = items[index];
		Node* remove = items[index];
		while (remove->key != key) {
			if (remove->next != NULL) { 
				prev = remove;
				remove = remove->next; }
			else { break; }
		}
		if (prev == remove) { items[index] = items[index]->next; }
		else { prev->next = remove->next; }
		remove->next = NULL;
		delete remove;
	}
	size--;
}

ValueType Dictionary::get(KeyType key) {
	int index = hash(key);
	ValueType item;
	Node* current = items[index];
	while (current->key != key) { current = current->next; }
	item = current->item;
	return item;
}

bool Dictionary::isEmpty() {
	if (size == 0) { return true; }
	else { return false; }
}

int Dictionary::getLength() { return 0; }

void Dictionary::print() {
	for (int i = 0; i < MAX_SIZE; i++) {
		if (items[i] != NULL) {
			Node* current = items[i];
			cout << current->key << ": " << current->item.getUsername() << endl;
			while (current->next != NULL) {
				current = current->next;
				cout << current->key << ": " << current->item.getUsername() << endl;
			}
		}
	}
}