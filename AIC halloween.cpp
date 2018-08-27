#include <iostream>
using namespace std;

int main()
{
	freopen("hallin.txt","r",stdin);
	freopen("hallout.txt","w",stdout);
	int n,count=1,i=1;
	cin >> n;
	while(n>=0)
	{
		if(i==n)
		{
		cout << i+1;
		break;
		}
		if(i>n)
		{
		cout << i;
		break;
		}
		n=n-count;
		count++;
		i++;
	}
	}
		
