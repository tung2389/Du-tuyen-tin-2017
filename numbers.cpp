#include <bits/stdc++.h>

#define int     long long

using namespace std;
const int mod = 1e9+7;

int getres(string x)
{
    int f[111][10][2];
    memset(f, 0, sizeof(f));
    for (int i = '0'; i < x[0]; i++)
    {
        f[0][i - '0'][0] = 1;
    }
    f[0][x[0] - '0'][1] = 1;
    for (int i = 1; i < x.length(); i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            for (int k = j; k <= 9; k++)
            {
                f[i][k][0] = (f[i-1][j][0] + f[i][k][0]) % mod;
            }
        }
        for (int j = 0; j <= x[i-1] - '0'; j++)
        {
            for (int k = j; k <= x[i] - '0'; k++)
            {
                if (k == x[i] - '0') f[i][k][1] = (f[i-1][j][1] + f[i][k][1]) % mod;
                else f[i][k][0] = (f[i-1][j][1] + f[i][k][0]) % mod;
            }
        }
    }
    int res = 0;
    for (int i = 0; i < 10; i++)
    {
        res = (res + f[x.length() - 1][i][0] + f[x.length() - 1][i][1]) % mod;
    }
    return res;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(); cout.tie();
    freopen("numbers.inp", "r", stdin);
    freopen("numbers.out", "w", stdout);
    string l, r;
    cin >> l >> r;
    bool q = true; char k = '0';
    for (int i = 0; i < l.length() && q; i++) // ham kiem tra xem co phai day tang ko
    {
        if (k > l[i])
        {
            q = false;
        }
        else
        {
            k = l[i];
        }
    }
    if (q) cout << (mod + getres(r) - getres(l) + 1)%mod;
    else cout << (getres(r) - getres(l) + mod)%mod;
}
