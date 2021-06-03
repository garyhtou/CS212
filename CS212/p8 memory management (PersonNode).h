/*
Gary Tou
Program 8: memory management
6/2/2021
*/

#pragma once
#include <string>
#include <iostream>

using namespace std;

class PersonNode {

public:
	PersonNode(std::string, std::string); // Constructor, 2 parameters
	PersonNode(const PersonNode*); // Constructor, copy
	~PersonNode(); // Destructor
	PersonNode* getNextContact(); // Return pointer next node
	void setNextContact(PersonNode*); // Set the next node
	void printPersonNode(); // Display string data of node
private:
	std::string contactName; // Name
	std::string contactPhoneNum; // Phone
	PersonNode* nextNode; // Link to next

};

void insertContactAfter(PersonNode*, PersonNode*); // adds a new node to the list

void deleteWholeList(PersonNode*); // deletes all nodes
