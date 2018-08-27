#include <bits/stdc++.h>
using namespace std;
int psum[100010];
int main()
{
    ios_base::sync_with_stdio(0);;
    cin.tie(0);
    cout.tie(0);
    int n,m,q;
    cin >> n >> m >> q;
    string s,t;
    cin >> s;
    cin >> t;
    for(int i=0;i<s.size();i++)
    {
        if(i+m-1<s.size())
        {
            if(s.substr(i,m) == t)
            {
                if(i>0)
                psum[i]=psum[i-1]+1;
                else
                psum[i]=1;
            }
            else
            {
                if(i>0)
                psum[i]=psum[i-1];
            }
        }
        else
        {
            if(i>0)
            psum[i]=psum[i-1];
        }
    }
    while(q--)
    {
        int l,r;
        cin >> l >> r;
        l=l-1,r=r-1;
        r=r-(m-1);
        if(r<0||r<l)
        {
            cout << "0" << "\n";
        }
        else
        {
        if(l<=0)
        {
            cout << psum[r] << "\n";
        }
        else
        {
            if(psum[r]-psum[l-1]<0)
            {
                cout << "0" << "\n";
            }
            else
            {
            cout << psum[r]-psum[l-1] << "\n";
            }
        }
    }
    }
}
