#include <iostream>
using namespace std;
int son[10000],dad[10000],sum[10000],n,check=0;
int main()
{

	cin >> n;
	for(int i=2;i<=n;i++)
	{
		cin >> dad[i];
		son[dad[i]]=1;
	}
	for(int i=2;i<=n;i++)
	{
		if(son[i]==0) sum[dad[i]]++;
	}
	for(int i=1;i<=n;i++)
	{
		if(son[i]!=0&&sum[i]<3) check=1;
	}
	if(check==1)
	cout << "No";
	else
	cout << "Yes";
	}
		
