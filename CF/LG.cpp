#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define LOCAL
const  int N = 1e5 + 5;
vector<int> g[N];
int d[N], c[N], f[N];

void dfs(int k, int fa, int dep) {
    d[k] = dep;
    f[k] = fa;
    c[k] = 1;
    for (auto & u : g[k]) {
        if (u != fa) {
            dfs(u, k, dep + 1);
            c[k] += c[u];
        }
    }
}

int solve(int x, int dep) {
    if (d[x] >= dep) return c[x];
    int ans = 0;
    for (auto & v : g[x]) {
        if (v != f[x]) {
            ans += solve(v, dep);
        }
    }
    return ans;
}


int main(int argc, char * argv[]) 
{
    std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    freopen("data.in", "r", stdin);
    #endif
    int n, m, u, v;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) g[i].clear();
    memset(c, 0, sizeof(c));
    for (int k = 1; k < n; ++k) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, -1, 1);
    int op, x, dep;
    while (m--) {
        cin >> op >> x;
        if (op == 1) dep = x;
        else cout << solve(x, dep) << endl;
    }
    

    return 0;
}