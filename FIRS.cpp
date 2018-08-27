#include <bits/stdc++.h>
using namespace std;
int n;
bool KILL[100010];
#define ii pair<int,int>
#define vii vector<ii>
priority_queue<ii,vii,greater<ii> > pq;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin >> x;
		pq.push(ii(x,i));
	}
	KILL[0]=1;
	KILL[n+1]=1;
	while(!pq.empty())
	{
		int v=pq.top().second;
		pq.pop();
		if(KILL[v]==0)
		{
			KILL[v]=1;
			KILL[v+1]=1;
			KILL[v-1]=1;
			ans++;
		}
	}
	cout << ans;
}
