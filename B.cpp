#include <bits/stdc++.h>
using namespace std;
const int N = 100007;
int n, q;
long long a[N], it[4*N];
void init(int k, int l, int r){
	if(l == r){
		it[k] = a[l];
		return;
	}
	int mid = (l+r)/2;
	init(k*2, l, mid);
	init(k*2+1, mid+1, r);
	it[k] = max(it[k*2],it[k*2+1]);
}
void update(int k, int l, int r, int u, int v){
	if(l > u || r < u) return;
	if(l == u && l == r){
		it[k] += v;
		return;
	}
	int mid = (l+r)/2;
	update(k*2, l, mid, u, v);
	update(k*2+1, mid+1, r, u, v);
	it[k] = max(it[k*2],it[k*2+1]);
}
long long get(int k, int l, int r, int U, int V){
	if(l > V || r < U || U> V) return 0LL;
	if(l >= U && r <= V) return it[k];
	int mid = (l+r)/2;
	return max(get(k*2, l, mid, U, V),get(k*2+1, mid+1, r, U, V));
}
int main(){
	ios_base::sync_with_stdio(0);
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	init(1, 1, n);
	while(q --){
		int type, x, y;
		cin >> type >> x >> y;
		if(type == 1){
			update(1, 1, n, x, y);
		}
		else cout << get(1, 1, n, x, y) << "\n";
	}
}

