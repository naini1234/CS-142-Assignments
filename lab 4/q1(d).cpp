#include <iostream>
using namespace std;
class Queue		//class Queue using arrays
{
 public:
 int i=0,t=0;
 int a[100];
 void enQueue(int x)		//adds element to the end of the queue
 {
  a[i]=x;
  i++;
 }
 int deQueue()		//returns the last element
 {
  return a[0];
 }
 void display(int n,int p)		//displays the queue
 {
  t=p;
  for(int j=t;j<n;j++)
  {
   cout<<a[j]<<"->";
  }
  cout<<"NULL"<<endl;
 }
};
int main()
{
 int n;
 //object creation and functions calling
 Queue q1;
 cout<<"Enter the number of entries you want to make\n";
 cin>>n;
 for(int i=0;i<n;i++)
 {
  
  
    q1.enQueue(i+1);
 }
 
 q1.display(n,0);
 
 q1.enQueue(7);
 
 q1.display((n+1),0);
 q1.deQueue();

 
 q1.display((n+1),1);
}
