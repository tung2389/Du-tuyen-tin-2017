#include <iostream>
using namespace std;

int main()
{
	freopen("slicein.txt","r",stdin);
	freopen("sliceout.txt","w",stdout);
	int n,a[10000],sum=1;
	bool check[10000];
	cin >> n;
    check[0]=true;
    check[n+1]=true;
	for(int i=1;i<=n;i++)
	cin >> a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[j]==i)
			{
			check[j]=true;
			if(check[j-1]==false&&check[j+1]==false)
			sum++;
			}
		}
	}
	cout << sum;
}
