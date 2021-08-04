#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

#define LOCAL

const int N = 1e5 + 5;
vector<int> g[N];
int n, r, avg;
int main() {
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	cin >> n >> r >> avg;
	int u, v;
	LL c = 0;
	for (int i = 0; i < n; ++i) {
		cin >> u >> v;
		g[i].clear();
		g[i].push_back(u);
		g[i].push_back(v);
		c += u;
	}
	sort(g, g + n, [](vector<int>& lhs, vector<int>& rhs) {return lhs[1] < rhs[1];});
	vector<int> p(n + 1);
	for (int k = 0; k < n; ++k) p[k + 1] = p[k] + (r - g[k][0]);
	LL tot = 1ll * n * avg;
	tot -= c;
	LL ans = 0;
	for (int k = 1; tot > 0; ++k) {
		ans += min(tot, 1ll * (r - g[k - 1][0])) * g[k - 1][1];
		tot -= r - g[k - 1][0];
	}
	cout << ans << endl;
}