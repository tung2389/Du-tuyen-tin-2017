#include <bits/stdc++.h>
using namespace std;
long long a[60];
long long w,m,n=0;
bool ok=false;
long long num=0;
long long poww(long long num,long long p)
{
	long long res=1;
	while(p)
	{
		if(p%2==1)
		res=res*num;
		num=num*num;
		p=p/2;
	}
	return res;
}
void backtrack(long long pos)
{
	if(pos==n+1)
	{
		if(num==m||num==-m)
		{
		cout << "YES" << "\n";
		exit(0);
		}
		return;
	}
	long long tmp=num;
	backtrack(pos+1);
	num=tmp+a[pos];
	backtrack(pos+1);
	num=tmp-a[pos];
	backtrack(pos+1);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> w >> m;
	if(w==2||w==3)
	{
		cout << "YES" << "\n";
		return 0;
	}
	while(poww(w,n)<=m)
	{
		n++;
	}
	for(long long i=0;i<=n;i++)
	{
		a[i]=poww(w,i);
		//cout << a[i] << "\n";
	}
	backtrack(0);
	cout << "NO" << "\n";
}
