#include <bits/stdc++.h>
using namespace std;
//int dp[2010][2010];
string s[6];
string LCS(string a,string b)
{
  int m=a.length(),n=b.length(),i,j;
  int dp[m+1][n+1];
  for(i=0;i<=m;i++)dp[i][0]=0;
  for(i=0;i<=n;i++)dp[0][i]=0;
  for(i=1;i<=m;i++)
  {
    for(j=1;j<=n;j++)
    {
      if(a[i-1]==b[j-1])
        dp[i][j]=1+dp[i-1][j-1];
      else
        dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
    }
  }
  int len,l=dp[m][n];len=l;
  char c[l+1];
  int k=l;
  c[l]='\0';
  i=m;j=n;
  while(i>0 and j>0)
  {
    if(a[i-1]==b[j-1])
    {
      c[l-1]=a[i-1];
      l--;
      i--;
      j--;
    }
    else if(dp[i][j-1]>dp[i-1][j])
      j--;
    else
      i--;
  }
  return c;
}
int main()
{
    freopen("REPETITIONS.INP","r",stdin);
    freopen("REPETITIONS.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> s[i];
	}
	string ans=LCS(s[1],s[2]);
	for(int i=3;i<=n;i++)
	{
		ans=LCS(ans,s[i]);
	}
	cout << ans.size() << "\n";
}
