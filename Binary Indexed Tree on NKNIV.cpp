#include <iostream>
using namespace std;
int BIT[100005],a[100005],n,ans=0;
void update(int x)
{
	while(x>0)
	{
		BIT[x]+=1;
		x-=x&-x;
	}
}
int get(int x)
{
	int res=0;
	while(x<=100000)
	{
		res+=BIT[x];
		x+=x&-x;
	}
	return res;
}
int main()
{
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	cin >> a[i];
	for(int i=1;i<=n;i++)
	{
	ans+=get(a[i]+1);
	update(a[i]);
	}
	cout << ans;
}
		
		
