#include <iostream>
using namespace std;

int main()
{
	int n,a=0,count=0;
	cin >> n;
	if(n==0)
	cout << 0;
	if(n<0)
	n=-n;
	for(int i=1;i<=100000;i++)
	{
		a=a+i;
		count++;
		if(a==n||a>n&&a%2==n%2)
		{
			cout << count;
			break;
		}
	}
	}

