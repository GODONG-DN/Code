#include <bits/stdc++.h>
using namespace std;

// https://www.luogu.com.cn/problem/P2392

const int INF = 1e9;
int n;
int s[25];
int sum = 0;
int ans;
int a[25],b[25],c[25],d[25],A,B,C,D;

/**
 * @def dfs主函数
 * @param pos 当前是第几道题
 * @param l 左脑做题分钟
 */
void dfs(int pos,int l) {
    if (pos == n) {
        ans = min(ans,max(l,sum-l));
        return ;
    }
    dfs(pos + 1,l + s[pos]); 
    dfs(pos + 1,l);
}

/** @def 此函数用于分别处理四个题组
 * @param len 题组长度
 * @param arr 题组
 * @return 返回dfs的ans
*/

int solve(int len,int arr[]) {
    n = len;
    sum = 0;
    ans = INF;
    for (int i = 0;i < n;i++) {
        s[i] = arr[i];
        sum += s[i];
    }
    dfs(0,0);
    return ans;
}

int main() {
    cin >> A >> B >> C >> D;
    for (int i = 0;i < A; i++) cin >> a[i];
    for (int i = 0;i < B; i++) cin >> b[i];
    for (int i = 0;i < C; i++) cin >> c[i];
    for (int i = 0;i < D; i++) cin >> d[i];

    int answer = 0;
    answer += solve(A,a);
    answer += solve(B,b);
    answer += solve(C,c);
    answer += solve(D,d);
    cout << answer << endl;

    return 0;
}