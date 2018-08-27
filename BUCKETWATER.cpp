#include <bits/stdc++.h>
using namespace std;

int visited[50][50][50][50];
bool ok;
int n;
int req[4]={0};
int main()
{
	freopen("BUCKETWATER.INP","r",stdin);
	freopen("BUCKETWATER.OUT","w",stdout);
	cin >> n;
	vector<int> a;
	for(int i=0;i<n;i++)
	{
		int x;
		cin >> x;
		a.push_back(x);
	}
	int len=4-n;
	for(int i=0;i<len;i++)
	{
		a.push_back(0);
	}
	for(int i=0;i<n;i++)
	cin >> req[i];
	ok=true;
	for(int i=0;i<n;i++)
	{
		if(a[i]!=req[i])
		ok=false;
	}
	if(ok==true)
	{
		cout << "0";
		return 0;
	}
	queue<vector<int> > q;
	q.push(a);
	visited[a[0]][a[1]][a[2]][a[3]]=1;
	while(!q.empty())
	{
		vector<int> cur=q.front();
		q.pop();
		vector<int> w;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(i!=j && cur[i]+cur[j]<=a[j])
				{
					ok=true;
					w=cur;
					w[j]+=w[i];
					w[i]=0;
					for(int k=0;k<n;k++)
					{
						if(w[k]!=req[k])
						{
						ok=false;
						break;
					    }
				    }
				    if(ok==true)
				    {
				    cout << visited[cur[0]][cur[1]][cur[2]][cur[3]];
				    return 0;
				    }
				    if(visited[w[0]][w[1]][w[2]][w[3]]==0)
				    {
				    	visited[w[0]][w[1]][w[2]][w[3]]=visited[cur[0]][cur[1]][cur[2]][cur[3]]+1;
				    	q.push(w);
					}
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i!=j && cur[j]!=a[j] && cur[j]+cur[i]>a[j])
			{
				ok=true;
				w=cur;
				w[i]=cur[i]-(a[j]-cur[j]);
				w[j]=a[j];
				for(int k=0;k<n;k++)
				{
					if(w[k]!=req[k])
					{
							ok=false;
							break;
					}
				}
				if(ok==true)
				{
					cout << visited[cur[0]][cur[1]][cur[2]][cur[3]];
					return 0;
				}
				if(visited[w[0]][w[1]][w[2]][w[3]]==0)
				{
					visited[w[0]][w[1]][w[2]][w[3]]=visited[cur[0]][cur[1]][cur[2]][cur[3]]+1;
					q.push(w);
				}
				}
			}
			}
	for(int i=0;i<n;i++)
	{
		if(cur[i]>0)
		{
			ok=true;
			w=cur;
			w[i]=0;
			for(int j=0;j<n;j++)
			{
				if(w[j]!=req[j])
				{
					ok=false;
					break;
				}
			}
			if(ok==true)
			{
			cout << visited[cur[0]][cur[1]][cur[2]][cur[3]];
			return 0;
		    }
		    if(visited[w[0]][w[1]][w[2]][w[3]]==0)
		    {
		    	visited[w[0]][w[1]][w[2]][w[3]]=visited[cur[0]][cur[1]][cur[2]][cur[3]]+1;
		    	q.push(w);
			}
		}
	}
}
	cout << "NO";
}
