#include <bits/stdc++.h>
using namespace std;
int a[100010],b[100010];
bool check[100010];
int cnt[100010];
int main()
{
	freopen("PRIMITIVUS.INP","r",stdin);
	freopen("PRIMITIVUS.OUT","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s="";
	int n,ans=2;
	cin >> n;
	int maxx=0,pos=1;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i] >> b[i];
		cnt[a[i]]++;
		cnt[b[i]]++;
	}
	for(int i=1;i<=n;i++)
	{
		if(cnt[a[i]]+cnt[b[i]]>maxx)
		{
			maxx=cnt[a[i]]+cnt[b[i]];
			pos=i;
		}
	}
	check[pos]=1;
	s=s+to_string(a[pos])+to_string(b[pos]);
	int cnt=1;
	char c[1];
	char d[1];
	while(cnt<n)
	{
		bool ok=false;
		for(int i=1;i<=n;i++)
		{
			c[0]=s[s.size()-1];
			d[0]=s[0];
			if(check[i]==0)
			{
				if(a[i]==atoi(c))
				{
				s=s+to_string(b[i]);
				ans++;
				cnt++;
				check[i]=1;
				ok=true;
			    }
				else if(b[i]==atoi(d))
				{
				s=to_string(a[i])+s;
				ans++;
				cnt++;
				check[i]=1;
				ok=true;
			    }
			}
		}
		if(ok)
		{
			for(int i=1;i<=n;i++)
		    {
		    c[0]=s[s.size()-1];
			d[0]=s[0];
			if(check[i]==0)
			{
				if(a[i]==atoi(c))
				{
				s=s+to_string(b[i]);
				ans++;
				cnt++;
				check[i]=1;
			    }
				else if(b[i]==atoi(d))
				{
				s=to_string(a[i])+s;
				ans++;
				cnt++;
				check[i]=1;
			    }
			    else
			    {
			    	s=s+to_string(a[i])+to_string(b[i]);
			    	ans=ans+2;
			    	cnt++;
				}
			}
		}
		}
	}
	cout << ans << "\n";
}
