#include <bits/stdc++.h>
using namespace std;
int a[100010];
int sum1=0;
double sum2=0;
int sum3=0;
int ans=0;
int main()
{
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		sum1+=a[i];
	}
	sum2=n*4.5;
	if(n%2==0)
	{
		sum3=int(sum2);
	}
	else
	{
		sum3=int(sum2)+1;
	}
	if(sum1>=sum3)
	{
	cout << "0" << "\n";
	return 0;
    }
    int delta=sum3-sum1;
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		delta-=(5-a[i]);
		ans++;
		if(delta<=0)
		{
			cout << ans << "\n";
			return 0;
		}
	}
}
