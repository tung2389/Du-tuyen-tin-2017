#include <bits/stdc++.h>
using namespace std;
int cnt=0;
string s;
void make(string t)
{
    size_t found=s.find(t);
    if(found!=string::npos)
    {
        cnt++;
    }
    found=s.find(t,found+1);
    if(found!=string::npos)
    {
        cnt++;
    }
}
int main()
{
    string s1="Danil";
    string s2="Olya";
    string s3="Slava";
    string s4="Ann";
    string s5="Nikita";
    cin >> s;
    make(s1),make(s2),make(s3),make(s4),make(s5);
    if(cnt==1)
    {
        cout << "YES" << "\n";
    }
    else
    {
        cout << "NO" << "\n";
    }

}
