void tree :: remove (int a)
{
	bool found = false;
	if(isEmpty())
	{
		return;
	}
		node *start;
		node *parent;
		start = root;
		parent = (node*)NULL;
		while(start !=NULL)
		{
			if(start->value == a)
			{
			found = true;
				break;
			}
			else
			{
				parent = start;
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
	
	if((start->leftchild == NULL && start->rightchild != NULL) || (start->leftchild != NULL && start->rightchild == NULL))
	{
		if(start->leftchild == NULL && start->rightchild != NULL)
		{
			if(parent->leftchild == start)
			{
				parent->leftchild = start->rightchild;
				delete start;

			}
			else
			{
				parent->rightchild = start->rightchild;
				delete start;
				
			}
		}
		else
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
	if( start->leftchild == NULL && start->rightchild == NULL)
	{
		if(parent == NULL)
		{
			delete start;
		}
		else
			if(parent->leftchild == start)
			parent->leftchild = NULL;
				else parent->rightchild = NULL;
				delete start;
				return;
	}
	if( start->leftchild != NULL && start->rightchild != NULL)
	{
		node* temp;
		temp = start->rightchild;
		if((temp->leftchild == NULL) && (temp->rightchild == NULL))
		{
			start = temp;
			delete temp;
			start->rightchild = NULL;
		}
		else
		{
			if((start->rightchild)->leftchild != NULL)
			{
				node* temp2;
				node* temp3;
				temp3 = start->rightchild;
				temp2 = (start->rightchild)->leftchild;
				while(temp2->leftchild != NULL)
				{
					temp3 = temp2;
					temp2 = temp2->leftchild;
				}
				start->value = temp2->value;
				delete temp2;
				temp3->leftchild = NULL;
			}
			else
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
}
