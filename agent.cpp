#include<iostream>
#include<vector>
#include<map>
#include<stdio.h>
using namespace std;

typedef pair<int,int> pi;
typedef vector<int> vi;

int n, p, r;
int cost, lef;
vector<vi> a;
vector<pi> b;
vector<int> agent;

void sortf() {
	int tg;
	for(int i = 0;i < p - 1;i++)
		for(int j= i + 1;j < p;j++)
			if(b[i].second > b[j].second) {
				tg = b[i].first;
				b[i].first = b[j].first;
				b[j].first = tg;
				tg = b[i].second;
				b[i].second = b[j].second;
				b[j].second = tg;
			}
}

void dfs(int pos) {
	lef --;
	agent[pos] = true;
	for(int i = 0;i < a[pos].size();i++){
		if(!agent[a[pos][i]]){
			dfs(a[pos][i]);
		}
	}
}

int main(){
	//freopen("agent.inp","r",stdin);
	//freopen("agent.out","w",stdout);
	cin >> n;
	cin >> p;

	a.assign(n+1,vi());
	agent.assign(n+1,false);
	b.assign(p,pi());

	for(int i=0;i<p;i++){
		cin >> b[i].first >> b[i].second;
	}

	cin >> r;
	int A, B;
	for(int i=0;i<r;i++){
		cin >> A >> B;
		a[A].push_back(B);
	}

	sortf();
	int i = 0;
	lef = n;
	while(i < p || lef){
		if(not agent[b[i].first]){
			cost += b[i].second;
			dfs(b[i].first);
		}
		i ++;
	}

	if(lef != 0) {cout << "NO" << endl; return 0;}
	cout << "YES" << endl << cost << endl;

	return 0;
}
