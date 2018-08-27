#include <iostream>
#include <cstring>
#define maxn 3
 
using namespace std;
 
int m;
long long n;
 
struct matrix
{
    int val[maxn][maxn];
    matrix()
    {
        memset(val, 0, sizeof(val));
    }
 
    matrix operator * ( const matrix & x)
    {
        matrix res;
        for (int u = 0; u <= 2; u++)
            for (int v = 0; v <= 2; v++)
                for (int i = 0; i <= 2; i++)
                    res.val[u][v] = (1ll * val[u][i] * x.val[i][v] + res.val[u][v] ) % m;
        return res;
    }
};
 
matrix A;
 
 
matrix power(long long n)                                            
{
	if(n==1) return A;
    matrix t=power(n/2);
    t=t*t;
    if(n%2==1) t=t*A;
    return t;
}

 
int main()
{
	ios_base::sync_with_stdio(0);
    cin >> n >> m;
    A.val[0][1] = A.val[1][2] = A.val[2][0] = A.val[2][1] = A.val[2][2] = 1;
    A.val[0][0] = A.val[0][2] = A.val[1][0] = A.val[1][1] = 0;
    matrix B = power(n-1);
    cout << (B.val[0][0] + B.val[0][1] * 2 + B.val[0][2] * 4) % m;
    return 0;
}
