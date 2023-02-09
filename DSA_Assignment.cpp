// DSA_Assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.//
/*
Members:
Xiao Yaojie (S10222764)
Lim Junquan Ryan (S10192609)

Group: Dr Pamela Fanclub
*/


#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream>
#include "List.h"
#include "Account.h"
#include "Topic.h"
#include "Dictionary.h"


// Main Menu: Menu displayed when the app is first run.
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

// Logged In Menu: Menu displayed after user has logged in.
void loggedInMenu()
{
	cout << endl;
	cout << "Welcome to Big Brain Forum\n";
	cout << "-------------------------------\n";
	cout << "1. View Topics					\n";
	cout << "2. Add Topic					\n";
	cout << "3. View My Posts				\n";
	cout << "0. Log Out						\n";
	cout << "-------------------------------\n";
	cout << "Enter option : ";
}

// Save Data File for Forum
void saveForum(List* forum)
{
	// Write to a file
	ofstream outForumFile("forumFile.txt");
	if (outForumFile.is_open()) {
		// For each topic
		for (int i = 1; i <= forum->getLength(); i++) {
			Topic* tempTopic = dynamic_cast<Topic*>(forum->returnAddress(forum->get(i)));
			outForumFile << ":t" << endl; // flag for topic
			outForumFile << tempTopic->getTitle() << endl;
			outForumFile << tempTopic->getDescription() << endl;
			// For each post in the current topic
			for (int j = 1; j <= tempTopic->getSubElements()->getLength(); j++) {
				Post* tempPost = dynamic_cast<Post*>(tempTopic->getSubElements()->returnAddress(tempTopic->getSubElements()->get(j)));
				outForumFile << ":p" << endl; // flag for post
				outForumFile << tempPost->getTitle() << endl;
				outForumFile << tempPost->getDescription() << endl;
				outForumFile << tempPost->getAccountName() << endl;
				outForumFile << tempPost->getPriority() << endl;
				outForumFile << tempPost->getSmileReaction() << endl;
				outForumFile << tempPost->getMehReaction() << endl;
				outForumFile << tempPost->getCryReaction() << endl;
				// For each reply in the current post
				for (int k = 1; k <= tempPost->getSubElements()->getLength(); k++) {
					Reply* tempReply = dynamic_cast<Reply*>(tempPost->getSubElements()->returnAddress(tempPost->getSubElements()->get(k)));
					outForumFile << ":r" << endl; // flag for reply
					outForumFile << tempReply->getTitle() << endl;
					outForumFile << tempReply->getDescription() << endl;
					outForumFile << tempReply->getAccountName() << endl;
				}
			}
		}
		outForumFile << endl;
		outForumFile.close();
	}
	else {
		cerr << "Unable to save file." << endl;
	}
}

// Save Data File for Accounts
void saveAccounts(Dictionary* accounts)
{
	ofstream outAccountFile("accountsFile.txt");
	if (outAccountFile.is_open()) {
		// For each account
		for (int i = 0; i < accounts->getLength(); i++) {
			string username = accounts->getAtIndex(i);
			string password = accounts->get(accounts->getAtIndex(i)).getPassword();
			outAccountFile << ":a" << endl; // flag for account
			outAccountFile << username << endl;
			outAccountFile << password << endl;
		}
		outAccountFile << endl;
		outAccountFile.close();
	}
	else {
		cerr << "Unable to save file." << endl;
	}
}

