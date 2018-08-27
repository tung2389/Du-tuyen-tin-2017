#include <bits/stdc++.h>
using namespace std;

#define matrix vector<vector<long long> >
matrix a={{0,1},{1,1}};
matrix operator * (const matrix &a,const matrix &b)
{
    matrix c={{0,0},{0,0}};
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            for(int k=0;k<2;k++)
            {
                c[i][j]=(c[i][j]+a[i][k]*b[k][j]);
            }
        }
    }
    return c;
}
matrix power(long long n)
{
    if(n==1)
        return a;
    matrix t=power(n/2);
    t=t*t;
    if(n%2==1)
        t=t*a;
    return t;
}
int main()
{
    long long n;
    cin >> n;
    if(n==1)
    {
        cout << "1" << "\n";
    }
    else
    {
        matrix r=power(n-1);
        cout << r[0][1] + r[1][1] << "\n";
    }
}
