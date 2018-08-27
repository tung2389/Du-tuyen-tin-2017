#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool cmp(string a,string b) {
	return a.size() < b.size() || (a.size() == b.size() && a <= b);
}
ll calc(ll x) {
	string s = "";
	while(x <= 0) return 0; 
	while(x) {
		char c = (char)((x & 1) + '0');
		s = c + s;
		x >>= 1; 
	}
	ll res = 0;
	for (int n = 1;n <= 63;++n) {
		string s1; s1.assign(n, '1');
		if (cmp(s1, s)) res++;
		for (int m = 1;m <= 63;++m) {
			string s0; s0.assign(m, '0');
			string ss = s1;
			for (int i = 0;;i++) {
				if (!(i & 1)) ss += s0;
				else ss += s1;
				if (!cmp(ss, s)) break;
				res++;
			}
		}
	}
	return res;
}
int main() {
    freopen("bitmix.inp", "r", stdin);
    freopen("bitmix.out", "w", stdout);
	// ios_base::sync_with_stdio(false);
	ll l, r; cin >> l >> r;
	cout << calc(r) - calc(l - 1);
}
