#include <bits/stdc++.h>
using namespace std;
int n,a[200000];
void QuickSort(int l,int r)
{
	int i=l;
	int j=r;
	int mid=a[(l+r)/2];
	while(i<=j)
	{
		while(a[i]<mid) i++;
		while(a[j]>mid) j--;
		if(i<=j)
		{
			if(i<j) cout << i << " " << j <<"\n";
			swap(a[i],a[j]);
			i++;
			j--;
		}
	}
	if(l<j) QuickSort(l,j);
	if(i<r) QuickSort(i,r);
}
int main()
{
	freopen("QUEUE.INP","r",stdin);
	freopen("QUEUE.OUT","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)
	cin >> a[i];
	QuickSort(1,n);
}
