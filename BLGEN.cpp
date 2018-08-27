#include <bits/stdc++.h>
using namespace std;
int f[2000][2000];
map<unsigned long long,int> check1;
bool check2[2200000];
int main()
{
	vector<unsigned long long> a,b;
	unsigned long long n,m,k;
	string s;
   for(int i=2;i<2154440;++i)
        if(!check2[i])
        {
            unsigned long long t=(unsigned long long)i;
            check1[t*t*t]=1;
            for(int j=2;j*i<2154440;++j)
            check2[i*j]=true;
        }
	  getline(cin,s);
    stringstream ss(s);
    while(ss>>k)
    {
        unsigned long long t=sqrt(k);
        if(k==(t*t))
            a.push_back(k);
        else if(check1.find(k)!=check1.end())
        a.push_back(k);
    }
    getline(cin,s);
    stringstream sss(s);
    while(sss>>k)
    {
        unsigned long long t=sqrt(k);
        if(k==t*t)
            b.push_back(k);
        else if(check1.find(k)!=check1.end())
            b.push_back(k);
 
    }
	for(int i=0;i<a.size();i++)
	f[i][0]=0;
	for(int i=0;i<b.size();i++)
	f[0][i]=0;
	for(int i=1;i<=a.size();i++)
	{
		for(int j=1;j<=b.size();j++)
		{
			if(a[i-1]==b[j-1])
			f[i][j]=f[i-1][j-1]+1;
			else
			f[i][j]=max(f[i-1][j],f[i][j-1]);
		}
	}
	cout << f[a.size()][b.size()];
}
