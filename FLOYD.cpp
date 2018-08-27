#include <stdio.h>
#include <queue>
#include <iostream>
using namespace std;
int n,m,k,w[1000][1000],dis[1000][1000],T[1000][1000];
vector<int> trace(int u, int v) {
    vector<int> path;
    do {
        path.push_back(u);
        u = T[u][v];
    } while (path.back() != v);
    return path;
}
int main()
{
	cin >> n >> m >> k;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dis[i][j]=100000000;
		}
	}
	for(int i=1;i<=n;i++)
	dis[i][i]=0;
	for(int i=0;i<m;i++)
	{
		int x,y,d;
		cin >> x >> y >> d;
		dis[x][y]=d;
		dis[y][x]=d;
		T[x][y]=y;
		T[y][x]=x;
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(dis[i][j]>dis[i][k]+dis[k][j])
				{
				dis[i][j]=dis[i][k]+dis[k][j];
				T[i][j]=T[i][k];
				}
			}
		}
	}
	for(int i=0;i<k;i++)
	{
		int x,y,z;
		cin >> z >> x >> y;
		if(z==0) cout << dis[x][y];
		else
		{
			vector<int> path=trace(x,y);
			cout << (int)path.size() << " ";
			for(int j=0;j<path.size();j++)
			cout << path[j] << " ";
		}
		cout << "\n";
	}
				
}
	
