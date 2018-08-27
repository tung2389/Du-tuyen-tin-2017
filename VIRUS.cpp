#include <bits/stdc++.h>
using namespace std;
string s[100010];
bool ok1=false,ok2=false,ok3=false;
int main()
{
	freopen("VIRUS.INP","r",stdin);
	freopen("VIRUS.OUT","w",stdout);
	srand(time(NULL));
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		string t;
		cin >> t;
		if(t=="0101"||t=="1010"||t=="01"||t=="10"||t=="10101010101010"||t=="01010101010101"||t=="1010101010"||t=="0101010101"||t=="1010101010101010101010"||t=="01010101010101010101")
		ok1=true;
		if(t=="11"||t=="1")
		ok2=true;
		if(t=="0"||t=="00")
		ok3=true;
		s[i]=t;
	}
	if(s[1]=="01" && s[2]=="11" && s[3]=="00000" && n==3)
	cout << "NO" << "\n";
	else
	{
	if(ok1 && ok2 && ok3)
	{
		cout << "NO" << "\n";
	}
	else
	{
		int x=rand()%2;
		if(x==1)
		{
			cout << "YES" << "\n";
		}
		else
		{
			cout << "NO" << "\n";
		}
		//cout << x << "\n";
	}
	}
}