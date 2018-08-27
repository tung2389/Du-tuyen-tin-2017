#include<iostream>
#include<cstring>
using namespace std;
int main(){
	freopen("bachin.txt", "r", stdin);
	freopen("bachout.txt", "w", stdout);
	string s;
	cin>>s;
	string t,m;
	cin>>m;
	while(1)
	{
		cin>>t;
		if(t[0]=='#')
		break;
		m=m+ t;
	}
	bool check,kl=0;
	int lenm=m.length();
	int lens=s.length();
/*	for(int i=0 ; i<lenm ; i++)
	cout<<m[i];
	cout<<"\n"; */
	int i,j;
	for(i=0 ; i<lenm-lens+1 ; i++)
	{
		int k=s[0]-m[i];
		check=true;
		for(j=1 ; j<lens ; j++)
		{
			if((s[j]-m[j+i])!=k)
			{
				check=false;
				break;
			}
		}
		if(check==true)
		{	kl=1;
			cout<<i+1<<"\n";
		}
		else
		{
			check=true;
			int n=s[0]+m[i];
			for(j=1 ; j<lens ; j++)
			{
				if(s[j]+m[i+j]!=n)
				{
					check=false;
					break;
				}
			}
			if(check==true)
			{	kl=1;
				cout<<i+1<<" inverted\n";
			}
		}
	}
	if(kl==0)
	cout<<"No occurrences";
}
