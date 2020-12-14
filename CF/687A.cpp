#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define LOCAL

int n, m;
const int N = 1e5 + 5;
vector<int> g[N];
int co[N];

int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	memset(co, -1, sizeof(co));
	cin >> n >> m;
	int u, v;
	for (int i = 1; i <= n; ++i) g[i].clear();
	for (int i = 0; i < m; ++i) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	queue<int> q;
	bool f = true;
	for (int k = 1; k <= n; ++k) {
		if (co[k] != -1 || g[k].empty()) continue ;
		q.push(k);
		co[k] = 0;
		while (!q.empty() && f) {
			auto t = q.front(); q.pop();
			int pc = co[t];
			for (auto & u : g[t]) {
				if (co[u] == pc) {
					f = false;
					break ;
				}
				else {
					if (co[u] == -1) q.push(u);
					co[u] = 1 - pc;
				}
			}
		}
		if (!f) break ;
	}
	if (!f) cout << "-1\n";
	else {
		vector<int> zero, one;
		for (int k = 1; k <= n; ++k) {
			if (co[k] == 1) one.push_back(k);
			else if (co[k] == 0) zero.push_back(k);
		}
		cout << zero.size() << endl;
		for (auto & v : zero) cout << v << ' ';
		cout << endl;
		cout << one.size() << endl;
		for (auto & v : one) cout << v << ' ';
		cout << endl;
	}


    return 0;
}