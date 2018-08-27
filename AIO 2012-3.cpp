#include <iostream>
#include <algorithm>
using namespace std;
//lay mot muc khoang cach lam chuan,dich chuyen o diem giua se ton it thoi gian nhat
int main()
{
	freopen("frogin.txt","r",stdin);
	freopen("frogout.txt","w",stdout);
	int n,k,a[100000],b[100000],ans=0,c;
	cin >> n >> k;
	a[0]=1;
	for(int i=1;i<n;i++)
	{
		cin >> c;
		a[i]=a[i-1]+c;
	}
	for(int i=0;i<n;i++)
	b[i]=a[i]-i*k;;
	sort(b,b+n);
	int x=b[n/2];
	for(int i=0;i<n;i++)
	b[i]=x+i*k;
	for(int i=0;i<n;i++)
	ans+=abs(a[i]-b[i]);
	cout << ans;
}
