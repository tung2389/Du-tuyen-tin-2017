#include <iostream>
#include <stdio.h>
using namespace std;

string kt (int x) {
    if (x == 1) {return "b";}
    if (x == 2) {return "a";}

    string fib1, fib2, fib;
    int i;

    fib1 = "b";
    fib2 = "a";

    for (i = 2;i < x;i++) {
        fib = fib2 + fib1;
        fib1 = fib2;
        fib2 = fib;
    }

    return fib;
}
int main() {
    freopen("FIBONACCI.inp","r",stdin);
    freopen("FIBONACCI.out","w",stdout);
    string s;
    int n;
    int str, fib, i, j, k, dem = 0, tb = 0;
    string ans, kan;

    getline(cin, s);
    cin >> n;

    str = s.length();
    kan = kt(n);
    fib = kan.length();

    for (i = 0;i < fib - str + 1;i++) {
        for (j = i;j < i + str;j++) {
            ans[j - i] = kan[j];
        }

        for (k = 0;k < str;k++) {
            if (ans[k] == s[k]) {tb ++;}
        }

        if (tb == str) dem ++;
        tb = 0;
    }

    cout << dem;
    return 0;
}
