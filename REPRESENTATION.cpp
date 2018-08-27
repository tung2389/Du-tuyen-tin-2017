#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
int a[11];
int k,n;
int cntnum(int x)
{
	int res=0;
	while(x!=0)
	{
		res++;
		x=x/10;		
	}
	return res;
}
int bfs(int x)
{
	queue<pair<int,int> > q;
	int t1=k*10+k;
	int t2=k*100+k*10+k;
	int t3=k*1000+t2;
	q.push(ii(k,1));
	q.push(ii(t1,2));
	q.push(ii(t2,3));
	q.push(ii(t3,4));
	int cnt=0;
	bool ok=false;
	int res=9999999;
	while(!q.empty())
	{
		if(ok)
		{
			if(res>8)
			{
				return -1;
				break;
			}
			else 
			return res;
		}
		int len=q.size();
		for(int i=0;i<len;i++)
		{
			ii t=q.front();
			q.pop();
			int num=t.first;
			int cntnum=t.second;
			if(num==x)
			{
				res=min(res,cntnum);
				ok=true;
			}
			q.push(ii(num*k,cntnum+1));
			q.push(ii(num*t1,cntnum+2));
			q.push(ii(num*t2,cntnum+3));
			q.push(ii(num*t3,cntnum+4));
			q.push(ii(num+k,cntnum+1));
			q.push(ii(num+t1,cntnum+2));
			q.push(ii(num+t2,cntnum+3));
			q.push(ii(num+t3,cntnum+4));
			q.push(ii(abs(num-k),cntnum+1));
			q.push(ii(abs(num-t1),cntnum+2));
			q.push(ii(abs(num-t2),cntnum+3));
			q.push(ii(abs(num-t3),cntnum+4));
			if(num%k==0)
			{
				q.push(ii(num/k,cntnum+1));
			}
			if(num%t1==0)
			{
				q.push(ii(num/t1,cntnum+2));
			}
			if(num%t2==0)
			{
				q.push(ii(num/t2,cntnum+3));
			}
			if(num%t3==0)
			{
				q.push(ii(num/t3,cntnum+4));
			}
		}
	}
}
int main()
{
	freopen("REPRESENTATION.INP","r",stdin);
	freopen("REPRESENTATION.OUT","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> k >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		int t=bfs(a[i]);
		if(t==-1)
		{
			cout << "NO" << "\n";
		}
		else
		{
			cout << t << "\n";
		}
	}
}
