#include<iostream>
using namespace std;

class Node
{
	public:
	    int data;
	    Node*next;
	
	    Node()
	    {
		    data=0;
		    next=NULL;
	    }
};

class CLinkedList
{
	public:
	    int c;
	    Node*head;
	    Node*tail;
	
	    CLinkedList()
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

void CLinkedList :: insert(int data)
{
	Node*temp=new Node;
	temp->data=data;
	
	if(head==NULL)
	{
		head=temp;
		tail=temp;
	}
	
	else
	{
		temp->next=head;
		tail->next=temp;
		tail=temp;
	}
	
	c++;
}

void CLinkedList :: insertAt(int pos,int data)
{
	if(pos>c)
	{
		
	}
	
	else if(pos==c)
	{
		insert(data);
	}
	
	else if(pos==1)
	{
		Node*temp=new Node;
		temp->data=data;
		temp->next=head;
		tail->next=temp;
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
		c++;
	}
}

void CLinkedList :: del()
{
	Node*p=head;
	Node*q;
	
	for(int i=1;i<c;i++)
	{
		p=p->next;
	}
	
	q=p->next;
	p->next=head;
	delete q;
	c--;
}

void CLinkedList :: deleteAt(int pos)
{
	if(pos==c)
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

int CLinkedList :: countItems()
{
	return c;
}

void CLinkedList :: display()
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
