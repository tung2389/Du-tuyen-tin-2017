#include <iostream>
#include <stdio.h>
using namespace std;
int n,a[10000],ans=0,BIT[10000];
int doBIT(int x)
{
	int sum=0;
	x=x+1;
	while(x>0)
	{
		sum+=BIT[x];
		x-=x&(-x);
	}
	return sum;
}
void updateBIT(int x,int val)
{
	x=x+1;
	while(x<=n)
	{
		BIT[x]+=val;
		x+=x&(-x);
	}
}
void constructBIT()
{
	for(int i=1;i<=n;i++)
	BIT[i]=0;
	for(int i=0;i<n;i++)
	updateBIT(i,a[i]);
}


int main()
{
	cin >> n;
	for(int i=0;i<n;i++)
	cin >> a[i];
    constructBIT();
    /*for(int i=1;i<=n;i++)
    {
        cout << BIT[i] << "\n";
    }*/
    cout << doBIT(4);
}
