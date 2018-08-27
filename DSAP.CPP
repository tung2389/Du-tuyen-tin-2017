#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	freopen("DSAP.INP","r",stdin);
	freopen("DSAP.OUT","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a[1000010],b[1000010],n,count=1,MAX=1,sum=0;
	cin >> n;
	for(int i=0;i<n;i++)
    cin >> a[i] >> b[i];
    sum=a[0];
    for(int i=0;i<n-1;i++)
    {
    	sum=a[i];
    	count=1;
    	for(int j=i+1;j<n;j++)
    	{
    	if(sum<=b[j])
    	{
    	if(a[j]>=sum)
    	{
    	sum=a[j];
        }
    	count++;
        if(count>MAX)
        {
        MAX=count;
        }
        }
    	else
    	{
    	count=1;
    	sum=a[j];
    }
	}

}
	cout << MAX;
}
