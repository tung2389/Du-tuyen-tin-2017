#include <bits/stdc++.h>
using namespace std;

class AliceGameEasy{
	public:
		long long findMinimumValue(long long x,long long y)
		{
			long long sum=2*(x+y);
			long long n=0;
			long long cnt=0;
			bool ok=false;
			bool check=false;
			for(long long i=sqrt(sum);i>=1;i--)
			{
				if(i*(i+1)==sum)
				{
				n=i;
				ok=true;
				break;
			    } 
			}
			long long test=x;
			for(long long i=n;i>=1;i--)
			{
				if(test>=i)
				{
					cnt++;
					test-=i;
				}
				if(test==0)
				{
					check=true;
				}
		    }
		    if(x==0&&y==0)
		    return 0;
		   if(ok==false)
		   return -1;
		   if(check==false)
		   return -1;
		   else
		   {
		   	if(x==0)
		   	return 0;
		   	else
		   	return cnt;
		   }
		   
		}
};