// Load Data File for Forum
void loadForum(List* forum)
{
	Topic* currentTopic = new Topic();
	Post* currentPost = new Post();
	
	//int numOfAccounts = 1;
	//#undef MAX_SIZE
	//#define MAX_SIZE numOfAccounts
	

	// Read from a file
	ifstream inForumFile("forumFile.txt");
	if (inForumFile.is_open()) {
		string line;
		while (getline(inForumFile, line)) {
			if (line == ":t") { // flag for topic
				string title;
				string description;
				getline(inForumFile, title);
				getline(inForumFile, description);
				forum->add(new Topic(title, description, forum->getLength() + 1)); // create new topic from data file
				currentTopic = dynamic_cast<Topic*>(forum->returnAddress(forum->get(forum->getLength() - 1)));
			}
			if (line == ":p") { // flag for post
				string title;
				string description;
				string accountName;
				string tempPriority;
				bool priority = tempPriority == "1" ? true : false;
				string tempSmileReaction;
				int smileReaction = stoi(tempSmileReaction);
				string tempMehReaction;
				int mehReaction = stoi(tempMehReaction);
				string tempCryReaction;
				int cryReaction = stoi(tempCryReaction);
				getline(inForumFile, title);
				getline(inForumFile, description);
				getline(inForumFile, accountName);
				getline(inForumFile, tempPriority);
				getline(inForumFile, tempSmileReaction);
				getline(inForumFile, tempMehReaction);
				getline(inForumFile, tempCryReaction);
				currentTopic->addSubElements(new Post(title, description, priority, smileReaction, mehReaction, cryReaction, currentTopic->getSubElements()->getLength() + 1, accountName)); // create new post from data file
				currentPost = dynamic_cast<Post*>(currentTopic->getSubElements()->returnAddress(currentTopic->getSubElements()->get(currentTopic->getSubElements()->getLength() - 1)));
			}
			if (line == ":r") { // flag for reply
				string title;
				string description;
				string accountName;
				getline(inForumFile, title);
				getline(inForumFile, description);
				getline(inForumFile, accountName);
				currentPost->addSubElements(new Reply(title, description, currentPost->getSubElements()->getLength() + 1, accountName)); // create new reply from data file
			}
		}
		inForumFile.close();
	}
	else {
		cerr << "Unable to load file." << endl;
	}
}

// Load Data File for Accounts
void loadAccounts(Dictionary* accounts)
{
	ifstream inAccountFile("accountsFile.txt");
	if (inAccountFile.is_open()) {
		string line;
		while (getline(inAccountFile, line)) {
			if (line == ":a") {
				string accountName;
				string password;
				getline(inAccountFile, accountName);
				getline(inAccountFile, password);
				accounts->add(accountName, Account(accountName, password));
			}
		}
		inAccountFile.close();
	}
	else {
		cerr << "Unable to save file." << endl;
	}
}

