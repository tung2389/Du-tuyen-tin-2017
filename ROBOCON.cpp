#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int> 
const int dx1[]={1,1,0};
const int dy1[]={0,1,1};
const int dx2[]={1,1,0};
const int dy2[]={0,-1,-1};
int n,k,cnt=0,vis1[2000][2000]={0},vis2[2000][2000]={0};
bool check[2000][2000];
int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin >> n >> k;
if(n==1)
cout << "0";
else
{
for(int i=0;i<k;i++)
{
	int x,y;
	cin >> x >> y;
	check[x][y]=1;
}
queue<ii> q;
q.push(ii(1,1));
while(!q.empty())
{
	cnt++;
	int len=q.size();
	for(int i=0;i<len;i++)
	{
		ii t=q.front();
		int u=t.first;
		int v=t.second;
		q.pop();
		for(int k=0;k<3;k++)
		{
			int x=u+dx1[k];
			int y=v+dy1[k];
			if(x<=0||y<=0||x>n||y>n||check[x][y]==1||vis1[x][y]) continue;
			vis1[x][y]=cnt;
			q.push(ii(x,y));
		}
}
}
while(!q.empty())
q.pop();
cnt=0;
q.push(ii(1,n));
while(!q.empty())
{
	cnt++;
	int len=q.size();
	for(int i=0;i<len;i++)
	{
		ii t=q.front();
		int u=t.first;
		int v=t.second;
		q.pop();
		for(int k=0;k<3;k++)
		{
			int x=u+dx2[k],y=v+dy2[k];
			if(x<=0||y<=0||x>n||y>n||check[x][y]==1||vis2[x][y]) continue;
			vis2[x][y]=cnt;
			q.push(ii(x,y));
		}
}
}
int ans=300000;
for(int i=1;i<=n;i++)
{
	for(int j=1;j<=n;j++)
	{
		if(i==1&&j==1||i==1&&j==n)
		continue;
		else if(vis1[i][j]==vis2[i][j]&&vis1[i][j]!=0&&vis2[i][j]!=0&&check[i][j]==0)
		{
		ans=min(ans,vis1[i][j]);
	}
}
}
cout << ans;
}
}

