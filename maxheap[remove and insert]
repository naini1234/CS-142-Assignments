#include<iostream>
using namespace std;
class maxHeap
{
	public:
	int heap[1000],len,i;
	maxHeap()
	{
		len=0;
		i=0;
	}
	void insert(int key)
	{
     		heap[len]=key;
		i=len;
		int par=(i-1)/2;
		while(heap[i]>heap[par])
		{
			swap(&heap[i],&heap[par]);
			i=par;
			par=(i-1)/2;
		}
		len++;
	}
	void swap(int *a,int *b)
	{
		int t=*a;
		*a=*b;
		*b=t;
	}
	void display()
	{
		for(int j=0;j<len;j++)
		{
			cout<<heap[j]<<endl;
		}
	}
	void remove()
	{
		int l=len-1,lc,rc,max=0,i=0;
		heap[i]=heap[l];
		len--;
		lc=(2*i)+1;
		rc=(2*i)+2;
		while(heap[i]<heap[rc]||heap[i]<heap[lc])
		{
			if(rc<len && lc<len)
			{
				max=maxValue(heap[rc],heap[lc]);
				if(heap[lc]==max)
				{
					swap(&heap[lc],&heap[i]);
					i=(2*i)+1;
				}
				else
				{
					swap(&heap[rc],&heap[i]);
					i=(2*i)+2;
				}
			}
			else
			{
					swap(&heap[lc],&heap[i]);
                                        i=(2*i)+1;
			}
			lc=(2*i)+1;
                	rc=(2*i)+2;
		}
	}
	int maxValue(int a,int b)
	{
		if(a<b)
			return b;
		else
			return a;
	}		
};

int main()
{
	maxHeap hp;
	int n,key;
	cout<<"Enter the number of elements of the heap"<<" ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>key;
		hp.insert(key);
	}
	cout<<"the elements of heap are:"<<endl; 
	hp.display();
	hp.remove();
	cout<<"the elements after removal is:"<<endl;
	hp.display();
}
