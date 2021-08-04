#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define LOCAL

int m, n;
const int N = 1e5 + 5;
vector<int> g[N];
bool vis[N];


int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif

	cin >> n >> m;
	int u, v;
	for (int i = 1; i <= n; ++i) g[i].clear();
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < m; ++i) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	priority_queue<int, vector<int>, greater<int>> heap;
	heap.push(1);
	vector<int> r;
	while (!heap.empty()) {
		auto t = heap.top(); heap.pop();
		if (vis[t]) continue ;
		vis[t] = true;
		r.push_back(t);
		for (auto & v : g[t]) if (!vis[v]) heap.push(v);
	}
	for (auto & v : r) cout << v << ' ';
	cout << endl;
    return 0;
}