#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> father;
    DSU (int n) {
        father.resize(n+1);
        for (int i = 1;i <= n;i++) {
            father[i] = i;
        }
    }
    int find(int x) {
        if (father[x] == x) return x;
        return father[x] = find(father[x]);
    }
    void join (int x,int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            father[x] = y;
        }
    }
};

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    return 0;
}
