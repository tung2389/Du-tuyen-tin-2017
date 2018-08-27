#include <iostream>
#include <stack>
using namespace std;

int main()
{
    freopen("shufflein.txt","r",stdin);
    freopen("shuffleout.txt","w",stdout);
	stack<pair<int,int> > s;
	int n,k,a[1000000],b[1000000],c,d;
	cin >> n >> k;
	for(int i=0;i<=n;i++)
	{
		a[i]=0;
		b[i]=0;
	}
	for(int i=1;i<=k;i++)
	{
	int d;
	cin >> d;
	a[d]=i;
	}
	for(int i=1;i<=k+1;i++)
	{
	int d;
	cin >> d;
	b[d]=i;
	}
	for(int i=1;i<=n;i++)//quet lan 1,loai bo nhung nguoi chac chan se co ghe
	{
	if(b[i]!=0) s.push(make_pair(i,b[i]));
	if(a[i]!=0&&s.size()!=0)
	{
	if(a[i]==1) c=s.top().second;
	s.pop();
	a[i]=0;
	}
	}
	for(int i=1;i<=n;i++)//quet lan 2
	{
		if(a[i]!=0)
		{
		if(a[i]==1) c=s.top().second;
		s.pop();
		a[i]=0;
		}
	}
	d=s.top().second;//nguoi cuoi cung;
	cout << c << "\n" << d;
}
		
	 
