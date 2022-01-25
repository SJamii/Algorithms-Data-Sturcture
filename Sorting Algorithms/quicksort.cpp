Time Complexity: O(n2)
Space Complexity: O(logn)

#include<bits/stdc++.h>
using namespace std;
int partition(int ara[],int low,int high)
{
	int i = low-1;
	int pivot = ara[high];
	for(int j=low;j<high;j++)
	{
		if(ara[j] <= pivot)
		{
			i++;
			swap(ara[i],ara[j]);
		}
	}
	swap(ara[i+1],ara[high]);
	return (i+1);
}
void quicksort(int ara[],int low,int high)
{
	if(low<high)
	{
		int pi = partition(ara,low,high);
		quicksort(ara,low,pi-1);
		quicksort(ara,pi+1,high);
	}
}
int main()
{
	int n; cin>>n;
	int ara[n+5];
	for(int i=0;i<n;i++)
	{
		cin>>ara[i];
	}
	quicksort(ara,0,n-1);
	for(int i=0;i<n;i++)
	{
		cout<<ara[i]<<" ";
	}
}

    
