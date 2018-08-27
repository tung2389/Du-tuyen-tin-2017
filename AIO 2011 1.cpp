#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    freopen("alienin.txt","r",stdin);
    freopen("alienout.txt","w",stdout);
	long long n,w,a[1000000],sum=0,count=0,MAX=0,i;
	cin >> n >> w;
	for(i=0;i<n;i++)
	{
	cin >> a[i];
	}
	sort(a,a+n);
	for(i=0;i<n-1;i++)
	{
		count++;
		sum+=a[i+1]-a[i];
		if(sum>=w)
		{
			sum=sum-(a[i+2-count]-a[i+1-count]);
		    count=count-1;
		}
	    MAX=max(MAX,count);
	}
	cout << MAX+1;
}
