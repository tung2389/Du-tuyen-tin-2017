#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
	int n,a[20000],b[20000],n1[20000],n2[20000],c=0,d=0,e=0,sum=0,ta=0,tb=0;
int cmp1( const int & x, const int & y ) {
	return a[x] < a[y];
}
 
int cmp2( const int & x, const int & y ) {
	return b[x] > b[y];
}
 
int main()
{
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	for(int i=0;i<n;i++)
	{
		cin >> b[i];
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]<=b[i])
		{
		n1[c]=i;
		c++;
		}
		else
		{
		n2[d]=i;
		d++;
		}
	}
	sort(n1,n1+c,cmp1);
	sort(n2,n2+d,cmp2);
	copy(n2,n2+d,n1+c);
	ta=a[n1[0]];
	tb=ta+b[n1[0]];
	for(int i=1;i<n;i++)
	{
		ta+=a[n1[i]];
		if(ta>=tb) tb=ta+b[n1[i]];
		else tb+=b[n1[i]];
	}
	cout << tb << "\n";
	for(int i=0;i<c+d;i++)
	{
		cout << n1[i]+1 << " ";
	}
     
}
