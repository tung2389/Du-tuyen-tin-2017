#include <bits/stdc++.h>
using namespace std;
long long a[150010],b[150010];
long long n;
set<long long> st;
void primefactor(int x)
{
	if(!(x&1))
	st.insert(2);
	while(!(x&1))
	x=x/2;
	for(int i=3;i<=sqrt(x);i+=2)
	{
		while(x%i==0)
		{
			st.insert(i);
			x=x/i;
		}
	}
	if(x>2)
	{
		st.insert(x);
	}
}
bool checkprime(long long x)
{
	if(x==2)
	return true;
	for(long long i=2;i<=sqrt(x);i++)
	{
		if(x%i==0)
		return false;
	}
	return true;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(long long i=1;i<=n;i++)
	{
		cin >> a[i] >> b[i];
	}
	if(checkprime(a[1]))
	st.insert(a[1]);
	if(checkprime(b[1]))
	st.insert(b[1]);
	primefactor(a[1]);
	primefactor(b[1]);
	/*for(set<long long>::iterator it=st.begin();it!=st.end();it++)
	{
		cout << *it << "\n";
	}*/
	for(set<long long>::iterator it = st.begin();it!=st.end();it++)
	{
	long long val=*it;
	bool ok=true;
	for(long long i=2;i<=n;i++)
	{
		if(a[i]%val!=0 && b[i]%val!=0)
		{
			ok=false;
			break;
		}
	}
	if(ok)
	{
		cout << val << "\n";
		return 0;
	}
	}
	cout << "-1" << "\n";
}
