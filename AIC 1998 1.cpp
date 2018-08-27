#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
int w,h,x,y;
int a[10],b[10];
bool check[30010];
int ans=0;
map<pair<int,int>,int> mp;
map<pair<int,int>,int> mp2;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("mallsin.txt","r",stdin);
	freopen("mallsout.txt","w",stdout);
	cin >> w >> h >> x >> y;
	for(int i=1;i<=4;i++)
	{
		cin >> a[i] >> b[i];
		mp[ii(b[i]+1,a[i]+1)]=1;
		check[a[i]+1]=1;
	}
	int posl;
	for(int i=1;i<=w;i++)
	{
	if(!check[i])
	{
	posl=i;
	int t=0;
	while(!check[i] && i<=w)
	{
		t++;
		i++;
	}
	if(t>=x)
	{
		ans=ans+(h-y+1)*(t-x+1);
		for(int j=posl;j<=t+posl-x;j++)
		{
			mp2[ii(j,j+x-1)]=1;
		}
	}
	}
	}
		for(int i=x;i<=w;i++)
		{
			vector<int> v;
			int t=0;
			if(!mp2[ii(i-x+1,i)])
			{
				for(int k=1;k<=4;k++)
				{
					if(a[k]+1 >= i-x+1 && a[k]+1<=i)
					{
						v.push_back(b[k]+1);
					}
				}
				sort(v.begin(),v.end());
				for(int j=0;j<v.size()-1;j++)
				{
					int dist=v[j+1]-v[j]-1;
					if(dist>=y)
					{
						ans+=dist-y+1;
					}
				}
				int dist=v[0]-1;
				if(dist>=y)
				ans+=dist-y+1;
				dist=h-v[v.size()-1];
				if(dist>=y)
				ans+=dist-y+1;
			}
		}
	cout << ans << "\n";
}
