#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;

int w[15];
bool used[15], cp[15];
int cnt, n, ans, p, tsum, sum, sz;
vector<int> sl;
vector<vector<int> > ssl;
void bt(int pos){
	if(pos == n + 1)
		return ;
	used[pos] = 1;
	tsum += w[pos];
	if(tsum == 1000){
		sl.clear();
		for(int i = 1; i <= pos; i++){
			if(used[i] == 1)
				sl.push_back(i);
			}
		ssl.push_back(sl);
	}
//	if(tsum >= 1000) return ;
	bt(pos + 1);
	used[pos] = 0;
	tsum -= w[pos];
	bt(pos + 1);
}
void bt2(int pos){
	if(pos == sz){
		sum = p * cnt;
		for(int i = 1; i <= n; i++){
			if(used[i] == 0) sum += w[i];
		}
		ans = min(sum, ans);
		return ;
	}
	bool ok = 1;
	for(int i = 0; i < ssl[pos].size(); i++)
		if(used[ssl[pos][i]] == 1) ok = 0;
	if(ok == 1){
		cnt++;
		for(int i = 0; i < ssl[pos].size(); i++)
			used[ssl[pos][i]]  = 1;
		bt2(pos + 1);
		cnt--;
		for(int i = 0; i < ssl[pos].size(); i++)
			used[ssl[pos][i]]  = 0;
	}
	bt2(pos + 1);
}
int main(){
	freopen("post.inp", "r", stdin);// 6 100 100 200 300 400 600 800
	freopen("post.out", "w", stdout);
	cin >> n >> p;
	for(int i = 1; i <= n; i++){
		cin >> w[i];
	}
	ans = 100000000;
	tsum = 0;
	bt(1);
	for(int i = 1; i <= n; i++)
		used[i] = 0;
	sz = ssl.size();
	/*for(int i = 0; i < sz; i++){
		for(int j = 0; j < ssl[i].size(); j++)
			cout << ssl[i][j] << " ";
		cout << '\n';
	}*/
	bt2(0);
	cout << ans;
}
