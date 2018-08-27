#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	
	freopen("antsin.txt","r",stdin);
	freopen("antsout.txt","w",stdout);
	int n,a[10000000],count1=0,count2=0;
	cin >> n;
	for(int i=0;i<n;i++)
	cin >> a[i];
	for(int i=0;i<n-1;i++)
	{
		if(a[i]<a[i+1])
		{
		 count1++;
		 if(count1==1)
		 {
		 	count2++;
		}
		}
		else
		{
		count1=0;
		}
		}
		cout << count2;
		}
		
