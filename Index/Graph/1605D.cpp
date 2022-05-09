/*
Q: 给定一颗树，树的节点值为1~n，让你给树的节点值进行relabel，使得任意两个相邻的节点u, v都满足：u xor v <= min(u, v)
A: 二分图
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define LOCAL

const int N = 2e5 + 5;
vector<int> g[N];
vector<int> mb[20];
vector<int> nodes[2];
int ans[N];
int n;
void dfs(int c, int f, int co) {
    nodes[co].push_back(c);
    for (auto & v : g[c]) {
        if (v != f) dfs(v, c, co ^ 1);
    }
}

void init() {
    for (int i = 0; i < 20; ++i) mb[i].clear();
    int k = 0;
    for (int i = 1; i <= n; ++i) {
        if (!(i >> k & 1)) ++k;
        mb[k].push_back(i);
    }
}

int main(int argc, char * argv[]) 
{
    std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    freopen("data.in", "r", stdin);
    #endif
    int T, u, v;
    cin >> T;
    while (T--) {
        cin >> n;
        init();
        nodes[0].clear();
        nodes[1].clear();
        for (int i = 1; i <= n; ++i) {
            g[i].clear();
        }
        for (int i = 1; i < n; ++i) {
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1, 0, 0);
        for (int k = 19; k >= 0; --k) {
            int co = 0;
            if (nodes[co].size() < nodes[co ^ 1].size()) co ^= 1;
            for (auto& i : mb[k]) {
                int o = nodes[co].back();
                nodes[co].pop_back();
                ans[o] = i;
            }
        }
        for (int i = 1; i <= n; ++i) cout << ans[i] << ' ';
        cout << endl;
    }
    

    return 0;
}