#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int, int> P;

#define LOCAL

int n, m;
const int N = 2e5 + 5;
vector<P> g[N];
int co[N];
int cnt[2];
bool isOk;

void dfs(int k) {
    cnt[co[k]]++;
    for (auto & e : g[k]) {
        int v = e.first, w = e.second;
        if (co[v] == -1) {
            co[v] = co[k] ^ w;
            dfs(v);
        }
        else if (co[v] != co[k] ^ w) {
            isOk = false;
            break ;
        }
    }
}

int main(int argc, char * argv[]) 
{
    std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    freopen("data.in", "r", stdin);
    #endif
    int T;
    cin >> T;
    int u, v;
    string com;
    int fake = n + 1;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) g[i].clear();
        for (int i = 0; i < m; ++i) {
            cin >> u >> v >> com;
            if (com == "imposter") {
                g[u].push_back(make_pair(v, 1));
                g[v].push_back(make_pair(u, 1));
            }
            else {
                g[u].push_back(make_pair(v, 0));
                g[v].push_back(make_pair(u, 0));
            }
        }
        memset(co, -1, sizeof(co));
        isOk = true;
        int ans = 0;
        for (int k = 1; k <= n; ++k) {
            if (co[k] == -1) {
                memset(cnt, 0, sizeof(cnt));
                co[k] = 0;
                dfs(k);
                ans += max(cnt[0], cnt[1]);
            }
            if (!isOk) break ;
        }
        if (!isOk) cout << "-1\n";
        else cout << ans << endl;
    }

    return 0;
}