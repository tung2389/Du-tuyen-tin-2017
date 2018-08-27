#include <bits/stdc++.h>
using namespace std;
#define ii pair<long long,long long>
vector<pair<long long,ii> > v;
bool isPrime[20000],notPrime[20000];
int main()
{
	freopen("THREEPRIME.INP","r",stdin);
	freopen("THREEPRIME.OUT","w",stdout);
	//ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	isPrime[0]=0;
	isPrime[1]=0;
	isPrime[2]=1;
	for(int i=3;i<=7000;i+=2)
	{
		if(notPrime[i]==0)
		{
			for(int j=i;j<=7000;j+=i)
			{
				notPrime[j]=1;
			}
			isPrime[i]=1;
		}
	}
	for(long long i=1;i<=7000;i++)
	{
		for(long long j=i;j<=7000;j++)
		{
				if((4*i*i-1)%j==0 && isPrime[i] && isPrime[j]&&j>i)
				v.push_back(make_pair(i,make_pair(i,j)));
		}
		}
	long long k;
	cin >> k;
	cout << v[k-1].first << " " << v[k-1].second.first << " " << v[k-1].second.second;
}
