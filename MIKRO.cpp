#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
int n,x[10000],y[10000],d[10000],t=0,mint,maxt=0;
int cnt1[1000][1000]={0},cnt2[1000][1000]={0};
int main()
{
	freopen("MIKRO.INP","r",stdin);
	freopen("MIKRO.OUT","w",stdout);
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	//cout.tie(0);
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> x[i] >> y[i] >> d[i];
	}
	queue<ii> q;
	for(int i=0;i<n;i++)
	{
		q.push(ii(x[i],y[i]));
	}
	while(!q.empty())
	{
		int cnt1[1000][1000]={0},cnt2[1000][1000]={0};
		if(t>=100)
		break;
		ii u[1000];
		t++;
		for(int i=0;i<n;i++)
		{
			u[i]=q.front();
			q.pop();
		}
		for(int i=0;i<n;i++)
		{
			if(d[i]==1)
			{
				u[i].first-=1;
				u[i].second+=1;
			}
			else if(d[i]==2)
			{
				u[i].second+=1;
			}
			else if(d[i]==3)
			{
				u[i].first+=1;
				u[i].second+=1;
			}
			else if(d[i]==4)
			{
				u[i].first+=1;
			}
			else if(d[i]==5)
			{
				u[i].first+=1;
				u[i].second-=1;
			}
			else if(d[i]==6)
			{
				u[i].second-=1;
			}
			else if(d[i]==7)
			{
				u[i].first-=1;
				u[i].second-=1;
			}
			else if(d[i]==8)
			{
				u[i].first-=1;
			}
		}
		for(int i=0;i<n;i++)
		{
			if(u[i].first<0||u[i].second<0)
			{
			cnt2[abs(u[i].first)][abs(u[i].second)]++;
			 if(cnt2[abs(u[i].first)][abs(u[i].second)]>maxt)
		    {
		    	maxt=cnt2[abs(u[i].first)][abs(u[i].second)];
		    	mint=t;
			}
		   }
		    else
		    {
		    cnt1[u[i].first][u[i].second]++;
			if(cnt1[u[i].first][u[i].second]>maxt)
			{
			maxt=cnt1[u[i].first][u[i].second];
			mint=t;
		    }
		}
	}
		for(int i=0;i<n;i++)
		{
			q.push(ii(u[i].first,u[i].second));
		}
		
		}
		cout << maxt << "\n" << mint;
		return 0;
	}

