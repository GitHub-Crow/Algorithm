#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define LOCAL



int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	int n, P, H, M;
	cin >> n >> P >> H >> M;
	set<pair<int, int>> re;
	int u, v;
	for (int i = 0; i < M; ++i) {
		cin >> u >> v;
		re.insert(make_pair(min(u, v), max(u, v)));
	}
	vector<int> h(n + 1);
	for (auto & v : re) {
		--h[v.first];
		++h[v.second - 1];
	}
	for (int k = 1; k <= n; ++k) h[k] += h[k - 1];
	for (int k = 0; k < n; ++k) cout << H + h[k] << ' ';

    return 0;
}