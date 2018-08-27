#include <iostream>
#include <stdio.h>
using namespace std;
int count=0;
void check(int n)
{
	while(n!=1)
	{
		if(n%2==0)
		{
		n=n/2;
		count++;
		}
		else
		{
			n=3*n+1;
			count++;
		}
		}
		}
int main()
{
	freopen("hailin.txt","r",stdin);
	freopen("hailout.txt","w",stdout);
	int n;
    while(cin >> n && n!=0)
    {
    	check(n);
    	cout << count << "\n";
    	count=0;
    }
    }	
    	
    	
