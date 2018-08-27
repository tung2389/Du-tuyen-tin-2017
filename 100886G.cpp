#include <bits/stdc++.h>
using namespace std;
long long ans=0,res=0;
long long n;
string a,b;
void solve(long long pos,long long digit,long long sum,bool zero,bool fa,bool fb)
{
	if(pos==n)
	{
		 if(ans<digit)
		 {
		 	ans=digit;
		 	res=sum;
		 }
		 return;
	}
	int low=0,high=9;
	if(fa==1) low=a[pos]-'0';
	if(fb==1) high=b[pos]-'0';
	if(zero==0 && fa==0 && fb==0)
	solve(pos+1,digit*9,sum*10+9,0,0,0);
	else
	{
		for(int i=low;i<=high;i++)
		{
			bool nfa=0,nfb=0;
			if(fa==1 && i==low) nfa=1;
			if(fb==1 && i==high) nfb=1;
			if(zero==1 && i==0)
			solve(pos+1,1LL,0,1,nfa,nfb);
			else
			{
				if(i==0) continue;
				solve(pos+1,digit*i,sum*10+i,0,nfa,nfb);
			}
		}
	}
}
int main()
{
	cin >> a >> b;
	while(a.size()<b.size()) a="0"+a;
	n=b.size();
	solve(0,1,0,1,1,1);
	if(res==0)
	{
		cout << a;
		return 0;
	}
	cout << res;
}
