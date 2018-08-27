#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,d,x,Max=0,Min=0,ans=0;
	cin >> n >> d;
	for(int i=0;i<n;i++)
	{
		cin >> x;
		if(x!=0)
		{
		Max+=x;
		Min+=x;
		if(Min>d)
		{
		 cout << "-1";
		 return 0;
		}
		Max=min(Max,d);
		}
		if(x==0)
		{
			Min=max(Min,0);
			if(Max<0)
			{
				Max=d;
				Min=0;
				ans++;
			}
		}
	}
	cout << ans;
}
