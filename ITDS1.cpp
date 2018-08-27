#include <bits/stdc++.h>
using namespace std;
const int N = 100007;
int ans=1e9+7;
int n, q;
long long a[N]; 
multiset<int> itt[4*N];
void init(int k, int l, int r)
{
	if(l == r)
	{
		itt[k].insert(a[l]);
		return;
	}
	int mid = (l+r)/2;
	init(k*2, l, mid);
	init(k*2+1, mid+1, r);
	int i;
	for(i=l;i<=r;++i)
	itt[k].insert(a[i]);
}
void update(int k, int l, int r, int pos, int val)
{
	if(l > pos || r < pos) return;
	if(l == pos && l == r)
	{
		itt[k].erase(itt[k].lower_bound(a[pos]));
		itt[k].insert(val);
		return;
	}
	int mid = (l+r)/2;
	update(k*2, l, mid, pos, val);
	update(k*2+1, mid+1, r, pos, val);
	itt[k].erase(itt[k].lower_bound(a[pos]));
	itt[k].insert(val);
}
long long get(int k, int l, int r, int L, int R,int val)
{
	if(l > R || r < L || L > R) return 1e9+7;
	if(l >= L && r <= R)
	{
		multiset<int>::iterator It=itt[k].lower_bound(val);
		if(It!=itt[k].end()){
			return min(ans,*It);
		}
		else{
			return ans;
		}
	}
	int mid = (l+r)/2;
	return min(get(k*2, l, mid, L, R,val),get(k*2+1, mid+1, r, L, R,val));
}
int main(){
	ios_base::sync_with_stdio(0);
	cin >> n >> q;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	int type, l, r, k ,i , v;
	init(1, 1, n);
	while(q --)
	{
		cin >> type;
		if(type == 1)
		{
			cin >> i >> v;
			update(1, 1, n, i, v);
			a[i]=v;
		}
		else
		{
			cin >> l >> r >> k;
			if( get(1, 1, n, l, r ,k) ==1e9+7 )
			{
				cout<<"-1\n";
			}
			else cout<<get(1, 1, n, l, r ,k)<<"\n";
		}
	}
}
