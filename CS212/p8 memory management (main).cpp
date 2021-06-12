/* Code below started with C program by Vahid and Lysecky, Univ. of Arizona
   modified for CS212 students at Bellevue College
   for C++ linked list dynamic memory management
   by W.P. Iverson, instructor
   May 2020
*/
#include "p8 memory management (PersonNode).h"

int p8() {
	// Load nodes with data
	PersonNode* head = new PersonNode("Fred Davey", "240-555-2104");
	PersonNode* current = new PersonNode("Gerald Berger", "802-555-4986");
	PersonNode* copy = new PersonNode(current);
	copy->printPersonNode();
	cout << "finished first portion of code\n" << endl;

	// Create a linked list
	insertContactAfter(head, current);
	insertContactAfter(current, new PersonNode("John Hills", "212-555-9467"));
	insertContactAfter(head, new PersonNode("Second Person", "206-206-6020"));

	// Print contact list 
	cout << "CONTACT LIST:" << endl;
	current = head;
	while (current != NULL) { // linked list traversal
		current->printPersonNode();
		current = current->getNextContact();
		cout << endl;
	}
	cout << "finished display of whole list\n" << endl;

	// Function will confirm delete of each node
	deleteWholeList(head);
	copy->printPersonNode(); // should still exist
	//head->PrintPersonNode(); // cannot work after deleted
	cout << "after delete list" << endl;

	return 0;
}