//we will use bfs to solve this problem.we can not use priority_queue,we must use two variable l and r.we use r to check if there is any heigt
//equal to the this height,and we use while(l<=r).if there is any hill which is higher than this hill,check=false.we do bfs for every x,y on the map,then count. 

#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
ii q[10000];
bool visited[1000][1000];
int n,m;
bool check[10000];
int a[1000][1000];
int res=0,ans=0;
void bfs(int X,int Y)
{
	int l=1,r=1,x,y;
	visited[X][Y]=1;
	q[1]=ii(X,Y);
	ii u;
	while(l<=r)
	{
		u=q[l++];
		for(int i=0;i<8;i++)
		{
			x=u.first+dx[i],y=u.second+dy[i];
			if(x<0||y<0||x>n||y>m) continue;
			if(visited[x][y]==0&&a[x][y]==a[X][Y])
			{
				q[++r]=ii(x,y);
				visited[x][y]=1;
			}
			else
			{
			 if(a[x][y]>a[X][Y]) check[res]=false;
			 }
		}
	}
}
int main()
{
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin >> a[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(visited[i][j]==0)
			{
			res++;
			check[res]=true;
			bfs(i,j);
			}
		}
	}
	for(int i=1;i<=res;i++)
	{
		if(check[i]) ans++;
	}
	cout << ans;
}
