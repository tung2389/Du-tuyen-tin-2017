#include <bits/stdc++.h>
using namespace std;
string s;
int z[100010];
void precompute(string s)
{
    int l=-1,r=-1;
    z[0]=s.size();
    for(int i=1;i<s.size();i++)
    {
        if(i>r)
        {
            l=i,r=i-1;
            while(r<s.size() && s[r+1]==s[r-l+1])
                r++;
            z[i]=r-l+1;
        }
        else
        {
            if(z[i-l]<r-i+1)
            {
                z[i]=z[i-l];
            }
            else
            {
                l=i;
                while(r<s.size() && s[r+1]==s[r-l+1])
                    r++;
                z[i]=r-l+1;
            }
        }
    }
}
void findd(string pattern,string text)
{
    string t=text;
    t=pattern + "$" + t;
    precompute(t);
    for(int i=0;i<t.size();i++)
    {
        if(z[i]>=pattern.size() && i!=0)
        {
            cout << i-pattern.size() << " ";
        }
    }
}
int main()
{
    cin >> s;
    precompute(s);
    for(int i=0;i<s.size();i++)
    {
        cout << z[i] << " ";
    }
    cout << "\n";
    string text,pattern;
    cin >> text;
    cin >> pattern;
    findd(pattern,text);
}
