#include <iostream>
using namespace std;
/*bubbleSort function to sort 
*the elements in ascending order
*and returns the  sorted array to the main function*/
int *bubbleSort(int arr[],int n ){
	int l=0;
	for(int i=0;i<n;i++){   //Comparision of each and every element with one another
		for(int j=i+1;j<n;j++){
			if(arr[j]<arr[i]){
				l=arr[j];
				arr[j]=arr[i];
				arr[i]=l;
			}
		}
	} 
	//Returning the array
	return arr;
}

int main() {
	int n,arr[n];
	cout<<"Enter the size of the array "<< endl;
	cin>>n;
	cout<<"Enter the elemnts in the array"<<endl;
	for(int i=0;i<n;i++){ //Inputing the elements in the array.
		cin>>arr[i];
	}
	//calling the bubbleSort function.
	int *p=bubbleSort(arr,n);
	cout<<"The sorted array is "<<endl;
	//printing the sorted array.
	for(int i=0;i<n;i++){
		cout<<*(p+i)<<endl;
	}
	return 0;
}
