// DSA_Assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
#include "List.h"
#include "Account.h"
#include "Topic.h"
#include "Dictionary.h"

void mainMenu()
{
	cout << endl;
	cout << "Welcome to Big Brain Forum	\n";
	cout << "-----------------------------------\n";
	cout << "1. Login Account					\n";
	cout << "2. Register Account				\n";
	cout << "3. View Topics						\n";
	cout << "4. View Assignment Report			\n";
	cout << "0. Exit							\n";
	cout << "-----------------------------------\n";
	cout << "Enter option : ";
}

void loggedInMenu()
{
	cout << endl;
	cout << "Welcome to Big Brain Forum\n";
	cout << "-------------------------------\n";
	cout << "1. View Topics					\n";
	cout << "2. Add Topic					\n";
	cout << "3. Add Post					\n";
	cout << "4. Edit Posts					\n";
	cout << "5. Delete Posts				\n";
	cout << "0. Log Out						\n";
	cout << "-------------------------------\n";
	cout << "Enter option : ";
}

void saveFile() 
{
	// Write to a file
	ofstream outFile("dataFile.txt");
	if (outFile.is_open()) {
		outFile << "Hello, world!" << endl;
		outFile.close();
	}
	else {
		cerr << "Unable to save file." << endl;
	}
}

void loadFile() 
{
	int numOfAccounts = 1;
	#undef MAX_SIZE
	#define MAX_SIZE numOfAccounts

	// Read from a file
	ifstream inFile("example.txt");
	if (inFile.is_open()) {
		std::string line;
		while (getline(inFile, line)) {
			cout << line << endl;
		}
		inFile.close();
	}
	else {
		cerr << "Unable to load file." << endl;
	}
}

int main()
{
	List forum;
	Dictionary accounts;
	Topic* currentTopic;
	Post* currentPost;

    forum.add(Topic("Medical", "All things Medical!"));
    forum.add(Topic("Engineering", "All things Engineering!"));
    forum.add(Topic("Coding", "All things Coding!"));
    forum.add(Topic("Sports", "All things Sports!"));
    forum.add(Topic("Physics", "All things Physics!"));
    forum.add(Topic("Media", "All things Media!"));

	/*
	forum.print();
	string currentTopic = forum.get(6);
	cout << currentTopic << endl;
	string currentPost = "";
	forum.addPost("Medical", "Cardiorespiratory", "Heart and Lungs", true, "Ryan");
	forum.printPosts(currentTopic);
	*/

	while (true) 
	{
		int mainOption;
		mainMenu();
		cin >> mainOption;
		// Option 1: Login Account
		if (mainOption == 1)
		{
			while (true) {
				string inputUsername;
				string inputPassword;
				cout << "\nEnter Username:	\n";
				cin >> inputUsername;
				cout << "\nEnter Password:	\n";
				cin >> inputPassword;
				Account identifiedAccount = accounts.get(inputUsername);
				if (identifiedAccount.checkPassword(inputPassword)) 
				{
					continue;
				}
				else 
				{
					cout << "Wrong password! Please try again. ";
				}
				int loggedInOption;
				loggedInMenu();
				cin >> loggedInOption;
				// Option 1: View Topics
				if (loggedInOption == 1)
				{
					cout << endl;
					forum.print();
				}
				// Option 2: Add Topic
				else if (loggedInOption == 2)
				{
					string title; 
					string description;
					cout << "Enter title for new topic: ";
					cin >> title;
					cout << "Enter description for new topic: ";
					cin >> description;
					forum.add(Topic(title, description));
				}
				// Option 3: Add Post
				else if (loggedInOption == 3)
				{

				}
				// Option 4: Edit Posts
				else if (loggedInOption == 4)
				{

				}
				// Option 5: Delete Posts
				else if (loggedInOption == 5)
				{

				}
				// Option 0: Log Out
				else if (loggedInOption == 0)
				{
					break;
				}
				// Invalid Option
				else
				{
					cout << "\nYour option is invalid. Please enter a value between 0 to 5.	\n";
				}
			}
		}
		// Option 2: Register Account
		else if (mainOption == 2)
		{
			string inputUsername;
			string inputPassword;
			cout << "\nEnter a Username:	\n";
			cin >> inputUsername;
			cout << "\nEnter a Password:	\n";
			cin >> inputPassword;

			accounts.add(inputUsername, Account(inputUsername, inputPassword));
		}
		// Option 3: View Topics
		else if (mainOption == 3)
		{
			cout << endl;
			forum.print();
			int topicSelected;
			cout << "Enter Topic Number: ";
			cin >> topicSelected;
			ForumElements temp = forum.get(topicSelected);
			ForumElements* ptr = forum.returnAddress(temp);
			currentTopic = dynamic_cast<Topic *>(ptr);
			currentTopic->printSubElements();
			currentTopic->addSubElements(Post("Title", "Desc"));
			currentTopic->printSubElements();
		}
		// Option 4: View Assignment Report	
		else if (mainOption == 4)
		{
			cout << "\nLink to DSA Assignment Report: Big Brain Forum	\n";
			cout << "https://tinyurl.com/bigbrainforum \n";
		}
		// Option 0: Exit
		else if (mainOption == 0)
		{
			cout << "\nThanks for being part of the Big Brain Forum. Bye!	\n";
			break;
		}
		// Invalid Option
		else 
		{
			cout << "\nYour option is invalid. Please enter a value between 0 to 4.	\n";
		}
	}
}