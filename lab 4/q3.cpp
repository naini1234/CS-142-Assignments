#include <iostream>
#include <string.h>
using namespace std;

int top, front;
class Issue
{
    public:
    char name[30];
    long int ph;
    char desc[100];
    Issue* link;
    Issue(){link=NULL;};
};

class StkPal
{
    public:
    char NM[30];
    /* push a character into stack */
    void push(char a)
   {
      top++;
      NM[top]  =  a;
   }
/* delete an element in stack */
   void pop()
   {
      top--;
   }
}stack;

class CustomerService
{
    public:
    Issue* head;
    Issue* tail;
    CustomerService()
    {
        head=NULL;
        tail=NULL;
    }
    int chkPalindrome(char nm[30]);
    void addIssue(char nm[30], long int p, char desc[]);
    void displayIssue();
};

/*Checking Palindrome Using Array STACK*/
int CustomerService::chkPalindrome(char nm[30])
{
   top=-1;
   front=0;
   char b;
   for (int i = 0;nm[i] != '\0';i++)
    {
          b = nm[i];
          stack.push(b);
    }
   for (int i = 0;i < (signed)(strlen(nm) / 2);i++)
    {
          if (stack.NM[top] == stack.NM[front])
          {
                stack.pop();
                front++;
          }
          else
          {
                return 0;
          }
    }
    int x=front;
    front  =  0;
    top  =  -1;
    if ((signed)(strlen(nm) / 2)==x)
      {    return 1;}
      return -1;
}


void CustomerService::addIssue(char nm[],long int p, char des[])
{
    Issue* temp=new Issue;
    temp->ph=p;
    strcpy(temp->name,nm);
    strcpy(temp->desc,des);
    if(head==NULL)
    {
      head=temp;
      tail=temp;
      return;
      
    }
    if(chkPalindrome(nm)==1)
    {
        temp->link=head;
        head=temp;
        
    }
    else
    {
        tail->link=temp;
        tail=temp;
        
    }
};
    
    

void CustomerService::displayIssue()
{
    Issue* iss;
    iss=head;
    if(iss==NULL)
    {
        cout<<"There is no registration done"<<endl;
    }
    else
    {
        cout<<"\nNAME \t \t PHONE \t \t\t Description \n";
        while(iss!=NULL)
        {
            cout<<"\n"<<iss->name<<" \t \t "<<iss->ph<<" \t \t "<<iss->desc;
            iss=iss->link;
        }
    }
    cout<<"\n \n \n";
}

int main()
{
    CustomerService CS;
    CS.displayIssue();
    CS.addIssue("ISSUE",9876543289,"Testing code");
    CS.displayIssue();
    CS.addIssue("ISSI",9905432893,"Code Testing");
    CS.displayIssue();
    CS.addIssue("ISS",9876847584,"PALINDROME STACK");
    CS.displayIssue();
    CS.addIssue("PRBLM",9876543289,"STACK PALINDROME");
    CS.displayIssue();
    CS.addIssue("PRORP",9876003289,"CODE SUCCESFUL");
    CS.displayIssue();
    CS.addIssue("PROB",7319103289,"SUCCESSFUL CODE");
    CS.displayIssue();
    CS.addIssue("TICKET",8093103289,"PDSL 2");
    CS.displayIssue();
    CS.addIssue("TICIT",9099803289,"2 PDSL");
    CS.displayIssue();
    CS.addIssue("TIIT",9009876546,"LAST ONE");
    CS.displayIssue();
    CS.addIssue("ENDNE",7890678987,"ONE LAST");
    CS.displayIssue();
    return 0;   
}
