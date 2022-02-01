//Disjoint Set to check if two nodes are connected or not.

#include <bits/stdc++.h>
using namespace std;

int root[101],n;

void makeset()
{
    for(int i=1; i<=n; i++)
        root[i] = i;
}

int find(int r)
{
    if(r == root[r])
         return r;
    return root[r] = find(root[r]);
}

void Union(int a, int b)
{
    int u = find(a);
    int v = find(b);

    if(u != v)
    {
        root[v] = u;
	}
	else return;
}
bool connected(int x,int y)
{
	return find(x) == find(y);
}
int main()
{

    makeset();

	makeset();
	Union(1,2);
	Union(2,3);
	cout<<connected(1,3); //returns tree;
  cout<<connected(1,4); //returns false;

}
