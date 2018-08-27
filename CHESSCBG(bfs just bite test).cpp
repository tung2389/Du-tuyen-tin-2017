#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
int dx[]={0,-1,0,1};
int dy[]={-1,0,1,0};
int amount=0,count=0,check=0;
string a[6],b[6];
bool visited[6][6];
void bfs(int i,int j)
{
	queue<ii> q;
	q.push(ii(i,j));
	while(!q.empty())
	{
		if(amount==0)
		break;
		if(check==1)
		break;
		::count++;
		int len=q.size();
		for(int d=0;d<len;d++)
		{
		if(amount==0)
		break;
		if(check==1)
		break;
		ii t=q.front();
		int n=t.first;
		int m=t.second;
		q.pop();
		for(int k=0;k<4;k++)
		{
		if(amount==0)
		break;
		if(check==1)
		break;
		int x=n+dx[k],y=m+dy[k];
		if(x<0||y<0||x>=4||y>=4||visited[x][y]) continue;
		if(a[x][y]=='1')
		{
			check=1;
			visited[x][y]=1;
			amount--;
			break;
		}
		q.push(ii(x,y));
		}
		
	}
	
}
}
int main()
{
	for(int i=0;i<4;i++)
	{
		cin >> a[i];
	}
	for(int i=0;i<4;i++)
	{
		cin >> b[i];
		for(int j=0;j<4;j++)
		{
			if(b[i][j]=='1')
			amount++;
		}
	}
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(b[i][j]=='1')
			{
				if(a[i][j]=='1')
				{
				visited[i][j]=1;
				amount--;
			   }
		}
	}
}
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(b[i][j]=='1'&&a[i][j]!='1')
			{
			bfs(i,j);
			}
			check=0;
		}
	}
	cout << ::count;
}
			
			
	
 
