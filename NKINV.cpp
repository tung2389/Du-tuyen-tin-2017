#include <stdio.h>
#include <iostream>
using namespace std;
int n,a[100005],BIT[100005];
void update(int x)
{
	while(x<=100000)
	{
		BIT[x]+=1;
		x+=x&(-x);
	}
}
int doBIT(int x)
{
	int sum=0;
	while(x>0)
	{
		sum+=BIT[x];
		x-=x&(-x);
	}
	return sum;
}
int main()
{
	int ans=0;
	cin >> n;
	for(int i=1;i<=n;i++)
	cin >> a[i];
	for(int i=n;i>0;i--)
	{
		ans+=doBIT(a[i]-1);
		update(a[i]);
	}
	cout << ans;
}
		
