#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n,k;
    cin >> n >> k;
    long long c=0;
    for(long long i=1;i<=n;i++)
    {
        long long t;
        cin >> t;
        c=__gcd(c,t);
    }
    long long sum=c;
    set<long long> st;
    for(long long i=1;i<=k;i++)
    {
        st.insert(sum%k);
        sum+=c;
    }
    set<long long> ::iterator it;
    cout << st.size() << "\n";
    for(it=st.begin();it!=st.end();it++)
    {
        cout << (*it) << " ";
    }
}
