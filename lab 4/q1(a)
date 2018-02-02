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

class StackLL
{
    public:
    
        Node*head;

        StackLL()
        {
            head=NULL;
        }
        
        void push(int data)
        {
            Node*temp=new Node;
            temp->data=data;
            temp->next=NULL;

            if(head==NULL)
            {
                head=temp;
            }

            else
            {
                temp->next=head;
                head=temp;
            }
        }
        
        void pop()
        {
            if(head!=NULL)
            {
                Node*p=head;
                head=p->next;
                delete p;
            }
           
            else
                cout<<"Popping out from an empty stack!\n";
        }

        void show()
        {
            Node*p=head;

            while(p!=NULL)
            {
                cout<<p->data<<"->";
                p=p->next;
            }
           
            cout<<"NULL\n";
        }
};

int main()
{
    StackLL s;
    int c,data;

    while(1)
    {
        cout<<"-------------------------------------------\n";
        cout<<"\t\tSTACK USING LINKED LIST\n\n";
        cout<<"1:PUSH\n2:POP\n3:DISPLAY STACK\n4:EXIT\n";
        cout<<"Enter your choice(1-4):\n";
        cin>>c;

        switch(c)
        {
            case 1:
                cout<<"Enter the number to push:\n";
                cin>>data;
                s.push(data);
                break;

	    	case 2:
	        	s.pop();
                break;

            case 3:
                s.show();
	        	break;

            case 4:
	        	return 0;
                break;

	    default:
                cout<<"PLease enter correct choice(1-4)!\n";
                break;	
        }
    }

    return 0;
}
