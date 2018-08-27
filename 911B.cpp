#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n,a,b,x=1;
	cin >> n >> a >> b;
	for(int i=1;i<n;i++)
	x=max(min(a/i,b/(n-i)),x);
	cout << x;
}
