#include <bits/stdc++.h>
using namespace std;
int a[230997];
int M[230997][23],C[230997][23];
int main()
{
	int n,m;
	cin >>  n >> m;
	for(int i=1;i<=n;i++)
	cin >> a[i];
	for(int i=1;i<=n;i++)
	M[i][0]=i;
	for(int j=1;(1<<j)<=n;j++)
	{
		for(int i=1;i+(1<<j)-1<=n;i++)
		{
			if(a[M[i][j-1]]>a[M[i+(1<<(j-1))][j-1]])
			M[i][j]=M[i][j-1];
			else
			M[i][j]=M[i+(1<<(j-1))][j-1];
		}
	}
	for(int i=1;i<=n;i++)
	C[i][0]=i;
	for(int j=1;(1<<j)<=n;j++)
	{
		for(int i=1;i+(1<<j)-1<=n;i++)
		{
			if(a[C[i][j-1]]<a[C[i+(1<<(j-1))][j-1]])
			C[i][j]=C[i][j-1];
			else
			C[i][j]=C[i+(1<<(j-1))][j-1];
		}
	}
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin >> u >> v;
		int k=log2l(v-u+1);
    cout<< max(a[M[u][k]],a[M[v-(1<<k)+1][k]])-min(a[C[u][k]],a[C[v-(1<<k)+1][k]]) << "\n";
}
}
  
 
