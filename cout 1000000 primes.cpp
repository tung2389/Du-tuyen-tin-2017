#include <bits/stdc++.h>
using namespace std;

bool isPrime[1000000],notPrime[1000000];
int main()
{
	isPrime[0]=0;
	isPrime[1]=0;
	isPrime[2]=1;
	for(int i=3;i<=1000000;i+=2)
	{
		if(notPrime[i]==0)
		{
			for(int j=i;j<=1000000;j+=i)
			{
				notPrime[j]=1;
			}
			isPrime[i]=1;
		}
	}
	for(int i=2;i<=1000000;i++)
	{
		if(isPrime[i])
		cout << i << " ";
	}
}