int main()
{
	// Declaration of the variables to be used
	List forum;
	Dictionary accounts;
	loadForum(&forum);
	loadAccounts(&accounts);
	
	Topic* currentTopic = new Topic();
	Post* currentPost;
	string smileReaction = "^_^";
	string mehReaction = "-.-";
	string cryReaction = "T.T";

	/*
	// Initialise sample topics
    forum.add(new Topic("Neuroscience", "Neuroscience is the scientific study of nervous systems. Articles involving neurology, brain science, neurobiology, psychology, computer science, artificial intelligence, statistics, prosthetics, neuroimaging, engineering, medicine, physics, mathematics, pharmacology, electrophysiology, biology, robotics and technology are listed here.", 1));
    forum.add(new Topic("Neurology", "Neurology is the study of the structure and diseases of the brain and the nervous system.", 2));
    forum.add(new Topic("Psychology", "Psychology is the scientific study of the human mind and its functions, especially those affecting behaviour in a given context.", 3));
    forum.add(new Topic("Artificial Intelligence", "Artificial Intelligence is the theory and development of computer systems able to perform tasks normally requiring human intelligence, such as visual perception, speech recognition, decision-making, and translation between languages.", 4));
    forum.add(new Topic("Genetics", "Genetics involves the study of heredity and the variation of inherited characteristics.", 5));
    forum.add(new Topic("Neurotechology", "Neurotechnology encompasses any method or electronic device which interfaces with the nervous system to monitor or modulate neural activity.", 6));

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
		mainMenu(); // display main menu
		cin >> mainOption;
		// Option 1: Login Account
		if (mainOption == 1)
		{
			string inputUsername;
			string inputPassword;
			cout << "\nEnter Username:	\n";
			cin >> inputUsername;
			cout << "\nEnter Password:	\n";
			cin >> inputPassword;

			Account identifiedAccount = accounts.get(inputUsername);
			if (!identifiedAccount.checkPassword(inputPassword)) // if password does not match
			{
				cout << "\nWrong password! \n";
				continue;
			}
			while (true) {
				int loggedInOption;
				loggedInMenu(); // display logged in menu
				cin >> loggedInOption;
				// Option 1 > 1: View Topics
				if (loggedInOption == 1)
				{
					cout << endl;
					if (!(forum.print())) {
						cout << "No topics yet." << endl;
					}
					else 
					{
						// View Specific Topic
						int topicSelected;
						cout << "\nEnter Topic Number (or 0 to Back): ";
						cin >> topicSelected;
						cout << endl;
						if (topicSelected != 0) {
							currentTopic = dynamic_cast<Topic*>(forum.returnAddress(forum.get(topicSelected)));
							currentTopic->printSubElements();
						}
						else {
							continue;
						}

						int viewOrAddPost;
						cout << "Press 1 to View Post." << endl;
						cout << "Press 2 to Add Post." << endl;
						cout << "Press 3 to Pin Post" << endl;
						cout << "Press 0 to Back." << endl;

						cin >> viewOrAddPost;

						// Option 1 > 1 > 1: View Specific Post
						if (viewOrAddPost == 1) {
							int postSelected;
							cout << "\nEnter Post Number (or 0 to Back): ";
							cin >> postSelected;
							cout << endl;
							if (postSelected != 0) {
								int postOption;
								currentPost = dynamic_cast<Post*>(currentTopic->getSubElements()->returnAddress(currentTopic->getSubElements()->get(postSelected)));
								cout << "Title: " << currentPost->getTitle() << endl;
								cout << "Description: " << currentPost->getDescription() << endl;
								cout << smileReaction << ": " << currentPost->getSmileReaction() << " | " << mehReaction << ": " << currentPost->getMehReaction() << " | " << cryReaction << ": " << currentPost->getCryReaction() << endl;
								currentPost->printSubElements();
								if (currentPost->getAccountName() == identifiedAccount.getUsername()) { 
									cout << "Press 1 to React to Post." << endl; 
									cout << "Press 2 to Reply to Post." << endl;
									cout << "Press 0 to Back." << endl;
									cout << endl;
								}
								cin >> postOption;
								// Option 1 > 1 > 1 > 1: React to Post
								if (postOption == 1) {
									int reactionOption;
									cout << "Press 1 to " << smileReaction << ", 2 to " << mehReaction << ", 3 to " << cryReaction << endl;
									cin >> reactionOption;
									// Add smile reaction
									if (reactionOption == 1) {
										currentPost->addSmileReaction();
									}
									// Add meh reaction
									else if (reactionOption == 2) {
										currentPost->addMehReaction();
									}
									// add cry reaction
									else if (reactionOption == 3) {
										currentPost->addCryReaction();
									}
									cout << smileReaction << ": " << currentPost->getSmileReaction() << " | " << mehReaction << ": " << currentPost->getMehReaction() << " | " << cryReaction << ": " << currentPost->getCryReaction() << endl;
								}
								// Option 1 > 1 > 1 > 2: Reply to post
								else if (postOption == 2) {
									string replyTitle;
									string replyDescription;
									cout;
									cin >> replyTitle;
									cout;
									cin >> replyDescription;
									currentPost->addSubElements(new Reply(replyTitle, replyDescription, (currentPost->getSubElements()->getLength()) + 1, identifiedAccount.getUsername()));
									cout << "Reply added successfully!";
								}
								else if (postOption == 0) {
									break;
								}
							}
							else {
								continue;
							}
						}
						// Option 1 > 1 > 2: Add Post in Specific Topic
						else if (viewOrAddPost == 2) {
							string title; 
							string description;
							cout << "Enter title for new post: ";
							cin >> title;
							cout << "Enter description for new post: ";
							cin >> description;
							currentTopic->addSubElements(new Post(title, description, (currentTopic->getSubElements()->getLength()) + 1, identifiedAccount.getUsername()));
						}
						// Option 1 > 1 > 3: Pin Post in Specific Topic
						else if (viewOrAddPost == 3) {
							int postToBePinned;
							cout << "Enter Post Number to be pinned: ";
							cin >> postToBePinned;
							currentPost = dynamic_cast<Post*>(currentTopic->getSubElements()->returnAddress(currentTopic->getSubElements()->get(postToBePinned)));
							currentPost->updatePriority();
							currentTopic->sortByPriorityAndSerial();
							currentPost->setTitle(currentPost->getTitle() + " (Pinned)");
						}
						// Option 1 > 1 > 0: Back
						else if (viewOrAddPost == 0) {
							break;
						}
						// Invalid Option
						else {
							cout << "\nYour option is invalid. Please enter a value between 0 to 5.	\n";
						}
					}	
				}
				// Option 1 > 2: Add Topic
				else if (loggedInOption == 2)
				{
					string title; 
					string description;
					cout << "Enter title for new topic: ";
					cin >> title;
					cout << "Enter description for new topic: ";
					cin >> description;
					forum.add(new Topic(title, description, forum.getLength() + 1));

					cout << "Topic added successfully!";
				}
				// Option 1 > 3: View My Posts (Edit/Delete Posts)
				else if (loggedInOption == 3)
				{
					int counter = 0;
					for (int i = 1; i <= forum.getLength(); i++) {
						Topic* tempTopic = (dynamic_cast<Topic*>(forum.returnAddress(forum.get(i))));
						for (int j = 1; j <= (*(tempTopic)->getSubElements()).getLength(); j++) {
							counter++;
							Post* tempPost = dynamic_cast<Post*>((*(tempTopic->getSubElements())).returnAddress((*(tempTopic->getSubElements())).get(j)));
							if ((*tempPost).getAccountName() == identifiedAccount.getUsername()) {
								string tempString = (*tempPost).getDescription();
								if (tempString.length() > 80) // if description longer than 80 char
								{
									tempString.resize(80); // truncate to 80 char and add ... behind
									cout << counter << ". \t\b\b\b\b" << (*tempPost).getTitle() << endl;
									cout << "\t\b\b\b\b" << tempString << "..." << endl;
								}
								else 
								{
									cout << counter << ". \t\b\b\b\b" << (*tempPost).getTitle() << endl;
									cout << "\t\b\b\b\b" << tempString << endl;
								}
							}
						}
					}
					// Option to Edit/Delete Post
					int editOrDelete;
					cout << "Press 1 to Edit Post." << endl;
					cout << "Press 2 to Delete Post." << endl;
					cin >> editOrDelete;
					if (editOrDelete == 1) 
					{
						// Use identifiedAccount to print all posts under the account owner
						string postToBeEdited;
						cout << "Enter title of the Post to be edited: ";
						cin >> postToBeEdited;
						//cin.ignore(numeric_limits<streamsize>::max(), '\n');
						// Print current description
						string newDescription;
						cout << "Enter new description for the Post: ";
						cin >> newDescription;
						for (int i = 1; i <= forum.getLength(); i++) {
							Topic* tempTopic = (dynamic_cast<Topic*>(forum.returnAddress(forum.get(i))));
							for (int j = 1; j <= (*(tempTopic)->getSubElements()).getLength(); j++) {
								Post* tempPost = dynamic_cast<Post*>((*(tempTopic->getSubElements())).returnAddress((*(tempTopic->getSubElements())).get(j)));
								if ((*tempPost).getTitle() == postToBeEdited) tempPost->setDescription(newDescription);
							}
						}
						cout << "Post has been successfully edited!";
					}
					else if (editOrDelete == 2)
					{
						// delete code
						string postToBeDeleted;
						cout << "Enter title of the Post to be edited: ";
						cin >> postToBeDeleted;
						for (int i = 1; i <= forum.getLength(); i++) {
							Topic* tempTopic = (dynamic_cast<Topic*>(forum.returnAddress(forum.get(i))));
							for (int j = 1; j <= (*(tempTopic)->getSubElements()).getLength(); j++) {
								Post* tempPost = dynamic_cast<Post*>((*(tempTopic->getSubElements())).returnAddress((*(tempTopic->getSubElements())).get(j)));
								if ((*tempPost).getTitle() == postToBeDeleted) tempTopic->getSubElements()->remove(j-1);
							}
						}
					}
				}
				// Option 1 > 0: Log Out
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
			saveForum(&forum);
			saveAccounts(&accounts);
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

			cout << "\nAccount successfully created!\n";
			saveForum(&forum);
			saveAccounts(&accounts);

			continue;
		}
		// Option 3: View Topics
		else if (mainOption == 3)
		{
			cout << endl;
			if (!(forum.print())) { // if no topics
				cout << "No topics yet." << endl;
			}
			else {
				int topicSelected;
				cout << "\nEnter Topic Number (or 0 to Back): ";
				cin >> topicSelected;
				cout << endl;
				if (topicSelected != 0) {
					currentTopic = dynamic_cast<Topic*>(forum.returnAddress(forum.get(topicSelected)));
					currentTopic->printSubElements();
				}
				else {
					continue;
				}

				int postSelected;
				cout << "\nEnter Post Number (or 0 to Back): ";
				cin >> postSelected;
				cout << endl;
				if (postSelected != 0) {
					currentPost = dynamic_cast<Post*>((*(currentTopic->getSubElements())).returnAddress((*(currentTopic->getSubElements())).get(postSelected)));
					cout << smileReaction << ": " << currentPost->getSmileReaction() << " | " << mehReaction << ": " << currentPost->getMehReaction() << " | " << cryReaction << ": " << currentPost->getCryReaction() << endl;
					currentPost->printSubElements();
				}
				else {
					continue;
				}
			}
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