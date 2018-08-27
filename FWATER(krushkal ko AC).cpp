#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> ip;
vector<ip> adjlist;
int p[400];
int find(int i)
{
	if(p[i]==i) return i;
	else 
	return p[i]=find(p[i]);
}
int main()
{
	ios_base::sync_with_stdio(0);
	 cin.tie(0);
	ios::sync_with_stdio(false); cin.tie(0);
	int n,a[400],x,sum=0;
	int MIN=1000000;
	cin >> n;
	for(int i=1;i<=n;i++)
	cin >> a[i];
	for(int i=1;i<=n;i++)
	p[i]=i;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin >> x;
		    if(j!=i)
		    adjlist.push_back(ip(x,ii(i,j)));
		}
	}
	sort(adjlist.begin(),adjlist.end());
	int j=0;
	for(int i=0;i<adjlist.size()&&j<n;i++)
	{
		int c=find(adjlist[i].second.first),b=find(adjlist[i].second.second);
		if(c!=b)
		{
			p[c]=b;
			if(adjlist[i].first>a[b])
			sum+=a[b];
			else
			sum+=adjlist[i].first;
			j++;
		}
    }
    for(int i=1;i<=n;i++)
    {
    	if(MIN>a[i])
    	MIN=a[i];
    }
   cout << sum + MIN;
    }


