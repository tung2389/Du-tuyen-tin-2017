#include<bits/stdc++.h>
using namespace std;
#define forr(i,a,b) for(i=a ; i<=b ; ++i)
int bit[2300][2300];
int n, m , test;
void update(int p,int q, int val){
    for(int i = p; i <= m; i += i & -i)
    	for(int j = q; j <= n; j += j & -j)
        	bit[i][j] += val;
}
int sum(int p,int q) {
    int ans = 0;
    for(int i = p; i>=1; i -= i & -i)
    	for(int j = q; j>=1; j -= j & -j)
        ans += bit[i][j];
    return ans;
}
int main(){
	freopen("bonus.INP", "r", stdin);
	freopen("bonus.OUT", "w", stdout);
	cin>> m >> n >> test;
	int i , j;
	int a;
	memset(bit,0,sizeof(bit));
	forr(i,1,m)
	{
		forr(j,1,n)
		{
			cin>>a;
			update(i,j,a);
		}
	}
	int x1,y1,x2,y2;
	while(test--)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		if(x2+y2<x1+y1)
		{
			swap(x1,x2);
			swap(y1,y2);
		}
		//cout << sum(x2,y2)-sum(x1-1,y2)-sum(x2,y1-1)-sum(x1-1,y1-1) << "\n";
		cout<<sum(x2,y2)+sum(x1-1,y1-1)-sum(x1-1,y2)-sum(x2,y1-1)<<"\n";
		//cout << sum(x2,y2);
	}
}
