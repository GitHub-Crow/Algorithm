#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

#define LOCAL
const int N = 1e5 + 5;
vector<PII> h;
int height[N];
vector<int> g[N];
int f[N];

int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	int n, m, u, v, ch;
	cin >> n >> m;
	h.clear();
	for (int i = 1; i <= n; ++i) {
		g[i].clear();
		cin >> ch;
		height[i] = ch;
		h.push_back({ch, i});
	}
	memset(f, 0, sizeof(f));
	for (int i = 1; i <= m; ++i) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	sort(h.begin(), h.end());

	for (auto it = h.rbegin(); it != h.rend(); ++it) {
		int k = (*it).second;
		for (auto & c : g[k]) {
			if (height[c] > height[k]) f[k] = max(f[k], f[c]);
		}
		f[k] += 1;
	}
	cout << *max_element(f + 1, f + n + 1) << endl;
    return 0;
}