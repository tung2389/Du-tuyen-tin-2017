#include <bits/stdc++.h>
using namespace std;

int main()
{
    char maxx='a';
    string s;
    cin >> s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>maxx)
            maxx=s[i];
    }
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==maxx)
            cout << maxx;
    }
}
