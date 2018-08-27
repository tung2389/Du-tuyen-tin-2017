#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;
# define MOD 20122007
long long mod(long long n)
{
	if(n<=15)
	return (long long)(pow(3,n));
	else if(n%2==0)
	return (long long)(pow(mod(n/2),2))%MOD;
	else return (long long)(3*mod(n-1))%MOD;
}
int main()
{
	long long n;
	long long sum=1;
	cin >> n;
	for(long long i=1;i<=sqrt(n);i++)
	{
		if(i*i==n)
		{
		sum=sum*(mod(i)-1);
		sum=sum%MOD;
	    }
		else if(n%i==0)
		{
			sum=sum*(mod(i)-1);
			sum=sum%MOD;
			sum=sum*(mod(n/i)-1);
			sum=sum%MOD;
		}
	}
    cout << sum;
}
