#include <iostream>
using namespace std;
int sum=0,count=0;
char a[1000][1000];

void search(int i,int j)
{
if(a[i-1][j]=='#')
count++;
if(a[i+1][j]=='#')
count++;
if(a[i][j+1]=='#')
count++;
if(a[i][j-1]=='#')
count++;
sum+=4-count;
count=0;
}
int main()
{
	freopen("cartin.txt","r",stdin);
	freopen("cartout.txt","w",stdout);
	int h,w;
	cin >> h >> w;
	for(int i=0;i<w;i++)
	{
		for(int j=0;j<h;j++)
		{
			cin >> a[i][j];
		}
	}
	for(int i=0;i<w;i++)
	{
		for(int j=0;j<h;j++)
		{
			if(a[i][j]=='#')
			{
			search(i,j);
	        }
		}
	}
	cout << sum;
}


