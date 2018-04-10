#include <iostream>
using namespace std;
class node		
{
    public:
    int data;
    node *parent,*left,*right;
    node()		
    {
        data=0;
        parent=NULL;
        left=NULL;
        right=NULL;
    }
};
class BST		
{
    public:
    node *root=NULL;		
    int insert(int x)
     {
	node *temp= new node;
	temp->data=x;
	temp->parent=temp->left=temp->right=NULL;
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
	         temp->parent=curr;
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
	         temp->parent=curr;
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
   void del(int key, node* v)
{
  node* temp=root;
  if(v==NULL)
  {
    cout<<"\n \nElement not found !!!\nCan not delete the data entered !";
    return;
  }
  
  if(v->left==NULL && v->right==NULL)
  {
    node* par;
    par=v->parent;
    if(par->data>=v->data)
    {
      par->left=NULL;
    }
    else
      par->right=NULL;
    delete v;
    
  }
  else if((v->left==NULL || v->right==NULL ))
   {   
    if(v!=root)
    {
     node* par;
     node* ch;
     par=v->parent; 
     if(v->left==NULL)
      ch=v->right;
     else
      ch=v->left;

     if(par->data>=v->data)
     {
       par->left=ch;
       ch->parent=par;
     }
     else
     {
       par->right=ch;
       ch->parent=par;
     }
    }
    else
    {
        if(v->left==NULL)
          root=v->right;
        else
          root=v->left;
    }
   }
  else
  {
    node* maxleft;
    maxleft=v->left;
    while(maxleft->right!=NULL)
    {
      maxleft=maxleft->right;
    }
    
   if(maxleft->left==NULL)
   {
     v->data=maxleft->data;
     node* par=maxleft->parent;
     if(par->left==maxleft)
        par->left=NULL;
     else
        par->right=NULL;
   }
   else
   {
     v->data=maxleft->data;
     node* par=maxleft->parent;
     if(par->left==maxleft)
        par->left=maxleft->left;
     else
        par->right=maxleft->left;
   }

  }
}
    node *bsearch(node *v,int data)
    {
        node *temp=v,*p;
        if(v==NULL)
        {
            cout<<"Not Found\n";
            return NULL;
        }
        else
        {
            if(data < temp->data)
            p=bsearch(temp->left,data);
            else if(data > temp->data)
            p=bsearch(temp->right,data);
            else
            {
                cout<<"Found\n";
                return temp;
            }
            return p;
        }
    }
    void display(node *v)
    {
        if(v==NULL)
        return;
        display(v->left);
        cout<<v->data<<" ";
        display(v->right);
    }
};
int main()
{
    BST bst;
    int n,data;
    cout<<"Enter the number of entries"<<endl;
    cin>>n;
    cout<<"Enter data"<<endl;
    for(int i=1;i<=n;i++)
    {
        
        cin>>data;
        bst.insert(data);
    }
    bst.display(bst.root);
    cout<<"\n";
    cout<<"Enter the data you want to search\n";
    cin>>data;
    bst.bsearch(bst.root,data);
    cout<<"Enter the data you want to delete\n";
    cin>>data;
    node* q;
    q=bst.bsearch(bst.root,data);
    bst.del(data,q);
    cout<<"Tree after deletion"<<endl;
    bst.display(bst.root);
    
    return 0;
}
