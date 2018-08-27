#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	freopen("genin.txt","r",stdin);
	freopen("genout.txt","w",stdout);
	int n,p,sum[10000],j=1,MAX=0,c=1;
	cin >> n >> p;
	for(int i=0;i<=n;i++)
	sum[i]=0;
	while(1)
	{
		if(p-c<=0)
		{
		sum[j]=sum[j]+p;
		break;
		}
		sum[j]=sum[j]+c;
		p=p-c;
		j++;
		c++;
		if(j>n)
		{
		j=1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(MAX<sum[i])
		MAX=sum[i];
	}
	for(int i=1;i<=n;i++)
	{
    if(sum[i]==MAX)
    {
    cout << i <<" "<< sum[i];
    break;
	}
	}
	}
