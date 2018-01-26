#include<iostream>
using namespace std;

class Node
{
    public:
        Node*next;
        Node*prev;
        int data;

        Node()
        {
            data=0;
            next=NULL;
            prev=NULL;
        }
};

class DLinkedList
{
    public:
        Node*head;
        Node*tail;
        int c;

        DLinkedList()
        {
            head=NULL;
            tail=NULL;
            c=0;
        }

        void insert(int data);
        void insertAt(int pos,int data);
        void del();
        void deleteAt(int pos);
        int countItems();
        void display();
};

void DLinkedList :: insert(int data)
{
    Node*temp=new Node;
    temp->data=data;
    temp->next=NULL;

    if(head==NULL)
    {
        temp->prev=NULL;
        head=temp;
        tail=temp;
    }

    else
    {
        Node*p=head;
      
        while(p->next!=NULL)
        {
            p=p->next;
        }
      
        p->next=temp;
        temp->prev=p;
    }
    c++;
}

void DLinkedList :: insertAt(int pos,int data)
{
    if(pos==c)
    {
        insert(data);
    }

    else if(pos==1)
    {
    	Node*temp=new Node;
    	temp->data=data;
        temp->next=head;
        temp->prev=NULL;
        head=temp;
        c++;
    }
    
    else
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

void DLinkedList :: del()
{
	Node*p=tail;
	tail=tail->prev;
	tail->next=NULL;
	delete p;
	c--;
}

void DLinkedList :: deleteAt(int pos)
{
	Node*p=head;
	
	if(pos==1)
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

int DLinkedList :: countItems()
{
	return c;
}

void DLinkedList :: display()
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
