#include<bits/stdc++.h>
using namespace std;
#define max 10000
int ara[max];
int tree[max];
int update(int idx,int val,int n)
{
	while(ind <= n)
	{
		tree[idx] += val;
		idx += (idx & -idx);
	}
	puts("");
}
int query(int idx)
{
	int sum = 0;
	while(idx > 0)
	{
		sum += tree[idx];
		idx -= (idx & -idx);
	}
	return sum;
}
void print(int *ara,int n)
{
	for(int i=1;i<=n;i++)
	{
		cout<<ara[i]<<" ";
	}
	puts("");
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>ara[i];
		update(i,ara[i],n);
	}
	print(ara,n);
	cout<<endl;
	update(3,3,n);
	print(ara,n);
	
}
