#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define LOCAL

const int N = 605;
int f[N][N], e[N][N];
vector<PII> monode[N*N];
int n, m;
set<int> re;

int en(int u, int v) {
	return min(u, v) * n + max(u, v);
}

void gen(int u, int v, int w) {
	auto term = monode[en(u, v)];
	printf("%d, %d\n", u, v);
	if (term.empty()) re.insert(en(u, v));
	else {
		for (auto & i : term) {
			for 
		}
	}
}

int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	re.clear();
	memset(f, 0, sizeof(f));
	memset(monode, 0, sizeof(monode));
	memset(e, 0, sizeof(e));

	cin >> n >> m;
	int u, v, w;
	for (int i = 0; i < m; ++i) {
		cin >> u >> v >> w;
		e[u][v] = e[v][u] = w;
		f[u][v] = f[v][u] = w;
	}
	for (int k = 1; k <= n; ++k)
		for (int j = 1; j <= n; ++j) 
			for (int i = 1; i <= n; ++i) {
				if (f[i][k] and f[k][j]) {
					int r = f[i][k] + f[k][j];
					f[j][i] = f[i][j] = r;
					int co =  en(i, j);
					monode[co].push_back({r, k});
				}
			}
	for (int i = 1; i <= n; ++i) 
		for (int j = 1; j <= n; ++j) {
			int co = en(i, j);
			sort(monode[co].begin(), monode[co].end());
		}
	int q;
	cin >> q;
	while (q--) {
		cin >> u >> v >> w;
		if (f[u][v] <= w) gen(u, v);
	}
	cout << re.size() << endl;

    return 0;
}