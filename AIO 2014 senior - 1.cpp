#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{	
	freopen("hippoin.txt","r",stdin);
	freopen("hippoout.txt","w",stdout);
	int n,h,f;
	cin>>n>>h>>f;
	int i;
	int a[h+2];
	int b[h+2];
	int que=0;
	int m;
	for(i=1;i<=h;i++)
	{
		cin>>b[i];
	}
	for(i=2;i<=h;i++)
	{
		a[i]=b[i]-b[i-1]-1;
	}

	int c1,c2;
	c1=b[1]-1;
	c2=n-b[h];

		if(f>=2*h)
		{
			cout<<n-h;
		}
		else
		{
			if(f%2==0)
			{	
				int sum=0;
				a[1]=c1+c2;
				sort(a+1,a+h+1);
				for(i=0;i<f/2;i++)
				{
					sum+=a[h-i];
				}
				cout<<sum;
			}
			else
			{	int sum=0;
				sum+=max(c1,c2);
				a[1]=min(c1,c2);
				sort(a+1,a+h+1);
				for(i=0;i<(f-1)/2;i++)
				{
					sum+=a[h-i];
				}
				cout<<sum;
			}
		}
	
}
