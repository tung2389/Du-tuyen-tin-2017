#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
	int n,m;
	cin >> n >> m;
	if(m==1) cout << "2" << "\n";
	else if(n%2==0) cout << "2" << "\n";
	else if(n%2!=0) cout << "1" << "\n";
    }
}
