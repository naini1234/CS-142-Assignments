#include <iostream>
using namespace std;

// function to swap two elements
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
 
/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition (int arr[], int l, int h)
{
    int pivot = arr[h];    // pivot
    int i = (l - 1);  // Index of smaller element
 
    for (int j = l; j <= h-1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[h]);
    return (i + 1);
}

void quickSort(int arr[], int l, int h)
{
    if (l < h)
    {
        /* p is partitioning index, arr[p] is now
           at right place */
        int p = partition(arr, l, h);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, h);
    }
}
 
/* Function to print an array */
void printArray(int arr[], int n)
{
    
    for (int i=0; i < n; i++)
        cout<<arr[i]<<"\n";
}
 
// Driver program to test above functions
int main()
{
    int n,arr[n]; 
    cout<<"Enter the number of elements in an array";
    cin>>n;
    for(int i=0;i<n;i++)
    {
    	cin>>arr[i];
    }
    quickSort(arr, 0, n-1);
   cout<<"the Sorted array is"<<endl;
    printArray(arr, n);
    return 0;
}
