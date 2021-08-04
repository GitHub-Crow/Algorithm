#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<LL, int> PLI;

#define LOCAL

int n, m;
const int N = 1e5 + 5;
int a[N];
vector<int> g[N];

PLI dfs(int r, bool fie, int f) {
	LL nmas = 0, mas = 0;
	int nmiv = INT_MAX, miv = INT_MAX;
	// use node r.
	if (fie) {
		mas = a[r];
		miv = a[r];
		for (auto & v : g[r]) {
			if (v != f) {
				auto w = dfs(v, false, r);
				mas += w.first;
				miv = min(miv, w.second);
			}
		}
	}
	// not use node r.
	for (auto & v : g[r]) {
		if (v == f) continue ;
		// not use a[r]
		auto w = dfs(v, true, r);
		nmas += w.first;
		nmiv = min(nmiv, w.second);
	}
	if (mas > nmas) return {mas, miv};
	else if (mas < nmas) return {nmas, nmiv};
	else if (miv > nmiv) return {mas, miv};
	else return {nmas, nmiv};
}

int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif

	int n, m;
 	cin >> n >> m;

 	memset(a, 0, sizeof(a));
 	for (int i = 1; i <= n; ++i) g[i].clear();
 	for (int i = 1; i <= n; ++i) cin >> a[i];

 	int u, v;
 	for (int i = 0; i < m; ++i) {
 		cin >> u >> v;
 		g[u].push_back(v);
 		g[v].push_back(u);
 	}
 	auto ans = dfs(1, true, -1);
 	cout << ans.first << ' ' << ans.second << endl;

    return 0;
}