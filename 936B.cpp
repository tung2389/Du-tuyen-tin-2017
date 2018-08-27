#include <bits/stdc++.h>
using namespace std;
vector<int> adjlist[300000];
vector<int> v;
bool visited[300000];
int par[300000];
int n,m;
int check=0,pos,count=0,cnt=0,test=0;
int vs[300000];
void dfs(int x , int count){
	vs[x]++;
	visited[x]=1;
	v.push_back(x);
	if(adjlist[x].size() == 0 && (count%2) ){
		cout << "Win" << "\n";
		for(int i=0;i<v.size();i++)
			cout << v[i] << " ";
		cout << "\n";
		exit( EXIT_SUCCESS );
	}
	for(int i=0;i<adjlist[x].size();i++){
		int v=adjlist[x][i];
		if(visited[v]){
			test=1;
		}
		if(vs[v]<2)dfs(v,count+1);
	}
	v.pop_back();
	visited[x]=0;
}
int main()
{
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		int a,b;
		cin >> a;
		if(a!=0)
		{
		for(int j=1;j<=a;j++)
		{
			cin >> b;
			adjlist[i].push_back(b);
		}
		}
	}
	memset(vs,0,sizeof(vs));
	memset(visited,0,sizeof(visited));
	cin >> pos;
	dfs(pos,0);
	if(test)
			cout << "Draw";
		else
			cout << "Lose";
}
