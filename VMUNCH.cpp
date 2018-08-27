#include <bits/stdc++.h>
using namespace std;
const int dx[]={1,0,-1,0};
const int dy[]={0,1,0,-1};
bool visited[1000][1000]={0};
#define ii pair<int,int>
int main()
{
	queue<ii> q;
	ii endd;
	int n,m;
	char s[1000][1000];
	cin >> n >> m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin >> s[i][j];
			if(s[i][j]=='B')
			endd=make_pair(i,j);
			if(s[i][j]=='C')
			q.push(ii(i,j));
		}
	}
	int count=0;
	while(!q.empty())
	{
		count++;
		int len=q.size();
		for(int l=0;l<len;l++)
		{
			ii t=q.front();
			int i=t.first;
			int j=t.second;
			q.pop();
			for(int k=0;k<4;k++)
			{
				int x=i+dx[k];
				int y=j+dy[k];
				if(x<0||y<0||x>=n||y>=m||visited[x][y]==1||s[x][y]=='*')
				continue;
				visited[x][y]=1;
				if(x==endd.first&&y==endd.second)
				{
					cout << count;
					return 0;
				}
				q.push(ii(x,y));
			}
		}
	}
}
			
				
	
