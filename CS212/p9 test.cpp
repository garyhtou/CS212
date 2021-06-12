// Original code from Daniel Liang (2003)
// now animated at yongdanielliang.github.io/animation/web/LinkedList.html
// 
// Extensively modified by W.P. Iverson
// Bellevue College, May 2020
// for CS212

#include <iostream>
#include <string>
#include "p9 LinkedList.h"
using namespace std;

int p9_1()
{
	// Create a list for strings
	LinkedList<string> list;
	list.add("Bellevue");
	list.add("Tofino");

	// Create another list for strings
	LinkedList<string> list2;
	list2.add("Bellevue");
	list2.add("Ellensburg");

	cout << "list: ";
	list.printList();

	cout << "list2: ";
	list2.printList();

	return 0;
}