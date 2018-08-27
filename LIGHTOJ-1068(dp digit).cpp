#include <bits/stdc++.h>
using namespace std;

long long dp[15][110][110][2];
int digit[20];
int k;
string sub(string a, string b)
{
    string res="";
    while(a.length() < b.length()) a="0"+a;
    while(b.length() < a.length()) b="0"+b;
    bool neg=false;
    if(a<b)
    {
        swap(a,b);
        neg=true;
    }
    int borrow=0;
    for(int i=a.length()-1; i>=0;i--)
    {
        int tmp=a[i]-b[i]-borrow;
        if(tmp<0)
        {
            tmp+=10;
            borrow=1;
        }
        else borrow=0;
        res=(char)(tmp%10 + 48) + res;
    }
    while(res.length()>1 && res[0]=='0') res.erase(0,1);
    if(neg) res="-"+res;
    return res;
}
long long solve(int pos,int sum,int sumdigit,int tight)
{
	if(pos==-1)
	{
		if(sum%k==0&&sumdigit%k==0)
		return 1;
		else
		return 0;
    }
	if(dp[pos][sum][sumdigit][tight]!=-1 && tight==0)
	return dp[pos][sum][sumdigit][tight];
	long long ans=0;
	int n;
	if(tight==1)
	{
		n=digit[pos];
	}
	else
	{
		n=9;
	}
	for(int i=0;i<=n;i++)
	{
		ans+=solve(pos-1,(sum*10+i)%k,(sumdigit+i)%k,(i==digit[pos] && tight==1)?1:0);
	}
	if(tight==0)
	dp[pos][sum][sumdigit][tight]=ans;
	return ans;
}
long long getdigit(string s)
{
	memset(digit,0,sizeof(digit));
	int cnt=0;
	for(int i=s.size()-1;i>=0;i--)
	{
		digit[cnt]=s[i]-'0';
		cnt++;
	}
	return solve(cnt-1,0,0,1);
}
int main()
{
	int t;
	string a,b;
	cin >> t;
	int cnt=0;
	while(t--)
	{
	memset(dp,-1,sizeof(dp));
	cnt++;
	cin >> a >> b >> k;
	cout << "Case " << cnt << ": ";
	if(k>90)
	{
		cout << "0" << "\n";
	}
	else
	{
	string t="1";
	a=sub(a,t);
	cout << getdigit(b)-getdigit(a) << "\n";
    }
    }
}
