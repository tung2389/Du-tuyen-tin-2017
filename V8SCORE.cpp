#include <bits/stdc++.h>
using namespace std;

int s,k,n,a[100][100],b[1000],sum=0,check=0;
 void backtrack(int i)
{
	if(check==1)
	return;
	for(int j=1;j<=n;j++)
	{
		if(a[j][i]>=b[i-1]&&(s-sum)/(k-i+1)>=a[j][i])
		{
			b[i]=a[j][i];
			sum=sum+b[i];
			if(i==k&&sum==s)
			{
				check=1;
				cout << "YES" << "\n";
				for(int t=1;t<=k;t++)
				cout << b[t] << " ";
				return;
			}
			else
			backtrack(i+1);
			sum=sum-b[i];
		}
	}
}
int main()
{
	cin >> s >> k >> n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k;j++)
		{
			cin >> a[i][j];
		}
	}
	memset(b,0,sizeof(b));
	backtrack(1);
	if(check==0)
	cout << "NO";
}
	
			
