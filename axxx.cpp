/*input
3
1
2
3
*/
#include <bits/stdc++.h>
using namespace std;
 
const int Mod = 111539786, sz = 2;
const long long Mod2 = 1ll * Mod * Mod;
 
struct Matrix {
	int M[sz][sz];
	Matrix() {
		memset(M, 0, sizeof M);
	}
 
	Matrix operator*(Matrix &b) {
		Matrix c;
		for(int i = 0; i < sz; ++i)
			for(int j = 0; j < sz; ++j) {
				int64_t tmp = 0;
				for(int k = 0; k < sz; ++k) {
					tmp += 1ll * M[i][k] * b.M[k][j];
					tmp -= (tmp > Mod2) ? Mod2 : 0;
				}
				c.M[i][j] = tmp % Mod;
			}
		return c;
	}
} x[30];
 
struct Matrix_1xn {
	int M[sz];
	Matrix_1xn() {
		memset(M, 0, sizeof M);
	}
	Matrix_1xn operator*(Matrix &a) {
		Matrix_1xn b;
		for(int i = 0; i < sz; ++i) {
			int64_t tmp = 0;
			for(int j = 0; j < sz; ++j) {
				tmp += 1ll * M[j] * a.M[j][i];
				tmp -= (tmp > Mod2) ? Mod2 : 0;
			}
			b.M[i] = tmp % Mod;
		}
		return b;
	}
};
 
int main(){
	x[0].M[0][1] = x[0].M[1][0] = x[0].M[1][1] = 1;
	for(int i = 1; i < 30; ++i)
		x[i] = x[i - 1] * x[i - 1];
 
	int test; scanf("%d", &test);
	while(test--) {
		int n; scanf("%d", &n);
		Matrix_1xn a; a.M[0] = a.M[1] = 1;
 
		for(int i = 29; i >= 0; --i)
			if(n & (1 << i)) a = a * x[i];
		printf("%d\n", a.M[0]);
	}
} 