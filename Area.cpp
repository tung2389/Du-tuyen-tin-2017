#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
pair<int,int> a[20000];
int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> a[i].x >> a[i].y;
	}
	int sum=0;
	for(int i=0;i<n-1;i++)
	{
		sum+=(a[i+1].x-a[i].x)*(a[i+1].y+a[i].y)/2;
	}
	cout << abs(sum);
}
