#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=m;i++)
	{
	int t=rand()%2+1;
	cout << t << " ";
	if(t==2)
	{
		int l=rand()%(n-2)+1;
		int r=l+(rand()%2+1);
		cout << l << " " << r << "\n";
	}
	else if(t==1)
	{
		int l=rand()%(n-2)+1;
		int r=l+(rand()%2+1);
		cout << l << " " << r << " " << rand()%n+1 << " " << rand()%n+1 << "\n";
	}
}
}
	
