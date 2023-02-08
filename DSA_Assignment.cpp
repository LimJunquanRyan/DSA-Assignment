// DSA_Assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.//

#include <iostream>
#include <string>
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

/*
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
		string line;
		while (getline(inFile, line)) {
			cout << line << endl;
		}
		inFile.close();
	}
	else {
		cerr << "Unable to load file." << endl;
	}
}
*/

int main()
{
	// Declaration of the variables to be used
	List forum;
	Dictionary accounts;
	Topic* currentTopic = new Topic();
	Post* currentPost;
	string smileReaction = "^_^";
	string mehReaction = "-.-";
	string cryReaction = "T.T";

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
		mainMenu();
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
			if (!identifiedAccount.checkPassword(inputPassword))
			{
				cout << "\nWrong password! \n";
				continue;
			}
			while (true) {
				int loggedInOption;
				loggedInMenu();
				cin >> loggedInOption;
				// Option 1: View Topics
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
						cout << "Press 0 to Back." << endl;

						cin >> viewOrAddPost;

						// Option 1: View Specific Post
						if (viewOrAddPost == 1) {
							int postSelected;
							cout << "\nEnter Post Number (or 0 to Back): ";
							cin >> postSelected;
							cout << endl;
							if (postSelected != 0) {
								int postOption;
								currentPost = dynamic_cast<Post*>((*(currentTopic->getSubElements())).returnAddress((*(currentTopic->getSubElements())).get(postSelected)));
								cout << currentPost->getTitle() << endl;
								cout << currentPost->getDescription() << endl;
								cout << smileReaction << ": " << currentPost->getSmileReaction() << " | " << mehReaction << ": " << currentPost->getMehReaction() << " | " << cryReaction << ": " << currentPost->getCryReaction() << endl;
								currentPost->printSubElements();
								cout << "Press 1 to " << endl;
								if (currentPost->getAccountName() == identifiedAccount.getUsername()) { cout << "Edit/Delete \n"; }
								cin >> postOption;
								// Option 1: React to Post
								if (postOption == 1) {
									currentPost->addSmileReaction();
									cout << "hi" << currentPost->getSmileReaction();
									//currentPost->addCryReaction();
									//currentPost->addMehReaction();
								}
								// Option 2: Reply to post
								else if (postOption == 2) {
									string replyTitle;
									string replyDescription;
									cout;
									cin >> replyTitle;
									cout;
									cin >> replyDescription;
									currentPost->addSubElements(new Reply(replyTitle, replyDescription, (currentPost->getSubElements()->getLength()) + 1, identifiedAccount.getUsername()));
								}
								else if (postOption == 0) {

								}
							}
							else {
								continue;
							}
						}
						// Option 2: Add Post in Specific Topic
						else if (viewOrAddPost == 2) {
							string title; 
							string description;
							cout << "Enter title for new post: ";
							cin >> title;
							cout << "Enter description for new post: ";
							cin >> description;
							currentTopic->addSubElements(new Post(title, description, (currentTopic->getSubElements()->getLength()) + 1, identifiedAccount.getUsername()));
						}
						// Option 0: Back
						else if (viewOrAddPost == 0) {
							break;
						}
						// Invalid Option
						else {
							cout << "\nYour option is invalid. Please enter a value between 0 to 5.	\n";
						}
					}	
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
					forum.add(new Topic(title, description, forum.getLength() + 1));
				}
				// Option 3: View My Posts (Edit/Delete Posts)
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
								if (tempString.length() > 80)
								{
									tempString.resize(80);
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
						// print current title
						// print new description
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

			continue;
		}
		// Option 3: View Topics
		else if (mainOption == 3)
		{
			cout << endl;
			if (!(forum.print())) {
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
	/*
	ofstream ofs("topic.txt");
	List* temp = new List();
	temp->add(new Post("Post1", "Desc", 1, "1"));
	ofs << temp;
	ofs.close();
	*/

	ifstream ifs("topic.txt");
	ifs >> Topic->posts;
	ifs.close();
}