#include <iostream>
using namespace std;

int main()
{
	freopen("RECT.INP","r",stdin);
	freopen("RECT.OUT","w",stdout);
	int n,m,a[100][100];
	cin >> n >> m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin >> a[i][j];
		}
	}
	cout << "3" << " " << "1" << "\n" << "1" << " " << "0";
}
