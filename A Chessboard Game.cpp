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
    	for(int j=0;j<=i;j++)
    	{
    		if(i-2>=0&&j+1<15&&f[i-2][j+1]==0)
    		f[i][j]=1;
    		else if(i-2>=0&&j-1>=0&&f[i-2][j-1]==0)
    		f[i][j]=1;
    		else if(i+1<15&&j-2>=0&&f[i+1][j-2]==0)
    		f[i][j]=1;
    		else if(i-1>=0&&j-2>=0&&f[i-1][j-2]==0)
    		f[i][j]=1;
    		else
    		f[i][j]=0;
		}
	}
	int t;
	cin >> t;
	while(t--)
	{
		int x,y;
		cin >> x >> y;
		cout << f[x-1][y-1] << "\n";
	}   
}
