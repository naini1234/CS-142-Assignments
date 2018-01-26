#include<iostream>
using namespace std;

class Node /*contains data and a pointer which points to the 
            *next element in the list*/
{
	public:
	    int data;
	    Node*next;
	
	    Node() //constructor => initialises the values//
	    {
		    data=0;
		    next=NULL;
	    }
};

class CLinkedList /*contains a variable, a head and a tail pointer which 
                   *point to the first and last element in the list respectively*/
{
	public:
	    int c; //counter => used to count the no. of elements in the list//
	    Node*head;
	    Node*tail;
	
	    CLinkedList() //constructor//
	    {
		    head=NULL;
		    tail=NULL;
		    c=0;
	    }
	
	/*calling the member functions*/
	    
		void insert(int data);
	    void insertAt(int pos,int data);
	    void del();
	    void deleteAt(int pos);
	    int countItems();
	    void display();
};

void CLinkedList :: insert(int data) /*inserts a node at the end of the circular 
                                      *linked list*/
{
	Node*temp=new Node; //creates a new node//
	temp->data=data; //to store data in the node//
	
	if(head==NULL) //if the linked list is empty//
	{
		head=temp;
		tail=temp;
	}
	
	else //if the linked list is non-empty//
	{
		temp->next=head;
		tail->next=temp;
		tail=temp;
	}
	
	c++; //increases the no. of elements by 1 as a new node has been inserted//
}

void CLinkedList :: insertAt(int pos,int data) /*inserts a new node at any position 
                                                *in the linked list*/
{
	if(pos>c) /*no node can be inserted as the position entered is more
	           *than the no. of elements in the linked list itself*/
	{
		cout<<"Not that many elements in the list dude!\n";
	}
	
	else if(pos==c) //to insert the node at the end of the list//
	{
		insert(data); //calling the insert function in the insertAt function//
	}
	
	else if(pos==1) //to insert at the first position//
	{
		Node*temp=new Node;
		temp->data=data;
		temp->next=head;
		tail->next=temp;
		head=temp;
		c++;
	}
	
	else //to insert at any position between the first and the last position//
	{
		Node*temp=new Node;
		temp->data=data;
		Node*p=head;
		
		for(int i=1;i<pos;i++)
		{
			p=p->next;
		}
		
		temp->next=p->next;
		p->next=temp;
		c++;
	}
}

void CLinkedList :: del() //deletes an element at the end of the list//
{
	Node*p=head; //a pointer to temporarily store head//
	Node*q;
	
	for(int i=1;i<c;i++)
	{
		p=p->next;
	}
	
	q=p->next;
	p->next=head;
	delete q; //deletes the node q//
	c--; //as one node is now deleted, the no. of elements decreases by 1//
}

void CLinkedList :: deleteAt(int pos) //deletes at any position of the linked list//
{
	if(pos>c) /*no node can be deleted as the position entered is more
	           *than the no. of elements in the linked list itself*/
	{
		cout<<"Not that many elements in the list dude!\n";
	}
	
	else if(pos==c)
	{
		del();
	}
	
	else if(pos==1)
	{
		Node*p=head;
		head=p->next;
		tail->next=p->next;
		delete p;
		c--;
	}
	
	else
	{
		Node*p=head;
		Node*q;
		
		for(int i=1;i<pos;i++)
		{
			p=p->next;
		}
		
		q=p->next;
		p->next=q->next;
		delete q;
		c--;
	}
}

int CLinkedList :: countItems() //counts the no. of elements in the linked list//
{
	return c; //returns the value of c//
}

void CLinkedList :: display() //displays the elements of the list//
{
	Node*p=head;
	
	for(int i=1;i<c;i++)
	{
		cout<<p->data<<"->";
		p=p->next;
	}
	
	cout<<p->data<<"\n";
}

int main()
{
	CLinkedList cl;
	
	for(int i=0;i<10;i++)
	{
		cl.insert(i+1);
	}
	
	cl.insertAt(6,9);
	cl.deleteAt(3);
	cl.display();
	cout<<"The number of elements in the circular linked list are "<<cl.countItems()<<"\n";
	
	return 0;
}
