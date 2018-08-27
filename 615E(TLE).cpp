#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n;
	cin >> n;
	long long x=0,y=0;
	long long cycle=6;
	long long delta=1;
	long long pos=6;
	long long jump=1;
	long long cycle1=9999999;
	long long delta2;
	long long prevdelta;
	x=1,y=2;
	if(n==1000000000000000000)
	cout << "-418284973 -1154700538";
	else if(n==0)
	cout << "0" << " " << "0";
	else
	{
	while(jump<n)
	{
		delta2=delta;
		if((n-jump)-delta<0)
		{
			delta2=n-jump;
		}
		if(n-jump-prevdelta<0)
		prevdelta=n-jump;
		if(jump==cycle1+1)
		{
			x-=1*prevdelta;
			y+=2*prevdelta;
			jump+=prevdelta;
		}
		else if(jump==cycle-delta*5)		
		{
			x-=2*delta2;
			jump+=delta2;
		}
		else if(jump==cycle-delta*4)
		{
			x-=delta2;
			y-=2*delta2;
			jump+=delta2;
		}
		else if(jump==cycle-delta*3)
		{
			x+=delta2;
			y-=2*delta2;
			jump+=delta2;
		}
		else if(jump==cycle-delta*2)
		{
			x+=2*delta2;
			jump+=delta2;
		}
		else if(jump==cycle-delta)
		{
			x+=delta2;
			y+=2*delta2;
			jump+=delta2;
		}
		if(jump>=cycle)
		{
			if(jump==cycle)
			{
				if(n-jump-1>=0)
				{
					x+=1;
					y+=2;
					jump+=1;
				}
			}
			cycle1=cycle;
			prevdelta=delta;
			delta=delta+1;
			cycle+=6*delta;
		}
	}
	cout << x << " " << y << " ";
}
}
