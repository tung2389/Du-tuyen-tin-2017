#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n,k,s;
	cin >> n >> k >> s;
	if(k>s||k*(n-1)<s)
	{
		cout << "NO" << "\n";
		return 0;
	}
	cout << "YES" << "\n";
	long long cnt=0;
	while(k-cnt<=s-(n-1)*cnt && cnt<=k)
    {
        cnt++;
    }
    cnt=cnt-1;
    long long sum=0;
    for(long long i=1;i<=cnt;i++)
    {
        if(i%2==1)
        {
            cout << n << " ";
            sum+=(n-1);
        }
        else
        {
            cout << "1" << " ";
            sum+=(n-1);
        }
    }
    long long last;
    if(cnt%2==1)
    {
        last=n;
    }
    else
    {
        last=1;
    }
    long long tmp=s-sum;
    /*if(tmp==k-cnt)
    {
        for(long long i=1;i<=tmp;i++)
        {
            cout << "1" << " ";
        }
    }
    else
    {*/
        long long c=tmp-(k-cnt-1);
        if(last==n)
        {
            for(long long i=1;i<=k-cnt;i++)
            {
                if(i%2==1)
                {
                    cout << n-c << " ";
                }
                else
                {
                    if(n-c+1>0)
                    cout << n-c+1 << " ";
                }
            }
        }
        else
        {
            for(long long i=1;i<=k-cnt;i++)
            {
                if(i%2==1)
                {
                    cout << c+1 << " ";
                }
                else
                {
                    cout << c << " ";
                }
            }
        }
    //}
}
