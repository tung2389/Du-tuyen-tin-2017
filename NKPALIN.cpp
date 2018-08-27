#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
#define N 5000+5
int dp[N][N];
string LCS(string a,string b)
{
	for(int i=0;i<a.size();i++)
	{
		for(int j=0;j<b.size();j++)
		{
			if(a[i]==b[j]) dp[i+1][j+1]=dp[i][j]+1;
			else if(a[i]!=b[j]) dp[i+1][j+1]=max(dp[i][j],max(dp[i][j+1],dp[i+1][j]));
		}
	}
	string ans;
	int n=a.size(),m=b.size();
	dp[0][0]=0;
	while(dp[n][m]>0)
	{
    if(a[n-1]==b[m-1]) ans+=a[n-1],n--,m--;
    else if(dp[n][m]==dp[n-1][m]) n--;
    else m--;
}
return ans;
}
int main()
{
	string a;
	cin >> a;
	string b=a;
	reverse(b.begin(),b.end());
	cout << LCS(a,b);
}
