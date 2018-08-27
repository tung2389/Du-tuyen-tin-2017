#include <iostream>
using namespace std;
int p[1000],sum[1000];
int find(long long i)
{
	if(p[i]==i)
	return i;
	else
	return p[i]=find(p[i]);
}
void Union(long long x,long long y)
{
	x=find(x);
	y=find(y);
	if(x!=y)
	{
		p[y]=x;
		sum[x]++;
		sum[y]++;
        
	}
}
int main()
{

	long long n,m,a,b,count=0,i;
	cin >> n >> m >> a >> b;
	for(i=1;i<=n;i++)
	{
		sum[i]=0;
		p[i]=i;
	}
	while(m--)
	{
		long long x,y;
		cin >> x >> y;
		sum[x]++;
		sum[y]++;
		Union(x,y);
	}
for(int i=1;i<=n;i++)
	cout << sum[i] << " ";
}
		
	
