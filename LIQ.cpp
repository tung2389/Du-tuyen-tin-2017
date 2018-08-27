#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int n,LIS[20000],a[20000],ans=0;
	cin >> n;
	for(int i=1;i<=n;i++)
	cin >> a[i];
	for(int i=1;i<=n;i++)
	{
		LIS[i]=1;
		for(int j=1;j<=i;j++)
		{
			if(a[i]>a[j]) LIS[i]=max(LIS[i],LIS[j]+1);
		}
		if(LIS[i]>ans)
		ans=LIS[i];
	}
	cout << ans;
}
