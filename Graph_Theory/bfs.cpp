#include<bits/stdc++.h>
using namespace std;
bool visited[10000];
vector<int>adj[1000];
int level[1000];
void bfs(int start)
{
	memset(visited,false,sizeof(visited));
	visited[start] = true;
	queue<int>q;
	q.push(start);
	level[start] = 0;
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for(int i=0;i<adj[u].size();i++)
		{
			int v = adj[u][i];
			if(!visited[v])
			{
				visited[v] = true;
				level[v] = level[u]+6;
			//	cout<<level[v]<<" ";
				q.push(v);
			}
		}
	}
}
int main()
{
	int test;cin>>test;
	while(test--)
	{
	int node,edge;
	cin>>node>>edge;
	int x,y;
	for(int i=0;i<edge;i++)
	{
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	int start;cin>>start;
	bfs(start);
	for(int i=0;i<node;i++)
	{
		adj[i].clear();
		if(i+1 != start)
		{
			if(!visited[i+1])
			{
				cout<<"-1"<<" ";
			}
			else
			{
				cout<<level[i+1]<<" ";
			}
		}
	}
	cout<<endl;
}
}

