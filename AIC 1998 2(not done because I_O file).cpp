#include <bits/stdc++.h>
using namespace std;
long long base=311;
long long mod=1e9+9;
long long mod2=999983;
long long hash_fw[660][40];
long long hash_target_fw[90];
long long hash_fw2[660][40];
long long hash_target_fw2[90];
string t[660];
string intial[660];
void build_hash(string s,long long id)
{
	string s2=s;
	s2="*"+s2;
	for(long long i=1;i<s2.size();i++)
	{
		hash_fw[id][i]=(hash_fw[id][i-1] * base % mod + s2[i]) % mod;
		hash_fw2[id][i]=(hash_fw2[id][i-1] * base % mod2 + s2[i]) % mod2;
	}
}
void build_hash_target(string s)
{
	string s2=s;
	s2="*"+s2;
	for(long long i=1;i<s2.size();i++)
	{
		hash_target_fw[i]=(hash_target_fw[i-1] * base % mod + s2[i]) % mod;
		hash_target_fw2[i]=(hash_target_fw2[i-1] * base % mod2 + s2[i]) % mod2;
	}
}
int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	//cout.tie(0);
	//freopen("anagin.txt","r",stdin);
	//freopen("anagout.txt","w",stdout);
	long long id=1;
	while(true)
	{
		cin >> t[id];
		intial[id]=t[id];
		sort(t[id].begin(),t[id].end());
		if(t[id]=="#")
		break;
		build_hash(t[id],id);
		id++;
	}
	id--;
	string a;
	getline(cin,a);
	string s;
	//freopen("words.txt","r",stdin);
	while(getline(cin,s) && s!="#")
	{
		string res="";
		for(long long i=0;i<s.size();i++)
		{
			if(s[i]!=' ')
			{
				res+=s[i];
			}
		}
		sort(res.begin(),res.end());
		build_hash_target(res);
		bool ok=false;
		for(long long i=1;i<=id;i++)
		{
			if(hash_target_fw[(int)res.size()] == hash_fw[i][(int)t[i].size()] 
			&& hash_target_fw2[(int)res.size()] == hash_fw2[i][(int)t[i].size()])
			{
				ok=true;
				cout << intial[i] << " ";
			}
		}
		if(!ok)
		{
			cout << "No anagram found";
		}
		cout << "\n";
	}
}
