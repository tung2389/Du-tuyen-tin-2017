#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{	
	freopen("hippoin.txt","r",stdin);
	freopen("hippoout.txt","w",stdout);
	int n,h,f;
	cin>>n;
	int i;
	int a[5];
	int b[5];
	int que=0;
	int m;
	for(i=1;i<=3;i++)
	{
		cin>>b[i];
	}
	for(i=2;i<=3;i++)
	{
		a[i]=b[i]-b[i-1]-1;
	}

	int c1,c2;
	c1=b[1]-1;
	c2=n-b[3];

	

				int sum=0;
				sum+=max(c1,c2);
				a[1]=min(c1,c2);
				sort(a+1,a+3+1);
				for(i=0;i<(3-1)/2;i++)
				{
					sum+=a[3-i];
				}
				cout<<sum;
			
	
}
