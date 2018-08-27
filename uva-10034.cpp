#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
int root[10000];
int find(int i)
{
	if(root[i]==i)
	return i;
	else
	return root[i]=find(root[i]);
}
struct edge
{
	double u,v,w;
	
	bool operator < (const edge &p)const
	{
		return w < p.w;
	}
};
vector <edge> e;
double dist[1000][1000];
double krushkal(int n)
{
	double sum=0;
	sort(e.begin(),e.end());
	for(int i=0;i<n;i++)
	{
		root[i]=i;
	}
	for(int i=0;i<(int)e.size();i++)
	{
		int u=find(e[i].u);
		int v=find(e[i].v);
		if(u!=v)
		{
			root[v]=u;
			sum+=e[i].w;
		}
	}
	return sum;
}
int main()
{
	int test,n;
	while(cin >> test)
	{
		while(test--)
		{
			cin >> n;
			for(int i=0;i<n;i++)
			{
			cin >> dist[i][0] >> dist[i][1];
		    }
		    e.clear();
		    for(int i=0; i<n; i++)
            for(int j=i+1; j<n; j++)
            {
                edge data;
                data.u = i;
                data.v = j;
                data.w = sqrt(pow(dist[i][0]-dist[j][0], 2) + pow(dist[i][1]-dist[j][1], 2));
                e.push_back(data);
            }
            printf("%.2lf\n", krushkal(n));
            if(test)
            cout << "\n";
		}
	}
}
