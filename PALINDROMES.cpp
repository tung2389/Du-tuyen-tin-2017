#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
string ans="";
string result1="";
string result2="";
int minPalPartion(string str)
{
    int n = str.size();  
    int C[n];
    bool P[n][n];
  
    int i, j, k, L; 
  
    
    for (i=0; i<n; i++)
    {
        P[i][i] = true;
    }
  
 
    for (L=2; L<=n; L++)
    {
     
        for (i=0; i<n-L+1; i++)
        {
            j = i+L-1; 
            if (L == 2)
                P[i][j] = (str[i] == str[j]);
            else
                P[i][j] = (str[i] == str[j]) && P[i+1][j-1];
        }
    }
 
    for (i=0; i<n; i++)
    {
        if (P[0][i] == true)
            C[i] = 0;
        else
        {
            C[i] = INT_MAX;
            for(j=0;j<i;j++)
            {
                if(P[j+1][i] == true && 1+C[j]<C[i])
                    C[i]=1+C[j];
            }
        }
    }
  
   
    return C[n-1];
}
bool check(string s)
{
    int l = 0;
    int h = s.size()-1;
 

    while (h > l)
    {
        if (s[l++] != s[h--])
        {
            return false;
        }
    }
   return true;
}

void palidrome1(string a)
{
	int count=0;
	for(int i=0;i<a.size();i++)
	{
		ans=ans+a[i];
		count++;
		if(check(ans))
		{
		if(count%2==0)
		{
		result1=result1+ans;
		result1=result1+" ";
		ans="";
		count=0;
	    }
		}
	}
}
void palidrome2(string a)
{
	int t=minPalPartion(a);
	string ans1="",ans2="";
	for(int i=0;i<a.size()-1;i++)
	{
		ans1=ans1+a[i];
		for(int j=i+1;j<a.size();j++)
		{
			ans2=ans2+a[j];
		}
		if(check(ans1)&&check(ans2))
		{
			if(t>0)
			{
			result2="";
			result2=result2+ans1;
			result2=result2+" ";
			result2=result2+ans2;
			}
			t--;
		}
		ans2="";
		}
}	

int main()
{
	freopen("PALINDROMES.INP","r",stdin);
	freopen("PALINDROMES.OUT","w",stdout);
	string a;
	cin >> a;
	result2=a;
	if(a.size()%2!=0)
	cout << "NO";
	else
	{
	palidrome1(a);
	ans="";
	palidrome2(a);
	ans="";
	if(result1==""&&result2==a)
	cout << "NO";
	else cout << result2 << "\n" << result1;
}
}


