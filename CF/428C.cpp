#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define LOCAL

const int N = 1e5 + 5;
vector<int> g[N];

double dfs(int k, int fa) {
	int n = 0;
	double r = 0;
	for (auto & v : g[k]) {
		if (v != fa) {
			++ n;
			r += dfs(v, k);
		}
	}
	return n ? (r + n) / n : 0;
}

int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif

	int n, u, v;
	cin >> n;
	for (int i = 1; i <= n; ++i) g[i].clear();
	for (int i = 1; i < n; ++i) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	cout << fixed << setprecision(7) << dfs(1, -1) << '\n';
	

    return 0;
}