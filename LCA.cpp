#include <iostream>
using namespace std;
int parent[1000],h[1000];
int LCA(int u,int v)
{
if(h[u]<h[v])
swap(u,v);
while(h[u]>h[v])
u=parent[u];
while(u!=v)
{
u=parent[u];
v=parent[v];
}
return u;
}
int main()
{
	int t,c=0;
	cin >> t;
	while(t--)
	{
		c++;
		h[1]=1;
		int n;
		cin >> n;
        for(int i=1;i<=n;i++)
        {
			int m,x;
			cin >> m;
		    for(int j=0;j<m;j++)
		    {
				cin >> x;
				parent[x]=i;
				h[x]=h[i]+1;
			}
		}
		int q,u[1000],v[1000];
		cin >> q;
		for(int i=0;i<q;i++)
		{
			cin >> u[i] >> v[i];
		}
		cout << "Case" << " " << c << ":" << "\n";
		for(int i=0;i<q;i++)
		{
			cout << LCA(u[i],v[i]) << "\n";
		}
	}
}
