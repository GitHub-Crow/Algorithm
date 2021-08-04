#include <iostream>
#include <vector>

using namespace std;
typedef long long LL;

#define LOCAL

const int N = 2e5 + 5;
vector<int> g[N];
bool h[N];
int m, n;

int dfs(int node, int x, int fa) {
	if (h[node]) --x;
	else x = m;
	if (x < 0) return 0;
	int r = 0;
	if (node > 1 && g[node].size() < 2) return 1;
	for (auto & v : g[node]) {
		if (v != fa) r += dfs(v, x, node);
	}
	return r;
}

int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> h[i];
		g[i].clear();
	}
	int u, v;
	for (int i = 1; i < n; ++i) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	cout << dfs(1, m, -1) << endl;

    return 0;
}