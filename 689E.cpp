#include <bits/stdc++.h>
using namespace std;
long long fact[200010];
long long mod=1e9+7;
vector<pair<long long,long long> > p;
#define ii pair<long long,long long>
long long poww(long long x,long long n)
{
	if(n==0)
	return 1*1LL;
	else if(n%2==0)
	{
		return poww(x,n/2)*poww(x,n/2)%mod;
	}
	else if(n%2!=0)
	{
		return poww(x,n/2)*poww(x,n/2)%mod*x%mod;
	}
}
long long C(long long k,long long n)
{
	//if(k==0||n==0) return 1*1LL;
	if(k>n) return 0*1LL;
	return poww(fact[k],mod-2)%mod * poww(fact[n-k],mod-2)%mod * fact[n]%mod;
}
int main()
{
	long long a,b;
	cin >> a >> b;
	fact[0]=1*1LL;
	for(long long i=1;i<=200000;i++)
	{
		fact[i]=(fact[i-1]*i)%mod;
	}
	//cout << fact[3] << "\n" << poww(3,4) << "\n";
	for(int i=1;i<=a;i++)
	{
		long long l,r;
		cin >> l >> r;
		p.push_back(ii(l,1));
		p.push_back(ii(r+1,-1));
	}
	long long ans=0,sum=1;
	sort(p.begin(),p.end());
	//cout << C(3,6) << "\n";
	for(int i=1;i<p.size();i++)
	{
		long long dist=p[i].first-p[i-1].first;
		ans+=C(b,sum)*dist;
		ans=ans%mod;
		sum+=p[i].second;
	}
	cout << ans << "\n";
}
