#include <bits/stdc++.h>
using namespace std;
int priority[4];
int correct[4];
string s[4];
int cnt[30];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("chimin.txt","r",stdin);
	freopen("chimout.txt","w",stdout);
	int n;
	cin >> n;
	for(int i=1;i<=3;i++)
	{
		cin >> s[i];
	}
	for(int j=0;j<n;j++)
	{
		bool ok=true;
		char c;
		for(int i=0;i<28;i++)
		{
			cnt[i]=0;
		}
		for(int i=1;i<=3;i++)
		{
			cnt[s[i][j]-'A']++;
			//cout << s[i][j] << " " << cnt[s[i][j]-'A'] << "\n";
			if(cnt[s[i][j]-'A']>=2)
			{
				c=s[i][j];
				ok=false;
			}
		}
		if(!ok)
		{
			for(int i=1;i<=3;i++)
			{
				if(s[i][j]==c)
				{
					priority[i]++;
					//cout << i << " " << priority[i] << "\n";
				}
			}
		}
	}
	/*for(int i=1;i<=3;i++)
	{
		cout << priority[i] << "\n";
	}*/
	int pos;
	if(priority[1]==priority[2]==priority[3])
	pos=0;
	else
	{
		int minn=999999;
		for(int i=1;i<=3;i++)
		{
			if(priority[i]<minn)
			{
				minn=priority[i];
				pos=i;
			}
		}
	}
	//cout << pos << "\n";
	for(int i=0;i<n;i++)
	{
		int maxx=0;
		char c;
		if(s[1][i]==s[2][i] && s[2][i]==s[3][i] && s[1][i]==s[3][i])
		{
			//cout << s[1][i] << "\n";
			for(int j=1;j<=3;j++)
			{
				correct[j]++;
				//cout << correct[j] << " ";
			}
			//cout << "\n";
		}
		else
		{
			if(correct[1]==correct[2] && correct[2]==correct[3] && correct[1]==0)
			{
				for(int j=1;j<=3;j++)
				{
					if(s[j][i]==s[pos][i])
					correct[j]++;
				}
			}
			else if(correct[1]==correct[2] && correct[2]==correct[3])
			{
				int maxx=0,maxpos;
				for(int j=0;j<28;j++)
				{
					cnt[j]=0;
				}
				for(int j=1;j<=3;j++)
				{
					cnt[s[j][i]-'A']++;
					if(cnt[s[j][i]-'A']>maxx)
					{
						maxx=cnt[s[j][i]-'A'];
						maxpos=j;
					}
				}
				for(int j=1;j<=3;j++)
				{
					if(s[j][i]==s[maxpos][i])
					correct[j]++;
				}
			}
			else
			{
				int minn=999999;
				int minpos;
				for(int j=1;j<=3;j++)
				{
					if(correct[j]<minn)
					{
						minn=correct[j];
						minpos=j;
					}
				}
				for(int j=1;j<=3;j++)
				{
					if(s[j][i]==s[minpos][i])
					{
						correct[j]++;
						//cout << minpos << " " << correct[j] << "\n";
					}
				}
			}
		}
	}
	cout << min(correct[1],min(correct[2],correct[3]));
}
