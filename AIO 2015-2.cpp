#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

bool checkCycle;
bool visited[1000000];
int holdhand[1000000][2];
int dfs(int v,int u)
{
	visited[v]=true;
	int count=1;
	int next=holdhand[v][0];// nguoi dau tien doi tuong dang xet nam tay
	if(next!=u && next!=0 && visited[next]==false)
	count+=dfs(next,v);
	else if(next!=u && visited[next]==true)
	checkCycle=true;
	next=holdhand[v][1];// nguoi thu hai doi tuong dang xet nam ta;
	if(next!=u && next!=0 && visited[next]==false)
	count+=dfs(next,v);
	else if(next!=u && visited[next]==true)
	checkCycle=true;
	return count;
}
int main()
{
	freopen("ruckusin.txt","r",stdin);
	freopen("ruckusout.txt","w",stdout);
	vector<int> Cycle;
	vector<int> normal;
	int n,l,k,m,sum=0;
	cin >> n >> l >> k >> m;
	for(int i=1;i<=n;i++)
	visited[i]=false;
	for(int i=0;i<l;i++)
	{
		int x,y;
		cin >> x >> y;
		if(holdhand[x][0]==0)
		holdhand[x][0]=y;
		else
		holdhand[x][1]=y;
		if(holdhand[y][0]==0)
		holdhand[y][0]=x;
		else
		holdhand[y][1]=x;
	}
	for(int i=1;i<=n;i++)
	{
		checkCycle=false;
		if(visited[i]==false)
		{
			int count=dfs(i,0);
			if(checkCycle==true)
			Cycle.push_back(count);
			else
			normal.push_back(count);
		}
		}
		for(int i=0;i<normal.size();i++)
		{
			if(normal[i]>=m)
			sum++;
			normal[i]=normal[i]/m - 1;
		}
		for(int i=0;i<Cycle.size();i++)
		{
			if(Cycle[i]>=m)
			sum++;
			Cycle[i]=Cycle[i]/m - 1;
		}
		sort(Cycle.begin(),Cycle.end(),greater<int>());//cai lon nhat len truoc
		for(int i=0;i<normal.size();i++)
		{
			while(k>0 && normal[i]>0)
			{
				sum++;
				normal[i]--;
				k--;
			}
		}
		for(int i=0;i<Cycle.size();i++)
		{
			if(k<=0)
			break;
			else
			{
				k--;//de cat vong tron can it nhat hai keo
				while(k>0 && Cycle[i]>0)
				{
					sum++;
					Cycle[i]--;
					k--;
				}
				}
		}
			cout << sum;
		}
