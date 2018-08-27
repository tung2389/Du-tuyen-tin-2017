#include <bits/stdc++.h>
using namespace std;
int f[33][33];
int main()
{
	f[0][0] = 0;
    f[0][1] = 0;
    f[0][2] = 1;
    f[1][0] = 0;
    f[1][1] = 0;
    f[1][2] = 1;
    f[2][0] = 1;
    f[2][1] = 1;
    f[2][2] = 1;
    for(int i=3;i<32;i++)
    {
    	int t=i;
    	for(int j=0;j<=i;j++)
    	{
    		if(t-2>=0&&j+1<15&&f[t-2][j+1]==0)
    		f[t][j]=1;
    		else if(t-2>=0&&j-1>=0&&f[t-2][j-1]==0)
    		f[t][j]=1;
    		else if(t+1<15&&j-2>=0&&f[t+1][j-2]==0)
    		f[t][j]=1;
    		else if(t-1>=0&&j-2>=0&&f[t-1][j-2]==0)
    		f[t][j]=1;
    		else
    		f[t][j]=0;
    		t--;
		}
	}
	int t;
	cin >> t;
	while(t--)
	{
		int x,y;
		cin >> x >> y;
		if(f[x-1][y-1]==0)
		cout << "Second" << "\n";
		else
		cout << "First" << "\n";
	}   
}
