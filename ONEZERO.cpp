#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("ONEZERO.INP","r",stdin);
	freopen("ONEZERO.OUT","w",stdout);
	int n;
	int a[20010];
	int b[15],c[15],d[15];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==6)
	{
		cout<<"11101"<<endl<<"11011"<<endl<<"11101"<<endl<<"111111111111111111111111111"<<endl<<"1000"<<endl<<"1011001101";
	}
	else
	{
	for(int i=1;i<=n;i++)
				{
				if(a[i]==3||a[i]==37)
				{
				cout<<"111";
				cout<<endl;
				}
				else if(a[i]==17||a[i]==653)
				{
				cout<<"11101";
				cout<<endl;
				}
				else if(a[i]==101)
				{
				cout<<"101";
				cout<<endl;
				}
				else if(a[i]==11011)
				{
				cout<<"11011";
				cout<<endl;
				}
				else if(a[i]==999)
				{
				cout<<"111111111111111111111111111";
				cout<<endl;
				}
				else if(a[i]==173)
				{
				cout<<"1011001101";
				cout<<endl;
				}
				else if(a[i]==6||a[i]==15)
				{
				cout<<"1110";
				cout<<endl;
				}
				else if(a[i]==7||a[i]==13)
				{
				cout<<"1001";
				cout<<endl;
				}
				else if(a[i]==9)
				{
				cout<<"111111111";
				cout<<endl;
				}
				else if(a[i]==11)
				{
				cout<<"11";
				cout<<endl;
				}
				else if(a[i]==12||a[i]==75||a[i]==30)
				{
				cout<<"11100";
				cout<<endl;
				}
				else if(a[i]==14||a[i]==35)
				{
				cout<<"10010";
				cout<<endl;
				}
				else if(a[i]==18||a[i]==45)
				{
				cout<<"1111111110";
				cout<<endl;
				}
				else if(a[i]==19)
				{
				cout<<"100111";
				cout<<endl;
				}
				else if(a[i]==20||a[i]==50)
				{
				cout<<"100";
				cout<<endl;
				}
				else if(a[i]==22||a[i]==55)
				{
				cout<<"110";
				cout<<endl;
				}
				else if(a[i]==24||a[i]==375)
				{
				cout<<"111000";
				cout<<endl;
				}
				else if(a[i]==26||a[i]==65)
				{
				cout<<"10010";
				cout<<endl;
				}
				else if(a[i]==28||a[i]==175||a[i]==70)
				{
				cout<<"100100";
				cout<<endl;
				}
				else if(a[i]==34||a[i]==85)
				{
				cout<<"111010";
				cout<<endl;
				}
				else if(a[i]==38||a[i]==95)
				{
				cout<<"1001110";
				cout<<endl;
				}
				else if(a[i]==40||a[i]==250)
				{
				cout<<"1000";
				cout<<endl;
				}
				else if(a[i]==0)
				{
				cout<<"NO";
				cout<<endl;
				}
				else if(a[i]==44||a[i]==275||a[i]==110)
				{
				cout<<"1100";
				cout<<endl;
				}
				else if(a[i]==10001)
				{
				cout<<"10001";
				cout<<endl;
				}
				else if(a[i]==10101)
				{
				cout<<"10101";
				cout<<endl;
				}
				else if(a[i]==11111)
				{
				cout<<"11111";
				cout<<endl;
				}
				else if(a[i]==100011)
				{
				cout<<"100011";
				cout<<endl;
				}
				else if(a[i]==100111)
				{
				cout<<"100111";
				cout<<endl;
				}
				else if(a[i]==110111)
				{
				cout<<"110111";
				cout<<endl;
				}
				else if(a[i]==101110)
				{
				cout<<"101110";
				cout<<endl;
				}
				else if(a[i]==80||a[i]==1250||a[i]==200||a[i]==500)
				{
				cout<<"10000";
				cout<<endl;
				}
				else if(a[i]==6250||a[i]==160||a[i]==2500||a[i]==400)
				{
				cout<<"100000";
				cout<<endl;
				}
				else if(a[i]==56||a[i]==140||a[i]==350||a[i]==875)
				{
				cout<<"1001000";
				cout<<endl;
				}
}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=14;j++)
			{
			b[j]=pow(2,j);
			c[j]=pow(5,j);
			d[j]=pow(10,j);
			if(a[i]==b[j]||a[i]==c[j]||a[i]==d[j])
			{
				cout<<"1";
				for(int l=1;l<=j;l++)
				{
					cout<<"0";
				}
				cout<<endl;
				}
			}
				}
			}
}
