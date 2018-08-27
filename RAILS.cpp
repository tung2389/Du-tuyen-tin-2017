#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("RAILS.INP","r",stdin);
	freopen("RAILS.OUT","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,x1[3000],y1[3000],x2[3000],y2[3000];
	cin >> n;
	for(int i=0;i<2*n;i++)
	{
		cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
	}
	int d=sqrt(pow((x1[0]-x2[0]),2)+pow((y1[0]-y2[0]),2));
	for(int i=1;i<2*n;i++)
	{
		if(sqrt(pow((x1[i]-x2[i]),2)+pow((y1[i]-y2[i]),2))!=d)
		{
			cout << "-1";
			return 0;
		}
	}
	cout << d;
}
