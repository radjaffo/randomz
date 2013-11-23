#include <iostream>		//load libraries
#include <string>
#include "node.h"		//link node.h

using namespace std;	

node :: node(int a)		//node constructor
{
	value = a;			//set value to argument
	previous = NULL;	//set pointers to NULL
	next = NULL;
}

int node :: getvalue()			//function definition to see private number
{
	return value;
}

node* node :: getnext()			//function definition to see private pointer
{
	return next;
}

void node :: setnext()			//function definition to set a private pointer
{
	next = NULL;
}

void node :: setnext(node *a)	//function definition to set a the private next pointer
{
	next = a;
}


node* node :: getprevious()		//function definition to see the private previous pointer
{
	return previous;
}

void node :: setprevious()		//function definition to set the private previous pointer
{
	previous = NULL;
}

void node :: setprevious(node *a)	//function definition to set the private previous pointer
{
	previous = a;
}