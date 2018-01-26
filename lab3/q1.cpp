#include<iostream>
using namespace std;

class Node /*contains data and pointers which point to the 
            *next and previous element in the list*/
{
    public:
        Node*next;
        Node*prev;
        int data;

        Node() //constructor => initialises the values//
        {
            data=0;
            next=NULL;
            prev=NULL;
        }
};

class DLinkedList /*contains a variable, a head and a tail pointer which 
                   *point to the first and last element in the list respectively*/
{
    public:
        Node*head;
        Node*tail;
        int c; //counter => used to count the no. of elements in the list//

        DLinkedList() //constructor//
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

void DLinkedList :: insert(int data) /*inserts a node at the end of the doubly 
                                      *linked list*/
{
    Node*temp=new Node; //creates a new node//
    temp->data=data; //to store data in the node//
    temp->next=NULL;

    if(head==NULL) //if the linked list is empty//
    {
        temp->prev=NULL;
        head=temp;
        tail=temp;
    }

    else //if the linked list is non-empty//
    {
        Node*p=head;
      
        while(p->next!=NULL)
        {
            p=p->next;
        }
      
        p->next=temp;
        temp->prev=p;
    }
    c++; //increases the no. of elements by 1 as a new node has been inserted//
}

void DLinkedList :: insertAt(int pos,int data) /*inserts a new node at any position 
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
        temp->prev=NULL;
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
		temp->prev=p;
		c++;
	}
}

void DLinkedList :: del() //deletes an element at the end of the list//
{
	Node*p=tail; //a pointer to temporarily store tail//
	tail=tail->prev;
	tail->next=NULL;
	delete p; //deletes the node p//
	c--; //as one node is now deleted, the no. of elements decreases by 1//
}

void DLinkedList :: deleteAt(int pos) //deletes at any position of the linked list//
{
	Node*p=head;
	
	if(pos>c) /*no node can be deleted as the position entered is more
	           *than the no. of elements in the linked list itself*/
	{
		cout<<"Not that many elements in the list dude!\n";
	}
	
	else if(pos==1)
	{
		Node*p=head;
		head=p->next;
		head->prev=NULL;
		delete p;
		c--;
	}
	
	else if(pos==c)
	{
		del();
	}
	
	else
	{
	    for(int i=1;i<pos;i++)
	    {
		    p=p->next;
	    }
	
	    (p->prev)->next=p->next;
	    (p->next)->prev=p->prev;
		c--;
	}
}

int DLinkedList :: countItems() /*no node can be deleted as the position entered is 
                                 *more than the no. of elements in the linked list 
								 *itself*/
{
	return c; //returns the value of c//
}

void DLinkedList :: display() //displays the elements of the list//
{
	Node*p=head;
	
	while(p!=NULL)
	{
		cout<<p->data<<"->";
		p=p->next;
	}
	
	cout<<"NULL\n";
}

int main()
{
	DLinkedList dl;
	
	for(int i=0;i<10;i++)
	{
		dl.insert(i+1);
	}
	
	dl.insertAt(4,8);
	dl.deleteAt(7);
	cout<<"The no. of items are "<<dl.countItems()<<"\n";
	dl.display();
	
	return 0;
}
