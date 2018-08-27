#include <iostream>
using namespace std;

int main()
{
	freopen("flowin.txt","r",stdin);
	freopen("flowout.txt","w",stdout);
	int n,m,count[5],d=0;
	for(int i=0;i<4;i++)
	{
		count[i]=0;
	}
	cin >> n;
	cin >> m;
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin >> x >> y;
		if(x<=n&&y<=n) count[0]++;
		if(x>n&&y<=n)  count[1]++;
		if(x<=n&&y>n)  count[2]++;
		if(x>n&&y>n)   count[3]++;
	}
	for(int i=0;i<4;i++)
	{
		if(count[i]>=d)
		d=count[i];
	}
	for(int i=0;i<4;i++)
	{
		if(d==count[i])
	cout << i+1 << " " << d;
	}
	}
