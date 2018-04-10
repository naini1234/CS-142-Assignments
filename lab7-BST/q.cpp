#include <iostream>
using namespace std;

struct node
{
	int data;
	node *par;
	node *left;
	node *right;
} *root;

class BST
{
      public:	
      BST()
      {
        root=NULL;
      };

      int insert(int x)
      {
	node *temp= new node;
	temp->data=x;
	temp->par=temp->left=temp->right=NULL;
	node *curr=new node;
	curr= root;
	if(root==NULL)
	{
	  root=temp;
	}
	else
	{
	  while(1)
	  {
	    if(x<curr->data)
	    {
	       if(curr->left==NULL)
	       {
	         temp->par=curr;
	         curr->left=temp;
	         break;
	       }
	       else
                   {
	         curr=curr->left;
	       }
	    }
	    else if(x>curr->data)
	    {
	      if(curr->right==NULL)
	      {
	         temp->par=curr;
	         curr->right=temp;
	         break;
	      }
	      else
      	      {
	         curr=curr->right;
	      }
	    }
             }
             return 0;
          }
      }

     int display(node *temp)
    {
      if(temp!=NULL)
      {
         display(temp->left);
         cout<<temp->data<<endl;
         display(temp->right);
      }
      return 0;
   }
 };
 
    int main() 
    {
      BST b;
      b.insert(15);
      b.insert(10);
      b.insert(30);
      b.display(root);
      return 0;
    }
