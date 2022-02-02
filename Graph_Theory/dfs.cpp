//DFS
#include<bits/stdc++.h>
using namespace std;
vector<int>adj[101];
bool seen[101];
void dfs(int n)
{
	if(seen[n]) return;
	seen[n] = true;
	for(int i=0;i<adj[n].size();i++)
	{
		dfs(adj[n][i]);
	}
}
int main()
{
	int node,ed,x,y,start;
	cin>>node>>ed;
	for(int i=0;i<ed;i++)
	{
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	memset(seen,false,sizeof(seen));
	cin>>start;
	dfs(start);
	cout<<"Visited Node:"<<endl;
	for(int i=0;i<node;i++)
	{
		if(seen[i]) cout<<i<<endl;
	}
}

