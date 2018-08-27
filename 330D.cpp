#include <bits/stdc++.h>
using namespace std;
long long dx[]={0,1,0,-1};
long long dy[]={1,0,-1,0};
long long dpos=99999999999;
pair<long long,long long> a[1010][1010];
char s[1010][1010];
long long visited[1010][1010];
long long n,m;
#define ii pair<long long,long long> 
int main()
{
	cin >> n >> m;
	memset(visited,0,sizeof(visited));
	long long endx,endy;
	for(long long i=1;i<=n;i++)
	{
		for(long long j=1;j<=m;j++)
		{
			cin >> s[i][j];
			if(s[i][j]=='E')
			{
				endx=i;
				endy=j;
			}
		}
	}
	long long ans=0;
	queue<pair<long long,long long> > q;
	q.push(ii(endx,endy));
	bool ok=false;
	visited[endx][endy]=1;
	while(!q.empty() && ok==false)
	{
		if(ok==true)
		break;
		long long k=q.size();
		for(long long i=0;i<k;i++)
		{
			ii t=q.front();
			q.pop();
			long long x=t.first;
			long long y=t.second;
			for(long long j=0;j<4;j++)
	        {
			long long newx=x+dx[j];
			long long newy=y+dy[j];
			if(visited[newx][newy]==0)
			{
			if(s[newx][newy]!='0' && s[newx][newy]!='E' && s[newx][newy]!='T' && s[newx][newy]!='S')
			{
				char c[1];
				c[0]=s[newx][newy];
				ans+=atoi(c);
				//cout << atoi(c) << "\n";
			}
			else if(s[newx][newy]=='S')
			{
				ok=true;
			}
			if(s[newx][newy]!='T' && newx>0 && newy>0 && newx<=n && newy<=m)
			{
			q.push(ii(newx,newy));
			visited[newx][newy]=1;
		    }
		    }
		}
		}
	}
	cout << ans << "\n";
}
