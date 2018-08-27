#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("EQUA.INP","r",stdin);
	freopen("EQUA.OUT","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long T;
	cin>>T;
	while(T--)
	{
	long long a,b;
	long long x;
	long long count=0;
	cin>>a>>b;
	for(long long y=a*b+1;y<=2*a*b;y++)
	{
		if((a*b*y)%(y-a*b)==0)
		count++;
	}
	cout<<2*count-1 << "\n";
	}
}
