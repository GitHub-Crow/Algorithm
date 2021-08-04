#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define LOCAL

const int N = 2e5 + 5;
int n, m, root;

vector<int> g[N];
vector<int> deg;
vector<int> vis;

bool dfs(int k, int fa) {
	if (deg[k] != 2) return false;
	if (fa && k == root) return true;
	if (vis[k]) return false;
	vis[k] = true;
	for (auto & v : g[k]) {
		if (v != fa) return dfs(v, k);
	}
	return false;
}

int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif

	cin >> n >> m;
	int u, v;
	for (int i = 1; i <= n; ++i) g[i].clear();
	deg.resize(n + 1, 0);
	vis.resize(n + 1, false);
	for (int i = 0; i < m; ++i) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
		deg[u]++;
		deg[v]++;
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (!vis[i] && deg[i] == 2) {
			root = i;
			if (dfs(i, 0)) ++ans;
		}
	}
	cout << ans << endl;


    return 0;
} 