#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n,pos,l,r,a[10000],left=0,right=0;
	cin >> n >> pos >> l >> r;
	if(l==1&&r==n)
	cout << 0;
    else
    {
    	if(l==1)
    	cout << abs(r-pos)+1;
		else
		{
			if(r==n)
			cout << abs(pos-l)+1;
			else
			cout << min(abs(r-pos),abs(l-pos))+2+r-l;
			}
			}
			}
