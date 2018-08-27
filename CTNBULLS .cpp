//we will scan from 1 to n.if the position of i <=k,so we can change one cow from C to B => we have f[i]=f[i-1]+1 ways
//if i>=k+1,we count the sum of amount of ways which from pos i-1 and amount of ways which from pos i-k-1 => we have f[i]=f[i-1]+f[i-k-1] ways
#include <bits/stdc++.h>
using namespace std;
const int MOD=2111992;
int main()
{
	int n,k,f[200000];
	cin >> n >> k;
	f[0]=1;
	for(int i=1;i<=n;i++)
	{
		if(i<=k)
		f[i]=(f[i-1]+1)%MOD;
		else
		f[i]=(f[i-1]+f[i-k-1])%MOD;
	}
	cout << f[n];
}


