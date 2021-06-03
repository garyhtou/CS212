/*
Gary Tou
Program 8: memory management
6/2/2021
*/

#include "p8 memory management (PersonNode).h"

PersonNode::PersonNode(std::string name, std::string phone) {
	this->contactName = name;
	this->contactPhoneNum = phone;
}


PersonNode::PersonNode(const PersonNode* other) {
	this->contactName = other->contactName;
	this->contactPhoneNum = other->contactPhoneNum;
}


PersonNode::~PersonNode() {
	cout << "Called destructor" << endl;
}

PersonNode* PersonNode::getNextContact() {
	return this->nextNode;
}

void PersonNode::setNextContact(PersonNode* next) {
	this->nextNode = next;
}

void PersonNode::printPersonNode() {
	std::cout << "Name: " << this->contactName << std::endl << "Phone number: " << this->contactPhoneNum << std::endl;
}

void insertContactAfter(PersonNode* base, PersonNode* next) {
	if(base->getNextContact() == NULL) {
		base->setNextContact(next);
	}
	else {
		PersonNode* temp = base->getNextContact();
		base->setNextContact(next);
		next->setNextContact(temp);
	}
}

void deleteWholeList(PersonNode* head) {
	PersonNode* current = head;
	while (current->getNextContact() != NULL) {
		PersonNode* next = current->getNextContact();
		delete current;
		current = next;
	}
}
