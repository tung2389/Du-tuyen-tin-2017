#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	freopen("chocin.txt","r",stdin);
	freopen("chocout.txt","w",stdout);
	int n,a,sum=0,i=0;
	cin >> n;
	if(n==0)
	cout << 0;
	else
	{
	for(i=0;i<n;i++)
	{
	cin >> a;
	sum+=a;
	}
	for(i=0;;i++)
	{
		if(i*10>=sum)
		{
		cout << i*10-sum;
		break;
		}
	}
	}	
	}
