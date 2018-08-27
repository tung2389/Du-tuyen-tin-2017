#include <bits/stdc++.h>
using namespace std;
int n,a[1010][1010];
int main()
{
	scanf("%d",&n);
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
			if(i==j)
			sum+=a[i][j];
		}
	}
	int m;
	scanf("%d",&m);
	while(m--)
	{
		int type,k;
		scanf("%d",&type);
		if(type==1||type==2)
		{
			scanf("%d",&k);
			sum=sum+1;
		}
		else if(type==3)
		printf("%d",sum%2);
	}
}
