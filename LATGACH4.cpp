#include <cstdio>
#include <vector>
using namespace std;
 
#define ll long long
#define matrix vector<vector<ll>>
 
const ll MOD = 111539786;
 
matrix a = {{0, 1}, {1, 1}};
matrix r = {{0, 0}, {0, 0}};
ll t, n;
 
matrix operator * (const matrix &a, const matrix &b) {
    matrix c = {{0, 0}, {0, 0}};
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                c[i][j] = (c[i][j] + (a[i][k] * b[k][j]) % MOD) % MOD;
            }
        }
    }
    return c;
}
 
matrix power(ll n) {
    if (n == 1) return a;
    matrix t = power(n / 2);
    t = t * t;
    if (n % 2 == 1) t = t * a;
    return t;
}
 
int main() {
    scanf("%lld", &t);
    for (int i = 1; i <= t; i++) {
        scanf("%lld", &n);
        if (n == 1) printf("1\n");
        else {
            r = power(n - 1);
            printf("%lld\n", (r[0][1] + r[1][1]) % MOD);
        }
    }
}
