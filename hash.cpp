#include <bits/stdc++.h>
using namespace std;
vector<long long> v;
long long mod=1e9+7;
long long base=31;
long long fact[100010];
long long hash_fw[100010];
string d[100010];
void build_hash(string s)
{
	/*fact[0]=1;
	for(int i=1;i<s.size();i++)
	{
		fact[i]=(fact[i-1]*base)%mod;
	}*/
	hash_fw[0]=s[0];
	for(int i=1;i<s.size();i++)
	{
		hash_fw[i]=((hash_fw[i-1]*base)%mod+s[i])%mod;
	}
}
int main()
{
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> d[i];
		build_hash(d[i]);
		int len=d[i].size()-1;
		int cnt=count(v.begin(),v.end(),hash_fw[len]);
		if(cnt<=0)
		{
			cout << "OK" << "\n"; 
		}
		else
		{
			cout << d[i] << cnt << "\n";
		}
		v.push_back(hash_fw[len]);
	}
}
