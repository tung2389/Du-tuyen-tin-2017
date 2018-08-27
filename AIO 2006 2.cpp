#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int a[100][100];
int ans=0;
int n,m;
bool visited[100][100];
int dist[100][100];
void dfs(int x,int y)
{
	if(x<1||y<1||x>n||y>m)
	return;
	for(int i=0;i<4;i++)
	{
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(a[x][y]>a[nx][ny] && dist[nx][ny]<dist[x][y]+1)
		{
			dist[nx][ny]=dist[x][y]+1;
			dfs(nx,ny);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("atlanin.txt","r",stdin);
	freopen("atlanout.txt","w",stdout);
	cin >> n >> m;
	int sx,sy;
	cin >> sx >> sy;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin >> a[i][j];
			dist[i][j]=-100;
		}
	}
	dist[sx][sy]=1;
	dfs(sx,sy);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			ans=max(ans,dist[i][j]);
		}
	}
	cout << ans << "\n";
}
