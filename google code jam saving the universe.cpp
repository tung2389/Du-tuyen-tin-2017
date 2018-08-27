#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	int test=1;
	while(t--)
	{
		int d,cntc=0;
		string s;
		cin >> d;
		cin >> s;
		int shoot=1;
		int sum=0;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='C')
			{
				cntc++;
				shoot=shoot*2;
			}
			if(s[i]=='S')
			{
				sum+=shoot;
			}
		}
		if(sum<=d)
		{
			cout << "Case #" << test << ": " << "0" << "\n";
		} 
		else
		{
		if(cntc==0)
		{
			cout << "Case #" << test << ": " << "IMPOSSIBLE" << "\n";
		}
		else if(cntc==1)
		{
			int pos;
			if(s.size()-1>d)
			cout << "Case #" << test << ": " << "IMPOSSIBLE" << "\n";
			else
			{
				int cnt=0;
				while(sum>d)
				{
					sum-=1;
					cnt++;
				}
				cout << "Case #" << test << ": " << cnt << "\n";
		}
			
		}
		else if(cntc>1)
		{
			if(s.size()-cntc>d)
			cout << "Case #" << test << ": " << "IMPOSSIBLE" << "\n";
			else if(cntc==s.size())
			cout << cout << "Case #" << test << ": " << "0" << "\n";
			else
			{
				cntc=pow(2,cntc);
				int ans=0;
				int check=0;
				for(int i=s.size()-1;i>=0;i--)
				{
					if(check==1)
					break;
					if(s[i]=='C')
					{
						int k=0;
						while(s[i]!='S')
						{
							if(check==1)
							break;
						for(int loop=0;loop<s.size()-i-1;loop++)
						{
							ans++;
							sum=sum-(cntc)/2;
							if(sum<=d)
							{
							cout << "Case #" << test << ": " << ans << "\n";
							check=1;
							break;
							}
							k++;
						}
						cntc=cntc/2;
						i--;
					}
				}
}
}
}
}
test++;
}
}
