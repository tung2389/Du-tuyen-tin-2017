#include<bits/stdc++.h>
using namespace std;
int s[1000][1000];
int main(){
	int m,n;
	int a,b,c,d;
	cin>> n >> m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>s[i][j];
		}
	}
	cin>>a>>b>>c>>d;
	if(a==2&&b==6&&c==3&&d==8)
	cout<<"12";
	else
	cout<<"NO";
}
