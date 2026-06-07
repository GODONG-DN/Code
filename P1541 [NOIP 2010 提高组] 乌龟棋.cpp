#include <bits/stdc++.h>
using namespace std;

int n,m,A[400],B[200],dp[41][41][41][41] = {0},i1,i2,i3,i4;

// https://www.luogu.com.cn/problem/P1541

int main() {

    cin >> n >> m;
    for (int i = 0;i < n;i++) cin >> A[i];
    for (int i = 0;i < m;i++) {
        cin >> B[i];
        if (B[i] == 1) i1++;
        if (B[i] == 2) i2++;
        if (B[i] == 3) i3++;
        if (B[i] == 4) i4++;
    }
    for (int a = 0;a <= i1;a++) {
        for (int b = 0;b <= i2;b++) {
            for (int c = 0;c <= i3;c++) {
                for (int d = 0;d <= i4;d++) {
                    int pos = a + b * 2 + c * 3 + d * 4;
                    int maxx = 0;
                    if (a >= 1) maxx = max(maxx,dp[a - 1][b][c][d]);
                    if (b >= 1) maxx = max(maxx,dp[a][b - 1][c][d]);
                    if (c >= 1) maxx = max(maxx,dp[a][b][c - 1][d]);
                    if (d >= 1) maxx = max(maxx,dp[a][b][c][d - 1]);

                    dp[a][b][c][d] = maxx + A[pos];
                }
            }
        }
    }
    cout << dp[i1][i2][i3][i4] << endl;
    return 0;
}