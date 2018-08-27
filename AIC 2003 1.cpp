#include <iostream>
using namespace std;

int main()
{
	freopen("cultin.txt","r",stdin);
	freopen("cultout.txt","w",stdout);
	int n;
	cin >> n;
	int count=0;
	while(n>0)
	{
		if(n%2==1)
		{
		cout << n << " " << count;
		break;
		}
		n=n/2;
		count++;
	}
    }
		
		
