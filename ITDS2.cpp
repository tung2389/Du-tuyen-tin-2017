#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,m,x[10000],y[10000],k[10000],xcol,ycol;
	cin >> n >> m;
	x[0]=0;
	y[0]=0;
	k[0]=0;
	for(int i=1;i<=n;i++)
	{
		int u,v;
		cin >> u >> k[i];
		x[i]=x[i-1]+u;
		y[i]=y[i-1]+u*k[i];
	}
	for(int i=1;i<=m;i++)
	{
	cin >> xcol >> ycol;
	int xleft,xright;
	for(int j=0;j<=n;j++)
	{
		if(x[j]>xcol)
		break;
		xleft=j;
	}
		for(int j=n;j>=0;j--)
		{
			if(x[j]<xcol)
			break;
			xright=j;
		}
		int maxleft=k[xleft];
		int maxright=k[xright];
		int ansleft,ansright;
		ansleft=0;
		ansright=x[n];
		for(int j=xleft;j>=0;j--)
		{
			if(k[j]<=maxleft)
			{
			ansleft=x[j];
		    }
			else if(k[j]>maxleft)
			break;
			maxleft=k[j];
		}
		for(int j=xright;j<=n;j++)
		{
			if(k[j]<=maxright)
			{
			ansright=x[j];
		    }
			else if(k[j]>maxright)
			break;
			maxright=k[j];
		}
		cout << ansleft << " " << ansright << "\n";
    }
}
