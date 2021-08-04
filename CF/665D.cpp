#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <unordered_map>

using namespace std;
typedef long long LL;
#define LOCAL
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
int p[N];
vector<int> g[N];
unordered_map<LL, int> cache;

int dfs(int k, int fa) {
	LL key = (LL)fa * (LL)(N) + (LL)k;
	if (cache.count(key)) return cache[key];
	int ans = 1;
	for (auto &v : g[k]) {
		if (v != fa) ans += dfs(v, k); 
	}
	return cache[key] = ans;
}

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		int u, v;
		cache.clear();
		for (int k = 0; k < n; ++k) g[k].clear();
		for (int k = 0; k < n - 1; ++k) {
			cin >> u >> v;
			g[u - 1].push_back(v - 1);
			g[v - 1].push_back(u - 1);
		}
		int m;
		cin >> m;
		for (int k = 0; k < m; ++k) cin >> p[k];
		sort(p, p + m);		
		vector<LL> w;
		for (int k = 0; k < n; ++k) {
			for (auto& v : g[k]) {
				if (v > k) {
					int x = dfs(k, v);
					w.push_back((LL)x * (LL)(n - x));
				}
			}
		}
		if (m >= n) {
			LL tmp = 1;
			for (int k = n - 2; k < m; ++k) tmp = (tmp * (LL)p[k]) % MOD;
			p[n - 2] = tmp;
		}
		sort(w.begin(), w.end());
		LL ret = 0;
		int iL = n - 2, iR = min(m - 1, n - 2);
		while (iR >= 0) ret = (ret + (LL)w[iL--] * (LL)p[iR--]) % MOD;
		while (iL >= 0) ret = (ret + w[iL--]) % MOD;
		cout << ret << endl;
	}

	

    return 0;
}