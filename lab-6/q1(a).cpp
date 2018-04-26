//Implementing binary search in array
#include <iostream>
using namespace std;

//Function to search an element of a sorted(ascending or descending) array.
int binarySearch(int a[50],int beg, int last,int num)
{
	
	while(beg<=last) //To run the loop till the end
	{
	int mid=(beg+last)/2; //The middle element is calculated each time during execution of loop.
	if(a[mid]==num)       //Checking if the number to be searched is the middle element .
   {
   	return mid+1;
   }
   else if(num<a[mid]) //Checking if the number is smaller than the middle element.
   {       if(a[0]<a[1])// To check whether the array is ascending or descending
   	{
   		last=mid-1;//If ascending this will be followed
   	}
   	else
   	 beg=mid+1; //If descending this will be followed
   }
   else //Checking if the number is greater than middle element
   {    
   	if(a[0]<a[1])//To check whether the array is ascending or descending
          {
          	beg=mid+1;//If ascending this will be followed
          }
          else
          last=mid-1;//If descending, this will be followed
   }
	}
	return -1;//To return -1 when the element is not in the array
}

//main function for implementation and execution
int main() {
int arr[100],n,num,pos;
cout<<"Enter the size of array:";
cin>>n;
cout<<n;
cout<<"\nEnter the elements of array in sorted order(ascending or descending).";
cout<<"\nThe array is:";
for (int i=0;i<n;i++) //entering the elements of array.
{
	cin>>arr[i];
	cout<<arr[i]<<" ";
}
cout<<"\nEnter the element to be searched:";
cin>>num;
cout<<num;

int beg=0;//initializing beg as 0 i.e the position of 1st element.
int last=n-1;//initializing end as n-1 i.e the position of last element.

pos=binarySearch(arr,beg,last,num);//Calling the funtion to do binary search.

if(pos==-1)//If the returned position is -1 then to print that the element is not found.
cout<<"\nThe element is not found.";
else
cout<<"\nElement found at "<<pos<<" th position";//printing the position of the element.

	return 0;
}	
