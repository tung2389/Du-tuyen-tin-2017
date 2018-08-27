#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
	
    int n,x,a[10000],count =0,sum=0;
	cin >> x >> n;
	int d=x;
	for(int i=0;i<n;i++)
	cin >> a[i];
	sort(a,a+n);
	for(int d=1;d<=x;d++)
	{
		if(a[0]*d<a[n-1])
		sum+=a[0];
		else
		{
	for(int i=0;i<n;i++)
	{
		while(a[i]<a[i+1])
		{
		if (count==x)
		break;
		a[i]=a[i]+a[i];
		sum+=a[i];
		count++;
		}
	}
	}  
	}
	cout << sum;
	}
