#ifndef DLINK_H			//if statement to include dlink.h only when needed
#define DLINK_H
#include "node.h"		//link node.h

using namespace std;

class dlink				//set up class for double linked lists
{
	int ncounter;		//initalize private variables
	node* head;			//initalize private pointers
	node* tail;
	node* current;
	
	public:
	
	dlink();				//dlink constructor
	void error();			//main function call
	void addleft(int a);	//function to add a node to the left
	void addright(int a);	//function to add a node to the right
	void left();			//function to move the current pointer to the left
	void right();			//function to move the current pointer to the right
	bool search(int a);		//function to search for a node
	void print();			//function to print the nodes
	friend class node;		//link node and dlink
};
#endif