#include <bits/stdc++.h>
using namespace std;
string a,b;
vector<long long> ans;
long long n;
bool check[20];
void solve(long long pos,bool fa,bool fb,long long sum)
{
	if(pos==n)
	{
		long long sum2=sum;
		while(sum!=0)
		{
			int t=sum%10;
			if(t!=0&&check[t]==0)
			{
			if(sum2%t==0)
			{
			check[3]=0;
			check[5]=0;
			check[7]=0;
			check[9]=0;
			return;
		    }
		    check[t]=1;
		    }
			sum=sum/10;
		}
		ans.push_back(sum2);
		check[3]=0;
		check[5]=0;
		check[7]=0;
		check[9]=0;
		return;
	}
	long long ans=0;
	int low=0,high=9;
	if(fa==1) low=a[pos]-'0';
	if(fb==1) high=b[pos]-'0';
	for(int i=low;i<=high;i++)
	{
		bool nfa=0,nfb=0;
		if(i==low && fa==1) nfa=1;
		if(i==high && fb==1) nfb=1;
		if(i%2!=0||i==0)
		{
		if(i!=1)
		solve(pos+1,nfa,nfb,sum*10+i);
	}
}
}
int main()
{
	long long t;
	cin >> t;
	while(t--)
	{
	long long k;
	cin >> a >> b >> k;
	while(a.size()<b.size()) a="0"+a;
	n=b.size();
	solve(0,1,1,0);
	if(ans.size()<k)
	cout << "-1" << "\n";
	else
	{
	cout << ans[k-1] << "\n";
    }
	ans.clear();
    }
} 
