#include <bits/stdc++.h>
using namespace std;

long long dp[405][405];
int head[405];

// https://www.luogu.com.cn/problem/P1063

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> head[i];
        head[i + n] = head[i];
    }

    for (int num = 2; num <= n; num++) { // 从 2 开始，因为1个珠子没法合并
        for (int i = 0; i <= 2 * n - num; i++) { // 由不等式 i + num - 1 (起点 + 范围，同时也是 j [终点]) <= 2n - 1 (最大终点)
            int j = i + num - 1;
            for (int k = i; k < j; k++) { // 遍历切断点
                //状态转移方程：energy 是 左边合并成大珠子 + 右边合并成大珠子。最后再 + 合并这两个大珠子释放的能量
                long long energy = dp[i][k] + dp[k+1][j] + (1LL * head[i] * head[k+1] * head[j+1]);
                dp[i][j] = max(dp[i][j], energy);
            }
        }
    }
    //在区间内寻找j - n + 1的最大值
    long long max_energy = 0;
    for (int i = 0; i < n; i++) {
        max_energy = max(max_energy, dp[i][i + n - 1]);
    }

    cout << max_energy << endl;

    return 0;
}