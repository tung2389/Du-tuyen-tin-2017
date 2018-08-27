#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	long long n;
	while(cin >> n)
	{
		long long count=0;
		for(long long i=2;i<=sqrt(2*n);i++)
		{
			if((2*n)%i==0&&(i+(2*n)/i-1)%2==0)
			count++;
		}
		cout << count << "\n";
	}
}
		
