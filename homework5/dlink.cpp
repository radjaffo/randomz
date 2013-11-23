#include <iostream>
#include <string>
#include "dlink.h"

using namespace std;

dlink :: dlink()					//double link constructor
{
	head = NULL;					//assign pointers to Null
	tail = NULL;
	current = NULL;
	ncounter = 0;					//set node counter to 0
}


void dlink :: error()					//function definition of primary program, checks for phrases
{


string cal;								//initialize variables
int x, cc = 0;

do{						//do while loop to keep program going until target phrase is entered
cout << endl << "list> ";
do{						//endless loop for error checking
cin >> cal;	
if(cal == "quit")		//conditional to exit program
{
	cc = 5;
	return;
}				
else if (cal == "addleft")	//exits first endless loop
{
	cin >> x;			//accept variables from user
	addleft(x);			//call addleft function
	cc = 5;
}
else if (cal == "addright")	//exits first endless loop
{
	cin >> x;			//accept variables from user
	addright(x);		//call addright function
	cc = 5;
}
else if (cal == "left")	//exits first endless loop
{
	left();			//call left function
	cc = 5;
}
else if (cal == "right")	//exits first endless loop
{
	right();		//call right function
	cc = 5;
}
else if (cal == "search")
{
	cin >> x;			//accept variables from user
	search(x);			//call search function
	cc = 5;
}
else if (cal == "print")
{
	print();			//call print function
}
else 
{
	cc = 3;
	cout << "Error! Incorrect entry" << endl << "list> ";}	// error check
}
while( cc !=5);		//endless loop until quit is entered
}
while(cal != "quit");		//exits the function when quit is entered
}

void dlink :: addleft(int a)	//function definition to add a node to the left
{
	node* temp;					//initalize a temporary node pointer for reassignment purposes
	if(current == NULL)			//if statement check to see if the list is empty
	{
		current = new node(a);	//create a new node
		current->setnext();		//nodes are empty, all pointers go to this spot
		current->setprevious();
		head = current;			//reassign head and tail
		tail = current;
		ncounter++;				//increment node counter
	}
		else					//if list isn't empty, insert a new node
		{
			temp = new node(a);				//initalize a new node
			if(current == head)				//conditional to check if we are at the head
			{
				temp->setnext(current);		//set temporary pointer next location to current(adding left)
				current->setprevious(temp);	//set previous pointer location to temp(adding left)
				head = temp;				//reassign head to this node
				ncounter++;					//increment node counter
			}
			else						
			{
				temp->setnext(current);				//set temporary pointer next location to current
				current = current->getprevious();	//shuffle current pointer
				current->setnext(temp);				//link current pointer with new temporary node
				temp->setprevious(current);			//link temporary pointer with current location
				current = temp->getnext();			//shuffle current pointer
				current->setprevious(temp);			//link current with new temporary node
				ncounter++;							//increment node counter
			}
		}
}

void dlink :: addright(int a)	//function definition to add a node to the right
{
	node* temp;					//initalize a temporary node pointer for reassignment purposes
	if(current == NULL)			//if statement to check to see if the list is empty
	{
		current = new node(a);	//create a new node
		current->setnext();		//nodes are empty, all pointers go to this spot
		current->setprevious();
		head = current;			//reassign head and tail
		tail = current;
		ncounter++;				//increment node counter
	}
		else					//if the list isn't empty, insert a new node
		{
			temp = new node(a);			//initalize a new node
			if(current == tail)			//if conditional to check if we are at the end
			{
			current->setnext(temp);		//set next pointer location to temp(adding right
			temp->setprevious(current);	//set temporary pointer previous location to current(adding right)
			tail = temp;				//reassign tail to this node
			ncounter++;					//increment node counter
			}
				else					
				{
				current = current->getnext();	
				temp->setprevious(current);
				temp->setnext(current);
				current = temp->getprevious();
				current->setnext(temp);
				ncounter++;
				}
		}
}


void dlink :: left()			//function definition to move the current pointer to the left
{
	if(current == head)			//if conditional to error check
		cout << "Error! Beginning of list reached." << endl;
	else
	{
		current = current->getprevious();	//reassign current pointer to the left node
		cout << current->getvalue() << endl;	//print the referenced value
	}
}

void dlink :: right()			//function definition to move the current pointer to the right
{
	if (current == tail)
		cout << "Error! End of list reached." << endl;
	else
	{
		current = current->getnext();		//reassign current pointer to the right node
		cout << current->getvalue() << endl;	//print the referenced value
	}
}

bool dlink :: search(int a)		//function definition to search for a node
{
	node* temp = head;			//set a temporary pointer to the start of the list
	for(int i=0; i < ncounter; i++)		//for loop to search the whole list
	{
		if (a == temp->getvalue())		//if you find it return boolean true
			return 1;
		else							//else return false
			return 0;
		temp = temp->getnext();			//go through the entire list
	}
}
			
			
void dlink :: print()			//function definition to print the lists
{
	node* temp = head;			//set a temporary pointer to the start of the list
	for(int i=0; i < ncounter; i++)		//for loop to search the whole list
	{
		cout << temp->getvalue();		//print the referenced value
		
		if ( temp == tail)				//if you are at the end, clear a line
			cout << endl;
		else
			cout << "-";				//else print a hyphen
		temp = temp->getnext();			//go through the entire list
	}
}