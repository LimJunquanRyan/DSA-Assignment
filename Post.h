#pragma once
#include <string>
#include <iostream>
#include "List.h"
#include "Reply.h"
using namespace std;


class Post : public ForumElement {
private:
	List* replies;
	string accountName;
	int smileReaction;
	int mehReaction;
	int cryReaction;

public:
	// Default Constructor
	Post();

	// Destructor
	~Post();

	// Parameterized Constructor when adding in the main loop
	Post(string t, string d, int s, string a);

	// Parameterised Constructor when adding by loading into the application
	Post(string t, string d, bool p, int sR, int mR, int cR, int s, string a);

	// Gets Account Name
	string getAccountName();

	// Gets Number of Smile Reactions
	int getSmileReaction();

	// Increments Number of Smile Reactions by 1
	void addSmileReaction();

	// Sets Number of Smile Reactions to value passed
	void setSmileReaction(int num);

	// Gets Number of Meh Reactions
	int getMehReaction();

	// Increments Number of Meh Reactions by 1
	void addMehReaction();

	// Sets Number of Meh Reactions to value passed
	void setMehReaction(int num);

	// Gets Number of Cry Reactions 
	int getCryReaction();

	// Increments Number of Meh Reactions by 1
	void addCryReaction();

	// Sets Number of Cry Reactions to value passed
	void setCryReaction(int num);

	// Returns pointer to address of the replies List
	List* getSubElements();

	// Adds Reply object to the replies List
	void addSubElements(Reply* reply);

	// Prints all Reply objects under this Post
	void printSubElements();

	// Print Post Details
	void print() override;
};
