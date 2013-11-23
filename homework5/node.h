#ifndef NODE_H
#define NODE_H


using namespace std;

class node
{
	int value;
	node *next;
	node *previous;
	
	public:
	node(int);
	int getvalue();
	node* getnext();
	void setnext();
	void setnext(node* a);
	node* getprevious();
	void setprevious();
	void setprevious(node* a);	
	friend class dlink;
	
};
#endif

	