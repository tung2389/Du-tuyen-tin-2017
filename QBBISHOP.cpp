#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
int n,m,p,q,s,t;
bool check[600][600],visited[600][600];
int count=0;
queue<ii> pq;
void process(int i, int j) {
	if(visited[i][j]==0) {
	visited[i][j] = 1;
	pq.push(ii(i,j));
	}
}
int main()
{
	cin >> n >> m >> p >> q >> s >> t;
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin >> u >> v;
		check[u-1][v-1]=1;
	}
	pq.push(ii(p-1,q-1));
	visited[p-1][q-1]=1;
	while(!pq.empty())
	{
		::count++;
		int len=pq.size();
		for(int k=0;k<len;k++)
		{
		ii tt=pq.front();
		int x=tt.first;
		int y=tt.second;
		pq.pop();
		if(x==s-1&&y==t-1)
		{
			cout << ::count-1;
			return 0;
		}
			for(int i=x-1, j=y-1; check[i][j]==0&&i>=0&&j>=0; i--,j--)
				process(i,j);
			for(int i=x+1, j=y+1; check[i][j]==0&&i<n&&j<n; i++,j++)
				process(i,j);
			for(int i=x+1, j=y-1; check[i][j]==0&&i<n&&j>=0; i++,j--)
				process(i,j);
			for(int i=x-1, j=y+1; check[i][j]==0&&i>=0&&j<n;i--,j++)
				process(i,j);
	
}
}
cout << "-1";
}

					
		
	
	
