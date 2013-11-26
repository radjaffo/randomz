void tree :: remove (int a)
{
	bool found = false;		//search part
	if(isEmpty())	//get out if the tree is empty
	{
		return;
	}
		node *start;			//initalize pointers
		node *parent;
		start = root;			//set start pointer to root of tree
		parent = (node*)NULL;
		while(start !=NULL)		//loop to find the value
		{
			if(start->value == a)
			{
			found = true;
				break;		//once found break out
			}
			else
			{
				parent = start;		//loop the tree until you find it
				if(a > start->value)
					start = start->rightchild;
				else
					start = start->leftchild;
			}
		}
	if(!found)
	{
		return;
	}
	//case 1: removing a node w/ a single child
	if((start->leftchild == NULL && start->rightchild != NULL) ||
	(start->leftchild != NULL && start->rightchild == NULL))
	{
		if(start->leftchild == NULL && start->rightchild != NULL)	//right child
		{
			if(parent->leftchild == start)
			{
				parent->leftchild = start->rightchild;
				delete start;
				start = NULL;

			}
			else
			{
				parent->rightchild = start->rightchild;
				delete start;
				start = NULL;
				
			}
		}
		else								//left child
		{
			if(parent->leftchild == start)
			{
				parent->leftchild = start->leftchild;
				delete start;

			}
			else
			{
				parent->rightchild = start->leftchild;
				delete start;
			}
		}
		return;
	}
	//Case 2: Removing a leaf node
	if( start->leftchild == NULL && start->rightchild == NULL)
	{
		if(parent == NULL)		//if its root
		{
			delete start;	
			root = NULL;
		}
		else
			if (parent->leftchild == start)
				parent->leftchild = NULL;
			else 
				parent->rightchild = NULL;
			delete start;
			return;
	}
	//Case 3: Removing w/ 2 children
	if( start->leftchild != NULL && start->rightchild != NULL)
	{
		node* temp;		//set a dummy pointer
		temp = start->rightchild;		//set to next right child
		if((temp->leftchild == NULL) && (temp->rightchild == NULL))	//if no grandchildren
		{
			start = temp;
			delete temp;
			start->rightchild = NULL;
		}
		else
		{
			if((start->rightchild)->leftchild != NULL)	//if left grandchild
			{
				node* temp2;
				node* temp3;
				temp3 = start->rightchild;
				temp2 = (start->rightchild)->leftchild;
				while(temp2->leftchild != NULL)		//loop down until you find the last
				{
					temp3 = temp2;
					temp2 = temp2->leftchild;
				}
				start->value = temp2->value;
				delete temp2;
				temp3->leftchild = NULL;
			}
			else						//if right grandchild
			{
				node* temp4;
				temp4 = start->rightchild;
				start->value = temp4->value;
				start->rightchild = temp4->rightchild;
				delete temp4;
			}
		}
	return;
	}
}			//hmm...
