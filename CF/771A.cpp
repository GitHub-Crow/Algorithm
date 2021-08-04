#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define LOCAL

const int N = 2e5;
int f[N], e[N];
int getFa(int x) {
	if (f[x] == x) return x;
	return f[x] = getFa(f[x]);
}

void merge(int u, int v) {
	f[getFa(u)] = f[getFa(v)];
}


int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif

	int n, m;
	memset(f, 0, sizeof(f));
	memset(e, 0, sizeof(e));
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) f[i] = i;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		merge(u, v);
		++e[u];
		++e[v];
	}
	bool ans = true;
	unordered_map<int, LL> c;
	for (int k = 1; k <= n; ++k) c[getFa(k)]++;
	for (int k = 1; k <= n; ++k) {
		if (c[getFa(k)] - 1 > e[k]) ans = false;
	}
	cout << (ans ? "YES\n" : "NO\n");

    return 0;
}