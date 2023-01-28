// DSA_Assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include "TopicList.h"

void topicMenu()
{
	cout << endl;
	cout << "Welcome to the Discussion Forum\n";
	cout << "-------------------------------\n";
	cout << "1. View Posts on Topic			\n";
	cout << "2. Add Topic					\n";
	cout << "3. Remove Topic				\n";
	cout << "-------------------------------\n";
	cout << "Enter option : ";
}

void postMenu()
{
	cout << endl;
	cout << "Welcome to the Discussion Forum	\n";
	cout << "-----------------------------------\n";
	cout << "1. Display all the items in order	\n";
	cout << "2. Search for an item				\n";
	cout << "3. Add a new item					\n";
	cout << "4. Delete an item					\n";
	cout << "5. Display total number of items	\n";
	cout << "6. Display the height				\n";
	cout << "7. Check if tree is balanced		\n";
	cout << "0. Exit							\n";
	cout << "-----------------------------------\n";
	cout << "Enter option : ";
}

int main()
{
    TopicList topicList;
    topicList.add("Medical", "All things Medical!");
    topicList.add("Engineering", "All things Engineering!");
    topicList.add("Coding", "All things Coding!");
    topicList.add("Sports", "All things Sports!");
    topicList.add("Physics", "All things Physics!");
    topicList.add("Media", "All things Media!");

	topicList.print();
	string currentTopic = topicList.get(6);
	cout << currentTopic << endl;
	string currentPost = "";
	topicList.addPost("Medical", "Cardiorespiratory", "Heart and Lungs", true, "Ryan");
	topicList.printPosts(currentTopic);
}