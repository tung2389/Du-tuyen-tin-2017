#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int count=0;

void check()
{
	int dem1[10000],dem2[10000],count2=0,dem3=0,dem4=0;
	char a[100000];
	for(int i=0;i<strlen(a);i++)
	{
		int val=atoi(a[i]);
		if(val%2==0)
		{
		dem1[val]++;
		count1++;
		}
		if(val%2!=0)
		{
		dem2[val]++;
		count2++;
		}
	}
	for(int i=0;i<count1;i++)
	{
		if(dem1[a[i]]%2!=0)
		dem3++;
	}
	for(int i=0;i<count2;i++)
	{
		if(dem2[a[i]]%2==0)
		dem4++;
	}
	if(dem3==count1&&dem4==count2)
	count++;

	
}
int main()
{
	char a[10000],b[100000];
	cin >> a >> b;
	for(int i=a;i<=b;i++)
	{
		check(i);
	}
	cout << count;
}
	
