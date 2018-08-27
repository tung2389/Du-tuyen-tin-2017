#include <bits/stdc++.h>
using namespace std;
vector<long long> adjlist[300020];
long long n;
long long a[300020];
long long res=0;
bool ok=false;
long long gcd(long long a,long long b)
{
	if(a==0)
	return b;
	if(b==0)
	return a;
	while(a!=b)
	{
		if(a>b)
		a-=b;
		else
		b-=a;
	}
	return a;
}
void dfs(long long u,long long ans,long long cnt)
{
	if(ok)
	return;
    ans=gcd(ans,a[u]);
    if(ans<=1)
    return;
    if(cnt>=n)
    {
    	if(!res)
    	res=ans;
    	ok=true;
    	return;
    }
    for(long long i=0;i<adjlist[u].size();i++)
    {
        long long v=adjlist[u][i];
        dfs(v,ans,cnt+1);
    }
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin >> n;
    for(long long i=1;i<=2*n;i++)
    {
       cin >> a[i];
    }
    for(long long i=1;i<=2*n-2;i++)
    {
        if(i%2==0)
        {
            if(gcd(a[i],a[i+1])>1)
            {
                adjlist[i].push_back(i+1);
            }
            if(gcd(a[i],a[i+2])>1)
            {
                adjlist[i].push_back(i+2);
            }
        }
        else
        {
            if(gcd(a[i],a[i+2])>1)
            {
                adjlist[i].push_back(i+2);
            }
            if(gcd(a[i],a[i+3])>1)
            {
                adjlist[i].push_back(i+3);
            }
        }
    }
    /*for(long long i=1;i<=2*n;i++)
    {
    	cout << i << "\n";
    	for(long long j=0;j<adjlist[i].size();i++)
    	{
    		cout << adjlist[i][j] << " ";
		}
		cout << "\n";
	}*/
    dfs(1,0,1);
    if(res)
    {
    	cout << res << "\n";
    	return 0;
	}
	ok=false;
	dfs(2,0,1);
	if(res)
	{
		cout << res << "\n";
		return 0;
	}
    cout << "-1";
    //cout << gcd(3,6);
}
